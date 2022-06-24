#pragma once
#include "ScatteringNode.h"
#include <JuceHeader.h>

class WaveGuide
{
private:
	std::shared_ptr<HasBuffer> startNode;
	std::shared_ptr<HasBuffer> endNode;

	float distance;
	float delay;
	float attenuation;

	dsp::ProcessorChain<dsp::Gain<float>, dsp::DelayLine<float>> processorChain;

public:
	WaveGuide();
	WaveGuide(std::shared_ptr<HasBuffer> start, std::shared_ptr<HasBuffer> end);

	std::shared_ptr<HasBuffer> getStart() { return startNode; };
	std::shared_ptr<HasBuffer> getEnd() { return endNode; };
	float getDelay() { return delay; };
	float getDistance() { return distance; };
	float getAttenuation() { return attenuation; };

	dsp::ProcessorChain<dsp::Gain<float>, dsp::DelayLine<float>> getProcessor() { return processorChain; };

	void prepare(double samplerate, int samplesPerBlock, uint32 nChannels);
	void prepare(double samplerate, int samplesPerBlock, uint32 nChannels, uint32 nNodes);
	void process(AudioBuffer<float>& currentContext);

	void updateParams();
};

