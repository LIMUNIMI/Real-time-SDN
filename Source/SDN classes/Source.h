#pragma once
#include "Point3d.h"
#include "HasBuffer.h"

class Source : public HasBuffer
{
public:
	Source();

	void init(Point3d position, int nChannels, int bufferSize);
	void addToBuffer(AudioBuffer<float>& inWave) override {};

	int getNChannels() { return numChannels; };
	int getBufferSize() { return bufferSize; };

private:
	int numChannels;
	int bufferSize;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Source);
};

