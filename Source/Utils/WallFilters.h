#pragma once
#include <JuceHeader.h>
#include <BiquadFIlter.h>

#define N_OF_FILTERS 6


class WallFilters
{
public:
	WallFilters();
	~WallFilters() {};

	void prepare(double samplerate, std::vector<float>& octaveCoeffs);
	void process(float& sample);


private:

	std::vector<BiquadFilter> EQ = std::vector<BiquadFilter>(N_OF_FILTERS);

	const float EQFrequency[N_OF_FILTERS] = { 125.0f, 250.0f, 500.0f, 1000.0f, 2000.0f, 4000.0f };

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(WallFilters);

};