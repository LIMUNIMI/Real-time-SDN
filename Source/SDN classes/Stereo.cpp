#include "Stereo.h"

void Stereo::init(double sampleRate)
{
	NodeRotation::init(sampleRate);
}

void Stereo::process(std::vector<WaveGuide*>& inWaveguides, Point3d position, AudioBuffer<float>& sourceBuffer, 
	int sampleIndex, int maxIndex, bool hasChanged)
{
	sourceBuffer.clear(sampleIndex,1);

	float azimuth;

	interpolateQuaternions();

	for (int i = 0; i < Parameters::NUM_WAVEGUIDES_TO_OUTPUT; i++)
	{
		if (hasChanged || isRotating())
		{
			microphoneToNodeVector = MathUtils::dirVector(inWaveguides[i]->getStart()->getPosition(), position);
			microphoneToNodeVector = currentRotation * microphoneToNodeVector;
			azimuth = atan2f(microphoneToNodeVector.x(), microphoneToNodeVector.z());
			panValues[i] = sin(azimuth);
		}

		monoToStereoDummy.at(0) = inWaveguides[i]->getCurrentSample();
		monoToStereoDummy.at(1) = 0.0f;

		panMonoToStereo(panValues[i]);

		for (int ch = 0; ch < Parameters::STEREO_CHANNELS; ch++)
		{
			float sampleToAdd = monoToStereoDummy[ch];
			sourceBuffer.addSample(ch, sampleIndex, sampleToAdd);
		}
	}

}

void Stereo::panMonoToStereo(float panAmount)
{
	float pan = (panAmount / 2) + 0.5;

	monoToStereoDummy[1] = monoToStereoDummy[0] * sqrtf(pan); //right
	monoToStereoDummy[0] *= sqrtf(1 - pan); //left
}
