#pragma once
#include <JuceHeader.h>

//IIR filter implemented in direct form II, accepts any filter order
class IIRBase
{
public:
	IIRBase();
	~IIRBase() {};

	void init(double samplerate, std::vector<double>* a, std::vector<double>* b);
	void process(float& sample);

private:

	std::vector<double> memory;
	std::vector<double> *a, *b;

	double sampleRate;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(IIRBase);

};