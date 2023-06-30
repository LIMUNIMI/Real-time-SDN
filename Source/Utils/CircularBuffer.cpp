#include "CircularBuffer.h"

void CircularBuffer::prepare(double samplerate, int nchannels, int maxLength, int writeHead)
{
	maxBufferLength = maxLength;
	circularBuffer.setSize(nchannels, maxBufferLength);
	circularBuffer.clear();
	sampleRate = samplerate;
	writeIndex = writeHead % maxBufferLength;
	readIndex = 0;
}

void CircularBuffer::storeInBuffer(const AudioBuffer<float>& buffer)
{
	const auto numCh = buffer.getNumChannels();
	const auto numInputSamples = buffer.getNumSamples();

	for (int ch = 0; ch < numCh; ++ch)
		if (writeIndex + numInputSamples <= maxBufferLength)
			circularBuffer.copyFrom(ch, writeIndex, buffer, ch, 0, numInputSamples);
		else
		{
			const auto fittingSamples = maxBufferLength - writeIndex;
			const auto remainingSamples = numInputSamples - fittingSamples;

			circularBuffer.copyFrom(ch, writeIndex, buffer, ch, 0, fittingSamples);
			circularBuffer.copyFrom(ch, 0, buffer, ch, fittingSamples, remainingSamples);
		}

	for (int i = numCh; i < circularBuffer.getNumChannels(); i++)
	{
		if (writeIndex + numInputSamples <= maxBufferLength)
			circularBuffer.clear(i, writeIndex, numInputSamples);
		else
		{
			const auto fittingSamples = maxBufferLength - writeIndex;
			const auto remainingSamples = numInputSamples - fittingSamples;

			circularBuffer.clear(i, writeIndex, fittingSamples);
			circularBuffer.clear(i, 0, remainingSamples);
		}
	}

	writeIndex += numInputSamples;
	writeIndex %= maxBufferLength;
}

void CircularBuffer::readFromBuffer(AudioBuffer<float>& destBuffer)
{
	const auto numCh = destBuffer.getNumChannels();
	const auto numOutputSamples = destBuffer.getNumSamples();

	for (int ch = 0; ch < numCh; ++ch)
		if (readIndex + numOutputSamples <= maxBufferLength)
			destBuffer.copyFrom(ch, 0, circularBuffer, ch, readIndex, numOutputSamples);
		else
		{
			const auto fittingSamples = maxBufferLength - readIndex;
			const auto remainingSamples = numOutputSamples - fittingSamples;

			destBuffer.copyFrom(ch, 0, circularBuffer, ch, readIndex, fittingSamples);
			destBuffer.copyFrom(ch, fittingSamples, circularBuffer, ch, 0, remainingSamples);

		}

	readIndex += numOutputSamples;
	readIndex %= maxBufferLength;
}
