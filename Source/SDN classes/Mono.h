#pragma once

#include <Microphone.h>
#include <WaveGuide.h>
#include <Parameters.h>

//handles MONO output
class Mono : public Microphone
{
public:
	Mono() {};
	~Mono() {};

	void init() override;

	void process(std::vector<WaveGuide*>& inWaveguides, Point3d position, Eigen::Quaternionf currentRotation,
		AudioBuffer<float>& sourceBuffer, int sampleIndex, int maxIndex, bool hasChanged, bool isRotating) override;

private:

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Mono);

};