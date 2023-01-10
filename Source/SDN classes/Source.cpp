#include "Source.h"

Source::Source()
{
	setPosition({0, 0, 0});
	numChannels = 0;
	bufferSize = 0;
}

void Source::init(Point3d position, int nChannels, int bufferSize, int nOfConnections, double samplerate)
{
	setPosition(position);
	numChannels = nChannels;
	this->samplerate = samplerate;
	this->bufferSize = bufferSize;
	outWaveguides = std::vector<WaveGuide*>(nOfConnections, 0);

	initRange(bufferSize, position);
}

void Source::process(AudioBuffer<float>& currentSample, AudioBuffer<float>& sourceBuffer, const float** currentReadPointers, int sampleIndex)
{
	currentSample.clear();

	for (int ch = 0; ch < numChannels; ch++)
	{
		currentSample.copyFrom(ch, 0, sourceBuffer, ch, sampleIndex, 1);
	}

	for (WaveGuide* guide : outWaveguides)
	{
		guide->pushNextSample(currentReadPointers);
	}
}

void Source::updatePosition()
{
	setPosition(getSmoothedPos());
}
