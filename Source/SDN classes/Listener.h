#pragma once
#include "Point3d.h"
#include "Node.h"
#include <WaveGuide.h>
#include "MathUtils.h"

class Listener : public Node
{
public:

	Listener();
	~Listener() {};
	void init(Point3d position, int nOfConnections);
	void process(int nChannels, AudioBuffer<float>& currentSample, AudioBuffer<float>& sourceBuffer, int sampleIndex);

	Point3d forward = {0, 0, -1};
	std::vector<WaveGuide*> inWaveguides;

private:

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Listener);

};

