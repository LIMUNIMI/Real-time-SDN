#pragma once
#include "Point3d.h"
#include "Node.h"
#include <WaveGuide.h>

class Source : public Node
{
public:
	Source();
	~Source() {};

	void init(Point3d position, int nChannels, int bufferSize, int nOfConnections);

	void process(AudioBuffer<float>& currentSample, AudioBuffer<float>& sourceBuffer, const float** currentReadPointers, int sampleIndex);
	//void addToBuffer(AudioBuffer<float>& inWave) override {};

	int getNChannels() { return numChannels; };
	int getBufferSize() { return bufferSize; };

	std::vector<WaveGuide*> outWaveguides;

private:
	int numChannels = 0;
	int bufferSize = 0;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Source);
};

