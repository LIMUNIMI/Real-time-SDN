#include "Panner.h"

void Panner::panByValue(std::vector<float>& buffer, float panAmount)
{
	panAmount > 0 ? buffer[1] *= 1 + panAmount : buffer[0] *= 1 - panAmount;
}
