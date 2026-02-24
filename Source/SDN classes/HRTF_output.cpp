#include "HRTF_output.h"
using namespace juce;
using namespace SDN;

#ifdef _BRT_LIBRARY_

HRTF_output::HRTF_output()
{
	envSources = std::vector<std::shared_ptr<BRTSourceModel::CSourceOmnidirectionalModel>>(Parameters::NUM_WAVEGUIDES_TO_OUTPUT);
	envSourceBuffers = std::vector<CMonoBuffer<float>>(Parameters::NUM_WAVEGUIDES_TO_OUTPUT);

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

void HRTF_output::process(std::vector<WaveGuide*>& inWaveguides, Point3d position, Eigen::Quaternionf currentRotation,
	AudioBuffer<float>& sourceBuffer, int sampleIndex, int maxIndex, bool hasChanged, bool isRotating)
{
	if (!isInit)
		initBRTEnv();

	int j = 0;

	for (WaveGuide* guide : inWaveguides)
	{
		envSourceBuffers[j][sampleIndex] = guide->getCurrentSample();
		j++;
	}

	if (hasChanged || isRotating)
		newPos = true;

	if (sampleIndex == maxIndex)
	{
		if (newPos)
		{
			//convert axis reference to y-right, z-up
			tempTransform.SetPosition(Common::CVector3(position.z, -position.x, position.y));
			tempTransform.SetOrientation(Common::CQuaternion(currentRotation.w(), currentRotation.z(),
				currentRotation.x(), -currentRotation.y()));
			envListener->SetListenerTransform(tempTransform);

			tempTransform.SetOrientation(Common::CQuaternion());
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

void SDN::HRTF_output::initBRTEnv()
{
	envManager.BeginSetup();
	envListener = envManager.CreateListener<BRTBase::CListener>("listener");
	envHRTFProcessor = envManager.CreateListenerModel<BRTListenerModel::CListenerDirectHRTFConvolutionModel>("HRTFProcessor");
	if (!envListener->ConnectListenerModel(envHRTFProcessor))
	{
		DBG("ConnectListenerModel fail");
	}
	for (int i = 0; i < Parameters::NUM_WALLS; i++)
	{
		envSources[i] = envManager.CreateSoundSource<BRTSourceModel::CSourceOmnidirectionalModel>(("wall" + String(i)).toStdString());
		if (!envHRTFProcessor->ConnectSoundSource(envSources[i]))
		{
			DBG("ConnectWall fail");
		}
	}
	envSources[Parameters::NUM_WALLS] = envManager.CreateSoundSource<BRTSourceModel::CSourceOmnidirectionalModel>("LOS");
	if (!envHRTFProcessor->ConnectSoundSource(envSources[Parameters::NUM_WALLS]))
	{
		DBG("ConnectDirect fail");
	}
	envManager.EndSetup();

	envHRTFProcessor->DisableDistanceAttenuation();

	isInit = true;
}

#endif