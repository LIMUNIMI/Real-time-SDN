#pragma once

#include <JuceHeader.h>
#include <WaveGuide.h>
#include <NodeRotation.h>


class Microphone : public NodeRotation
{
public:

	Microphone() {};
	virtual ~Microphone() {};

	virtual void init() {};

	virtual void process(std::vector<WaveGuide*>& inWaveguides, Point3d position, AudioBuffer<float>& currentSample,
		AudioBuffer<float>& sourceBuffer, int sampleIndex, int maxIndex) {};

private:

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Microphone);
};