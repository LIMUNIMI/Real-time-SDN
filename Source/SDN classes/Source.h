#pragma once
#include "Point3d.h"
#include "WaveGuide.h"
#include "Node.h"

class Source : public HasBuffer
{
private:
	int numChannels;
	int bufferSize;
public:
	Source();
	Source(Point3d position);
	Source(Point3d position, int nChannels, int bufferSize);
	void addToBuffer(AudioBuffer<float>& inWave) override {};

	int getNChannels() { return numChannels; };
	int getBufferSize() { return bufferSize; };

};

