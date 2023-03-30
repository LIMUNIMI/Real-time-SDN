#pragma once
#include <Point3d.h>
#include <Node.h>
#include <WaveGuide.h>
#include <IIRBase.h>
#include <DSPUtils.h>

//Scattering node in SDN srchitecture uses IIR filters to simulate material absorption
class ScatteringNode : public Node
{
public:
	ScatteringNode();
	~ScatteringNode() {};

	void init(double samplerate, Point3d position, int nOfConnections, 
		WaveGuide* sourceNodeGuide, WaveGuide* nodeListenerGuide);
	
	//gather all incoming samples and process them
	void process();

	//update local absorption values array
	void setFreqAbsorption(float newValue, int index)
	{
		absorption[index] = newValue;
		newAbsorption = true;
	}
	//calculate filter coefficients from local absorption values array
	void updateFilterCoeffs(double samplerate)
	{
		std::vector<std::vector<double>> coeffs = dspUtils::getWallFilterCoeffs(samplerate, absorption[0],
			absorption[1], absorption[2], absorption[3], absorption[4], absorption[5], absorption[6], absorption[7]);

		a = coeffs[1];
		b = coeffs[0];

		for (IIRBase& filter : wallFilters)
		{
			filter.clearMemory();
		}

		newAbsorption = false;
	}

	bool hasNewAbsorption() { return newAbsorption; }

	std::vector<WaveGuide*> inWaveguides, outWaveguides;

private:

	//send correctly scattered and filtered sample in the waveguides
	void getAllOutSamples();

	std::vector<float> inSamples;
	float toListenerSample = 0;
	float totLoudness = 0;

	std::vector<IIRBase> wallFilters;
	WaveGuide* sourceGuide = 0;
	WaveGuide* listenerGuide = 0;

	int nOfConnections = 0;
	float scatteringCoeff = 0.0f;

	float absorption[Parameters::NUM_FREQ] = { 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f };
	bool newAbsorption = false;
	std::vector<double> a, b;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ScatteringNode);
};

