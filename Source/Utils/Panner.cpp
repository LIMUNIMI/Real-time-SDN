#include "Panner.h"

void Panner::panByValue(std::vector<float>& buffer, float panAmount)
{
	panAmount > 0 ? buffer[1] *= 1 - panAmount : buffer[0] *= 1 + panAmount; //cambiare in if
}

void Panner::panMonoToStereo(std::vector<float>& buffer, float panAmount)
{
	float pan = (panAmount / 2) + 0.5;

	buffer[1] = buffer[0] * sqrtf(pan); //right
	buffer[0] *= sqrtf(1 - pan); //left
}
