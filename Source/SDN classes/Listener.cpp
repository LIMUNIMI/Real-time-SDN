#include "Listener.h"
#include <Panner.h>

void Listener::init(Point3d position, int nOfConnections)
{
	setPosition(position);
	inWaveguides = std::vector<WaveGuide*>(nOfConnections, 0);
	//newBuffer(nChannels, numSamples);
	//cleanBuffer();
}

void Listener::process(int nChannels, AudioBuffer<float>& currentSample, AudioBuffer<float>& sourceBuffer, int sampleIndex)
{
	currentSample.clear();
	Point3d playerToNodeVector;
	float panValue;

	for (WaveGuide* guide : inWaveguides)
	{
		playerToNodeVector = MathUtils::dirVector(guide->getStart()->getPosition(), getPosition());
		panValue = -copysignf(1, playerToNodeVector.x) * MathUtils::sinOfAzimuth(playerToNodeVector, forward);
		std::vector<float>& guideSample = guide->getCurrentSample();

		Panner::panByValue(guideSample, panValue);
		for (int ch = 0; ch < nChannels; ch++)
		{
			float sampleToAdd = guideSample[ch];
			currentSample.addSample(ch, 0, sampleToAdd);
		}
	}

	for (int ch = 0; ch < nChannels; ch++)
	{
		sourceBuffer.copyFrom(ch, sampleIndex, currentSample, ch, 0, 1);
	}
}

Listener::Listener()
{
	setPosition({ 0, 0, 0 });
	//newBuffer(0, 0);
}