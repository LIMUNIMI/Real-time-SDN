#pragma once

#include <JuceHeader.h>
#include <WaveGuide.h>
#include <NodeRotation.h>
#include <Eigen/Geometry>

//virtual class for output modes
class Microphone
{
public:

	Microphone() {};
	virtual ~Microphone() {};

	virtual void init() {};

	virtual void process(std::vector<WaveGuide*>& inWaveguides, Point3d position, Eigen::Quaternionf currentRotation, AudioBuffer<float>& sourceBuffer,
		int sampleIndex, int maxIndex, bool hasChanged, bool isRotating) {};

private:

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Microphone);
};