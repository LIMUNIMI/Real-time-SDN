#pragma once
#include <JuceHeader.h>

class IIRBase
{
public:
	IIRBase();
	~IIRBase() {};

	void init(double samplerate, std::vector<double>* a, std::vector<double>* b);
	void process(float& sample);

private:

	//filter memory
	//float buffer1, buffer2;

	std::vector<double> memory;

	//filter coeffs
	//float b0, b1, b2;
	//float a1, a2;

	std::vector<double> *a, *b;

	double sampleRate;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(IIRBase);

};