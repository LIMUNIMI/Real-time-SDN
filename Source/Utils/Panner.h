#pragma once
#include <JuceHeader.h>


class Panner
{
public:
	static void panByValue(std::vector<float>& buffer, float panAmount);

private:
	
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Panner);
};