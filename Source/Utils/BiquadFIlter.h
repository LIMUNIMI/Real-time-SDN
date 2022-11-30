#pragma once
#include <JuceHeader.h>

class BiquadFilter
{
public:
	BiquadFilter();
	~BiquadFilter() {};

	void init(double samplerate, float centerFreq, float gain);
	void process(float& sample);

private:

	void normalizeByA0(float a0);
	void peakingEQ(float centerFreq, float gain);

	//filter memory
	float buffer1, buffer2;
	//filter coeffs
	float b0, b1, b2;
	float a1, a2;

	float Q = 10;
	double sampleRate;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(BiquadFilter);

};