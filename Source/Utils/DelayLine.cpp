#include "DelayLine.h"

void DelayLine::prepare(double samplerate, int numChan, int maxLength, float delaySamp)
{
	maxBufferLength = maxLength;
	circularBuffer.setSize(numChan, maxBufferLength);
	circularBuffer.clear();
	sampleRate = samplerate;
	numChannels = numChan;
	oldSample = std::vector<float>(numChan, 0.0f);
	outSamples = std::vector<float>(numChannels, 0.0f);
	delaySamples = delaySamp;
}

void DelayLine::storeInDelay(const AudioBuffer<float>& buffer)
{
	
	for (int i = 0; i < numChannels; i++)
	{
		circularBuffer.copyFrom(i, writeIndex, buffer, i, 0, 1);
	}
}

std::vector<float>& DelayLine::readNextSample()
{

	auto** delayReadPointers = circularBuffer.getArrayOfReadPointers();

	float fReadIndex = maxBufferLength + writeIndex - delaySamples;
	int readIndex = (int)fReadIndex;
	float fractionalIndex = fReadIndex - readIndex;
	const float allPassCoeff = fractionalIndex / (2.0f - fractionalIndex);

	readIndex %= maxBufferLength;
	int nextIndex = (readIndex + 1) % maxBufferLength;

	for (int i = 0; i < numChannels; i++)
	{
		auto sample = allPassCoeff * (delayReadPointers[i][nextIndex] - oldSample.at(i)) + delayReadPointers[i][readIndex];
		oldSample.at(i) = sample;
		outSamples[i] = sample;
	}


	return outSamples;
}
