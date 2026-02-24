#pragma once

#include <JuceHeader.h>

class CircularBuffer
{
public:
	CircularBuffer() {};
	~CircularBuffer() {};

	void prepare(double samplerate, int nchannels, int maxLength, int writeHead = 0);

	void storeInBuffer(const juce::AudioBuffer<float>& buffer);
	void readFromBuffer(juce::AudioBuffer<float>& destBuffer);

	int getNumNotReadSamples() { return (writeIndex + maxBufferLength - readIndex) % maxBufferLength; }

private:

	juce::AudioBuffer<float> circularBuffer;
	int maxBufferLength = 0;
	double sampleRate = 1;
	int writeIndex = 0;
	int readIndex = 0;

};