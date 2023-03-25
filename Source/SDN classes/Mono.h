#pragma once

#include <Microphone.h>
#include <WaveGuide.h>
#include <Parameters.h>

class Mono : public Microphone
{
public:
	Mono() {};
	~Mono() {};

	void init() override;

	void process(std::vector<WaveGuide*>& inWaveguides, Point3d position, AudioBuffer<float>& currentSample,
		AudioBuffer<float>& sourceBuffer, int sampleIndex, int maxIndex, bool hasChanged) override;

private:

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Mono);

};