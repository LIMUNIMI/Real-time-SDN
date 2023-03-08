#include "Mono.h"

void Mono::init()
{
}

void Mono::process(std::vector<WaveGuide*>& inWaveguides, Point3d position, AudioBuffer<float>& currentSample, 
	AudioBuffer<float>& sourceBuffer, int sampleIndex, int maxIndex, bool hasChanged)
{

	for (WaveGuide* guide : inWaveguides)
	{
		currentSample.addSample(0, 0, guide->getCurrentSample());
	}

	sourceBuffer.copyFrom(0, sampleIndex, currentSample, 0, 0, 1);

}
