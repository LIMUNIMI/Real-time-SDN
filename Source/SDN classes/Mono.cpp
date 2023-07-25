#include "Mono.h"

void Mono::init()
{
}

void Mono::process(std::vector<WaveGuide*>& inWaveguides, Point3d position, Eigen::Quaternionf currentRotation,
	AudioBuffer<float>& sourceBuffer, int sampleIndex, int maxIndex, bool hasChanged, bool isRotating)
{
	sourceBuffer.clear(sampleIndex, 1);

	for (WaveGuide* guide : inWaveguides)
	{
		sourceBuffer.addSample(0, sampleIndex, guide->getCurrentSample());
	}

}
