#include "WallFilters.h"

WallFilters::WallFilters()
{
}

void WallFilters::prepare(double samplerate)
{
	std::vector<std::vector<double>> coeffs = dspUtils::getWallFilterCoeffs(samplerate, absorption[0], 
		absorption[1], absorption[2], absorption[3], absorption[4], absorption[5], absorption[5], absorption[5]);

	filter.init(samplerate, &coeffs[1], &coeffs[0]);
}

void WallFilters::process(float& sample)
{

	filter.process(sample);

}
