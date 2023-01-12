#pragma once
#include "Point3d.h"
#include "Node.h"
#include "NormalPosition.h"
#include <WaveGuide.h>

class Source : public Node, public NormalPosition
{
public:
	Source();
	~Source() {};

	void init(Point3d normalPosition, int bufferSize, int nOfConnections, double samplerate, Point3d dimensions);

	void process(AudioBuffer<float>& currentSample, AudioBuffer<float>& sourceBuffer, const float* currentReadPointer, int sampleIndex);
	//void addToBuffer(AudioBuffer<float>& inWave) override {};

	void updatePosition();

	int getBufferSize() { return bufferSize; };
	double getSamplerate() { return samplerate; };

	std::vector<WaveGuide*> outWaveguides;

private:
	int bufferSize = 0;
	double samplerate = 48000;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Source);
};

