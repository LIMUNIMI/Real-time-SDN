#include "DelayLine.h"

void DelayLine::prepare(double samplerate, int maxLength, float delaySamp)
{
	maxBufferLength = maxLength;
	circularBuffer.setSize(1, maxBufferLength);
	circularBuffer.clear();
	sampleRate = samplerate;
	delaySamples = delaySamp;
}

void DelayLine::storeInDelay(const AudioBuffer<float>& buffer)
{
	circularBuffer.copyFrom(0, writeIndex, buffer, 0, 0, 1);
}

void DelayLine::storeInDelay(const float* sampleReadPointer, float gain)
{
	circularBuffer.copyFrom(0, writeIndex, sampleReadPointer, 1, gain);
}

void DelayLine::storeInDelay(float sample)
{
	circularBuffer.setSample(0, writeIndex, sample);
}

float& DelayLine::readNextSample()
{

	auto* delayReadPointer = circularBuffer.getReadPointer(0);

	float fReadIndex = maxBufferLength + writeIndex - delaySamples;
	int readIndex = (int)fReadIndex;
	float fractionalIndex = fReadIndex - readIndex;
	const float allPassCoeff = fractionalIndex / (2.0f - fractionalIndex);

	readIndex %= maxBufferLength;
	int nextIndex = (readIndex + 1) % maxBufferLength;

	auto sample = allPassCoeff * (delayReadPointer[nextIndex] - oldSample) + delayReadPointer[readIndex];
	oldSample = sample;
	outSample = sample;


	return outSample;
}
