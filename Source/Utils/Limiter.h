#pragma once

#include <JuceHeader.h>

#define THRESHOLD -1
#define RELEASE 0.40

class Limiter
{
public:
	Limiter() {}
	~Limiter() {}

	void prepareToPlay(double sampleRate);

	void releaseResources()
	{
		sideChain = 0;
	}

	void processBlock(float& inSample);

	void reset()
	{
		old = 0.0;
	}

private:

	double sideChain = 0;

	double t = 1.0;
	double r = 1.0;
	double rat = 1.0;

	double old = 0;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Limiter)
};