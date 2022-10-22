#pragma once

#include <JuceHeader.h>
#include"Node.h"

class HasBuffer : public Node
{
public:

	AudioBuffer<float>* getBuffer() { return &buffer; };
	void setBuffer(AudioBuffer<float> newBuffer) { buffer.makeCopyOf(newBuffer); };
	void newBuffer(int numChannels, int numSamples) { buffer = AudioBuffer<float>(numChannels, numSamples); buffer.clear(); };
	void addToBuffer(AudioBuffer<float>& inWave) override;
	void cleanBuffer() { buffer.clear(); };

private:
	AudioBuffer<float> buffer;
};

