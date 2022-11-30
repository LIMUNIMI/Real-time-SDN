#include "WallFilters.h"

WallFilters::WallFilters()
{
}

void WallFilters::prepare(double samplerate, std::vector<float>& octaveCoeffs)
{
	for (int i = 0; i < N_OF_FILTERS; i++)
	{
		EQ[i].init(samplerate, EQFrequency[i], -octaveCoeffs[i]);
	}
}

void WallFilters::process(float& sample)
{

	EQ[0].process(sample);
	/*for (BiquadFilter& filter : EQ)
	{
		filter.process(sample);
	}*/

}
