#pragma once

#include <JuceHeader.h>

//delay line implementation for waveguides, uses an all-pass filter to extract samples
class DelayLine
{
public:
	DelayLine() {};
	~DelayLine() {};

	void prepare(double samplerate, int maxLength, float delaySamp);
	
	void storeInDelay(const AudioBuffer<float>& buffer);
	void storeInDelay(const float* sampleReadPointer, float gain);
	void storeInDelay(float sample);
	float& readNextSample();
	
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

	double getSampleRate() { return sampleRate; };

private:

	AudioBuffer<float> circularBuffer;
	float oldSample = 0;
	float outSample = 0;
	int maxBufferLength = 0;
	double sampleRate = 1;
	float delaySamples = 0;
	int writeIndex = 0;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DelayLine);

};