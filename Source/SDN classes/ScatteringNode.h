#pragma once
#include <Point3d.h>
#include <Node.h>
#include <WaveGuide.h>

class ScatteringNode : public Node
{
public:
	ScatteringNode();
	~ScatteringNode() {};

	void init(Point3d position, int numChannels, int numSamples, int nOfConnections, WaveGuide* sourceNodeGuide, WaveGuide* nodeListenerGuide);
	void process();
	
	void addToBuffer(AudioBuffer<float>& inWave) override {};

	std::vector<WaveGuide*> inWaveguides, outWaveguides;

private:

	void getAllOutSamples(std::vector<float>& totLoudness);

	std::vector<std::vector<float>> inSamples;
	WaveGuide* sourceGuide = 0;
	WaveGuide* listenerGuide = 0;
	int nOfConnections = 0;
	int nChannels = 0;
	float scatteringCoeff = 0;
	float wallAbsorption = 0.8;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ScatteringNode);
};

