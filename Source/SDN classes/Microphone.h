#pragma once

#include <JuceHeader.h>
#include <WaveGuide.h>
#include <NodeRotation.h>


class Microphone
{
public:

	Microphone() {};
	virtual ~Microphone() {};

	virtual void init() {};

	virtual void process(std::vector<WaveGuide*>& inWaveguides, Point3d position, AudioBuffer<float>& currentSample,
		AudioBuffer<float>& sourceBuffer, int sampleIndex, int maxIndex, bool hasChanged) {};

private:

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Microphone);
};