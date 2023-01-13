#pragma once
#include <Point3d.h>
#include <Node.h>
#include <WaveGuide.h>
#include <IIRBase.h>
#include <DSPUtils.h>

class ScatteringNode : public Node
{
public:
	ScatteringNode();
	~ScatteringNode() {};

	void init(double samplerate, Point3d position, int nOfConnections, 
		WaveGuide* sourceNodeGuide, WaveGuide* nodeListenerGuide);
	void process();

	void setAbsorption(float newValue) { wallAbsorption = newValue; };

	void setFreqAbsorption(float newValue, int index)
	{
		absorption[index] = newValue;
	}

	void updateFilterCoeffs(double samplerate)
	{
		std::vector<std::vector<double>> coeffs = dspUtils::getWallFilterCoeffs(samplerate, absorption[0],
			absorption[1], absorption[2], absorption[3], absorption[4], absorption[5]);

		a = coeffs[1];
		b = coeffs[0];
	}
	
	//void addToBuffer(AudioBuffer<float>& inWave) override {};

	std::vector<WaveGuide*> inWaveguides, outWaveguides;

private:

	void getAllOutSamples();

	std::vector<float> inSamples;
	AudioBuffer<float> toListenerSample;
	float totLoudness = 0;

	std::vector<IIRBase> wallFilters;
	WaveGuide* sourceGuide = 0;
	WaveGuide* listenerGuide = 0;

	int nOfConnections = 0;
	float scatteringCoeff = 0.0f;
	float wallAbsorption = 0.8f;

	float absorption[6] = { 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f };
	//std::vector<std::vector<double>> coeffs;
	std::vector<double> a, b;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ScatteringNode);
};

