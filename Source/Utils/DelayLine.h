#pragma once

#include <JuceHeader.h>

class DelayLine
{
public:
	DelayLine() {};
	~DelayLine() {};

	void prepare(double samplerate, int numChannels, int maxLength, float delaySamp);
	
	void storeInDelay(const AudioBuffer<float>& buffer);
	std::vector<float>& readNextSample();
	
	void advanceWriteIndex()
	{
		writeIndex++;
		writeIndex %= maxBufferLength;
	}

	void setDelay(float newDelay) { delaySamples = newDelay; };
	
	void releaseResources() 
	{
		circularBuffer.setSize(0,0);
		maxBufferLength = 0;
	}

private:

	AudioBuffer<float> circularBuffer;
	std::vector<float> oldSample;
	std::vector<float> outSamples;
	int maxBufferLength = 0;
	double sampleRate = 1;
	float delaySamples = 0;
	int writeIndex = 0;
	int numChannels = 0;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DelayLine);

};