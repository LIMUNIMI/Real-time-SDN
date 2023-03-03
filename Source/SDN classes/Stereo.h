#pragma once

#include <Microphone.h>
#include <NodeRotation.h>
#include <WaveGuide.h>
#include <Parameters.h>


class Stereo : public Microphone
{
public:
	Stereo() : monoToStereoDummy(2, 0.0f) {};
	~Stereo() {};

	void init() override;

	void process(std::vector<WaveGuide*>& inWaveguides, Point3d position, AudioBuffer<float>& currentSample,
		AudioBuffer<float>& sourceBuffer, int sampleIndex, int maxIndex) override;


private:
	
	void panMonoToStereo(float panAmount);

	std::vector<float> monoToStereoDummy;
	Eigen::Vector3f microphoneToNodeVector;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Stereo);
};