#pragma once

#include <Microphone.h>
#include <NodeRotation.h>
#include <WaveGuide.h>
#include <Parameters.h>

//implements stereo output, handles head rotation
class Stereo : public Microphone, public NodeRotation
{
public:
	Stereo() : monoToStereoDummy(2, 0.0f) {};
	~Stereo() {};

	void init() override;

	//pan from azimuth angle
	void process(std::vector<WaveGuide*>& inWaveguides, Point3d position, AudioBuffer<float>& sourceBuffer, 
		int sampleIndex, int maxIndex, bool hasChanged) override;


private:
	
	//square law panning function
	void panMonoToStereo(float panAmount);

	std::vector<float> monoToStereoDummy;
	Eigen::Vector3f microphoneToNodeVector;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Stereo);
};