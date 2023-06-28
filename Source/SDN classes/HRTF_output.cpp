#include "HRTF_output.h"

HRTF_output::HRTF_output()
{
	envSources = std::vector<std::shared_ptr<BRTSourceModel::CSourceSimpleModel>>(Parameters::NUM_WAVEGUIDES_TO_OUTPUT);
	envSourceBuffers = std::vector<CMonoBuffer<float>>(Parameters::NUM_WAVEGUIDES_TO_OUTPUT);

	envManager.BeginSetup();
	envListener = envManager.CreateListener<BRTListenerModel::CListenerHRTFbasedModel>("listener");
	for (int i = 0; i < Parameters::NUM_WALLS; i++)
	{
		envSources[i] = envManager.CreateSoundSource<BRTSourceModel::CSourceSimpleModel>(("wall" + String(i)).toStdString());
		envListener->ConnectSoundSource(envSources[i]);
	}
	envSources[Parameters::NUM_WALLS] = envManager.CreateSoundSource<BRTSourceModel::CSourceSimpleModel>("LOS");
	envListener->ConnectSoundSource(envSources[Parameters::NUM_WALLS]);
	envManager.EndSetup();

	hrtf_loaded = std::make_shared<BRTServices::CHRTF>();
}

void HRTF_output::init(double samplerate, int buffersize)
{
	globalParameters.SetSampleRate(samplerate);
	globalParameters.SetBufferSize(buffersize);

	for (int i = 0; i < Parameters::NUM_WAVEGUIDES_TO_OUTPUT; i++)
	{
		envSourceBuffers[i] = CMonoBuffer<float>(buffersize);
	}
	bufferProcessed.left = CMonoBuffer<float>(buffersize);
	bufferProcessed.right = CMonoBuffer<float>(buffersize);

}

void HRTF_output::process(std::vector<WaveGuide*>& inWaveguides, Point3d position, AudioBuffer<float>& sourceBuffer, int sampleIndex, int maxIndex, bool hasChanged)
{

	int j = 0;

	for (WaveGuide* guide : inWaveguides)
	{
		envSourceBuffers[j][sampleIndex] = guide->getCurrentSample();
		j++;
	}

	if (hasChanged)
		newPos = true;

	if (sampleIndex == maxIndex)
	{
		if (newPos)
		{
			//convert axis reference to y-right, z-up
			tempTransform.SetPosition(Common::CVector3(position.z, -position.x, position.y));
			envListener->SetListenerTransform(tempTransform);

			int i = 0;
			for (WaveGuide* guide : inWaveguides)
			{
				tempTransform.SetPosition(Common::CVector3(guide->getStart()->getPosition().z,
					-guide->getStart()->getPosition().x,
					guide->getStart()->getPosition().y));
				envSources[i]->SetSourceTransform(tempTransform);

				envSources[i]->SetBuffer(envSourceBuffers[i]);
				i++;
			}

			newPos = false;
		}
		else
		{
			for (int i = 0; i < Parameters::NUM_WAVEGUIDES_TO_OUTPUT; i++)
			{
				envSources[i]->SetBuffer(envSourceBuffers[i]);
			}
		}

		envManager.ProcessAll();
		envListener->GetBuffers(bufferProcessed.left, bufferProcessed.right);

		sourceBuffer.copyFrom(0, 0, bufferProcessed.left.data(), maxIndex + 1); //left
		sourceBuffer.copyFrom(1, 0, bufferProcessed.right.data(), maxIndex + 1); //right
	}
}