#pragma once

#include <Microphone.h>
#include <NodeRotation.h>
#include <WaveGuide.h>
#include <Parameters.h>

//implements stereo output, handles head rotation
class Stereo : public Microphone
{
public:
	Stereo() : monoToStereoDummy(2, 0.0f),panValues(Parameters::NUM_WAVEGUIDES_TO_OUTPUT, 0.0f) {};
	~Stereo() {};

	void init(double sampleRate);

	//pan from azimuth angle
	void process(std::vector<WaveGuide*>& inWaveguides, Point3d position, Eigen::Quaternionf currentRotation, 
		AudioBuffer<float>& sourceBuffer, int sampleIndex, int maxIndex, bool hasChanged, bool isRotating) override;


private:
	
	//square law panning function
	void panMonoToStereo(float panAmount);

	void processWhileChanging(std::vector<WaveGuide*>& inWaveguides, Point3d position, Eigen::Quaternionf currentRotation,
		AudioBuffer<float>& sourceBuffer, int sampleIndex);
	void processWhileStable(std::vector<WaveGuide*>& inWaveguides,AudioBuffer<float>& sourceBuffer, int sampleIndex);
	void panWaveguide(std::vector<WaveGuide*>& inWaveguides, int waveguideIndex,
		AudioBuffer<float>& sourceBuffer, int sampleIndex);

	std::vector<float> monoToStereoDummy;
	Eigen::Vector3f microphoneToNodeVector, lookAtVector, upVector, side;

	std::vector<float> panValues;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Stereo);
};