#include "Limiter.h"
using namespace juce;

void Limiter::prepareToPlay(double sampleRate)
{
	t = Decibels::decibelsToGain(THRESHOLD);
	r = exp(-1.0 / (RELEASE * sampleRate));
	rat = 1.0 / t;
	sideChain = 0;
}

void Limiter::processBlock(float& inSample)
{
	// GR COMPUTING
	sideChain = abs(inSample) * rat;

	sideChain = sideChain > 1 ? 1.0 / sideChain : 1;

	// SMOOTHING
	sideChain = -sideChain + 1;

	sideChain = jmax(sideChain, old * r);
	old = sideChain;

	sideChain = -sideChain + 1;

	// AM / VCA

	inSample *= sideChain;
}
