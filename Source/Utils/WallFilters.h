#pragma once
#include <JuceHeader.h>
#include <IIRBase.h>
#include <DSPUtils.h>

#define N_OF_FILTERS 6


class WallFilters
{
public:
	WallFilters();
	~WallFilters() {};

	void prepare(double samplerate);
	void process(float& sample);


private:

	IIRBase filter;

	float absorption[6] = { 0.08, 0.2, 0.55, 0.65, 0.5, 0.4 };

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(WallFilters);

};