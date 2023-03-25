#include "Mono.h"

void Mono::init()
{
}

void Mono::process(std::vector<WaveGuide*>& inWaveguides, Point3d position, AudioBuffer<float>& sourceBuffer, 
	int sampleIndex, int maxIndex, bool hasChanged)
{
	sourceBuffer.clear(sampleIndex, 1);

	for (WaveGuide* guide : inWaveguides)
	{
		sourceBuffer.addSample(0, sampleIndex, guide->getCurrentSample());
	}

}
