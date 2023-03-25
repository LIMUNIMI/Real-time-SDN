#pragma once
#include "Point3d.h"
#include "Node.h"
#include "NormalPosition.h"
#include <WaveGuide.h>

//Source node in the SDN architecture
class Source : public Node, public NormalPosition
{
public:
	Source();
	~Source() {};

	void init(Point3d normalPosition, int bufferSize, int nOfConnections, double samplerate, Point3d dimensions);

	void process(const float* currentReadPointer, int sampleIndex);

	void updatePosition();

	int getBufferSize() { return bufferSize; };
	double getSamplerate() { return samplerate; };

	std::vector<WaveGuide*> outWaveguides;

private:
	int bufferSize = 0;
	double samplerate = 48000;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Source);
};

