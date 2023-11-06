#include "Stereo.h"

void Stereo::init(double sampleRate)
{
}

void Stereo::process(std::vector<WaveGuide*>& inWaveguides, Point3d position, Eigen::Quaternionf currentRotation, AudioBuffer<float>& sourceBuffer,
	int sampleIndex, int maxIndex, bool hasChanged, bool isRotating)
{
	sourceBuffer.clear(sampleIndex,1);

	if (hasChanged || isRotating)
		processWhileChanging(inWaveguides, position, currentRotation, sourceBuffer, sampleIndex);
	else
		processWhileStable(inWaveguides, sourceBuffer, sampleIndex);

}

void Stereo::panMonoToStereo(float panAmount)
{
	float pan = (panAmount / 2) + 0.5;

	monoToStereoDummy[1] = monoToStereoDummy[0] * sqrtf(pan); //right
	monoToStereoDummy[0] *= sqrtf(1 - pan); //left
}

void Stereo::processWhileChanging(std::vector<WaveGuide*>& inWaveguides, Point3d position, 
	Eigen::Quaternionf currentRotation, AudioBuffer<float>& sourceBuffer, int sampleIndex)
{
	float azimuth, x, z;

	lookAtVector = currentRotation * Eigen::Vector3f::UnitZ();
	lookAtVector.normalize();
	upVector = currentRotation * Eigen::Vector3f::UnitY();
	upVector.normalize();

	side = upVector.cross(lookAtVector);
	side.normalize();

	for (int i = 0; i < Parameters::NUM_WAVEGUIDES_TO_OUTPUT; i++)
	{
		microphoneToNodeVector = MathUtils::dirVector(inWaveguides[i]->getStart()->getPosition(), position);
		microphoneToNodeVector.normalize();

		x = microphoneToNodeVector.dot(side);
		z = microphoneToNodeVector.dot(lookAtVector);
		azimuth = atan2f(x, z);
		panValues[i] = sin(azimuth);

		panWaveguide(inWaveguides, i, sourceBuffer, sampleIndex);
	}
}

void Stereo::processWhileStable(std::vector<WaveGuide*>& inWaveguides, AudioBuffer<float>& sourceBuffer, int sampleIndex)
{
	for (int i = 0; i < Parameters::NUM_WAVEGUIDES_TO_OUTPUT; i++)
		panWaveguide(inWaveguides, i, sourceBuffer, sampleIndex);
}

void Stereo::panWaveguide(std::vector<WaveGuide*>& inWaveguides, int waveguideIndex, 
	AudioBuffer<float>& sourceBuffer, int sampleIndex)
{
	monoToStereoDummy.at(0) = inWaveguides[waveguideIndex]->getCurrentSample();
	monoToStereoDummy.at(1) = 0.0f;

	panMonoToStereo(panValues[waveguideIndex]);

	for (int ch = 0; ch < Parameters::STEREO_CHANNELS; ch++)
	{
		float sampleToAdd = monoToStereoDummy[ch];
		sourceBuffer.addSample(ch, sampleIndex, sampleToAdd);
	}
}
