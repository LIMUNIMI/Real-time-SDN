#pragma once
#include <JuceHeader.h>

//To be deleted
class Panner
{
public:
	static void panByValue(std::vector<float>& buffer, float panAmount);

	static void panMonoToStereo(std::vector<float>& buffer, float panAmount);

private:
	
};