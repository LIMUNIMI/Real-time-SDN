#pragma once
#include <Node.h>
#include <JuceHeader.h>
#include <DelayLine.h>
#include <Parameters.h>

class WaveGuide
{
public:
	WaveGuide();
	~WaveGuide() {};

	Node* getStart() { return startNode; };
	Node* getEnd() { return endNode; };
	float getDistance() { return distance; };
	float getAttenuation() { return attenuation; };
	void setDistance(float newDist);
	void setAttenuation(float newValue) { attenuation = newValue; };

	void prepare(double samplerate, Node* start, Node* end, float dist);

	float& getCurrentSample() { return delay.readNextSample(); };
	void pushNextSample(AudioBuffer<float>& sample) 
	{
		if (attenuation != 1.0f) sample.applyGain(attenuation);
		delay.storeInDelay(sample); 
	}

	void pushNextSample(const float* sampleReadPointer)
	{
		delay.storeInDelay(sampleReadPointer, attenuation);
	}

	void pushNextSample(float sample)
	{
		if (attenuation != 1.0f) sample *= attenuation;
		delay.storeInDelay(sample);
	}
	void stepForward() { delay.advanceWriteIndex(); };


private:
	Node* startNode;
	Node* endNode;
	DelayLine delay;

	float distance;
	float toSamplesConst = 0;
	float attenuation;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(WaveGuide);

};

