#pragma once
#include <Node.h>
#include <JuceHeader.h>
#include <DelayLine.h>
#include <Parameters.h>

//waveguides that connect all the nodes in the SDN architecture
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

	//push sample into the delay-line
	void pushNextSample(AudioBuffer<float>& sample) 
	{
		sample.applyGain(attenuation);
		delay.storeInDelay(sample); 
	}
	void pushNextSample(const float* sampleReadPointer)
	{
		delay.storeInDelay(sampleReadPointer, attenuation);
	}
	void pushNextSample(float sample)
	{
		sample *= attenuation;
		delay.storeInDelay(sample);
	}

	//advance delay-line by one sample
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

