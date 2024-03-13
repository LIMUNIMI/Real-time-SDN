#pragma once
#include <Node.h>
#include <JuceHeader.h>
#include <DelayLine.h>
#include <Parameters.h>
#include <IIRBase.h>
#include <FilterPresets.h>

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
	void setAttenuation(float newValue) { attenuation = jlimit(0.0f, 1.0f, newValue); };

	void prepare(double samplerate, Node* start, Node* end, float dist);

	float& getCurrentSample();

	//push sample into the delay-line
	void pushNextSample(AudioBuffer<float>& sample) //TODO remove if not necessary
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

	//advance delay-line by one sample
	void stepForward() { delay.advanceWriteIndex(); };

	void enableAirAbsorption(bool absorb) 
	{ 
		airAbsorption = absorb;
		airAbsorptionFilter.clearMemory();
	};


private:
	Node* startNode;
	Node* endNode;
	DelayLine delay;

	float distance;
	float toSamplesConst = 0;
	float attenuation;
	double sampleFreq = 0;

	std::vector<double> a, b;
	IIRBase airAbsorptionFilter;
	bool airAbsorption = false;
	bool isNodeToNode = false;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(WaveGuide);

};

