#pragma once
#include <Node.h>
#include <JuceHeader.h>
#include <DelayLine.h>

class WaveGuide
{
public:
	WaveGuide();
	~WaveGuide() {};

	Node* getStart() { return startNode; };
	Node* getEnd() { return endNode; };
	float getDelay() { return delayInSamples; };
	float getDistance() { return distance; };
	float getAttenuation() { return attenuation; };
	void setAttenuation(float newValue) { attenuation = newValue; };

	void prepare(double samplerate, int samplesPerBlock, uint32 nChannels, Node* start, Node* end, float dist);

	std::vector<float>& getCurrentSample() { return delay.readNextSample(); };
	void pushNextSample(AudioBuffer<float>& sample) 
	{
		if (attenuation != 1.0f) sample.applyGain(attenuation);
		delay.storeInDelay(sample); 
	}
	void stepForward() { delay.advanceWriteIndex(); };


private:
	Node* startNode;
	Node* endNode;
	DelayLine delay;

	float distance;
	float delayInSamples;
	float attenuation;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(WaveGuide);

};

