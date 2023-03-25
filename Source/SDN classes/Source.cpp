#include "Source.h"

Source::Source()
{
	setPosition({0, 0, 0});
	bufferSize = 0;
}

void Source::init(Point3d normalPosition, int bufferSize, int nOfConnections, double samplerate, Point3d dimensions)
{
	initRange(samplerate, normalPosition, dimensions);
	setPosition(getSmoothedPos());
	this->samplerate = samplerate;
	this->bufferSize = bufferSize;
	outWaveguides = std::vector<WaveGuide*>(nOfConnections, 0);
}

void Source::process(const float* currentReadPointer, int sampleIndex)
{
	for (WaveGuide* guide : outWaveguides)
	{
		guide->pushNextSample(currentReadPointer[sampleIndex]);
	}
}

void Source::updatePosition()
{
	setPosition(getSmoothedPos());
}
