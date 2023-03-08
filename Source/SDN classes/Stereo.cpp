#include "Stereo.h"

void Stereo::init()
{
	NodeRotation::init();
}

void Stereo::process(std::vector<WaveGuide*>& inWaveguides, Point3d position, AudioBuffer<float>& currentSample, 
	AudioBuffer<float>& sourceBuffer, int sampleIndex, int maxIndex, bool hasChanged)
{

	float panValue, azimuth;
	currentRotation = prevRotation.slerp((float)sampleIndex / maxIndex, targetRotation).normalized().toRotationMatrix();

	for (WaveGuide* guide : inWaveguides)
	{
		microphoneToNodeVector = MathUtils::dirVector(guide->getStart()->getPosition(), position);
		microphoneToNodeVector = currentRotation * microphoneToNodeVector;
		azimuth = atan2f(microphoneToNodeVector.x(), microphoneToNodeVector.z());
		panValue = sin(azimuth);

		monoToStereoDummy.at(0) = guide->getCurrentSample();
		monoToStereoDummy.at(1) = 0.0f;

		panMonoToStereo(panValue);

		for (int ch = 0; ch < Parameters::STEREO_CHANNELS; ch++)
		{
			float sampleToAdd = monoToStereoDummy[ch];
			currentSample.addSample(ch, 0, sampleToAdd);
		}
	}

	for (int ch = 0; ch < Parameters::STEREO_CHANNELS; ch++)
	{
		sourceBuffer.copyFrom(ch, sampleIndex, currentSample, ch, 0, 1);
	}

}

void Stereo::panMonoToStereo(float panAmount)
{
	float pan = (panAmount / 2) + 0.5;

	monoToStereoDummy[1] = monoToStereoDummy[0] * sqrtf(pan); //right
	monoToStereoDummy[0] *= sqrtf(1 - pan); //left
}
