#pragma once
#include <Point3d.h>
#include <Node.h>
#include <WaveGuide.h>
#include <WallFilters.h>

class ScatteringNode : public Node
{
public:
	ScatteringNode();
	~ScatteringNode() {};

	void init(double samplerate, Point3d position, int numChannels, int nOfConnections, 
		WaveGuide* sourceNodeGuide, WaveGuide* nodeListenerGuide, std::vector<float>& octaveCoeffs);
	void process();

	void setAbsorption(float newValue) { wallAbsorption = newValue; };
	
	//void addToBuffer(AudioBuffer<float>& inWave) override {};

	std::vector<WaveGuide*> inWaveguides, outWaveguides;

private:

	void getAllOutSamples();

	std::vector<std::vector<float>> inSamples;
	AudioBuffer<float> toListenerSample;
	std::vector<float> totLoudness;
	std::vector<std::vector<WallFilters>> wallFilter;
	WaveGuide* sourceGuide = 0;
	WaveGuide* listenerGuide = 0;
	int nOfConnections = 0;
	int nChannels = 0;
	float scatteringCoeff = 0.0f;
	float wallAbsorption = 0.8f;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ScatteringNode);
};

