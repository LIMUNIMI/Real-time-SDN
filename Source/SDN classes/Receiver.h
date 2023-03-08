#pragma once

#include "Point3d.h"
#include "Node.h"
#include "NormalPosition.h"
#include <WaveGuide.h>
#include <Microphone.h>
#include <Stereo.h>
#include <Mono.h>
#include <Ambisonic.h>

class Receiver : public Node, public NormalPosition
{
public:
	Receiver();
	~Receiver() { microphone.reset(); };

	void init(Point3d normalPosition, int bufferSize, int nOfConnections, Point3d dimensions, int nChannels);
	void process(AudioBuffer<float>& currentSample, AudioBuffer<float>& sourceBuffer, int sampleIndex, int maxIndex);

	void updatePosition();
	std::vector<WaveGuide*> inWaveguides;

	void setRotation(float newValue, const char& axis)
	{
		microphone->setRotation(newValue, axis);
	}

	void updateQuaternion()
	{
		microphone->updateQuaternion();
	}

	void sync()
	{
		microphone->sync();
	}

	void setOutputMode(int mode);


private:

	void setAmbisonicOrder(int newOrder)
	{
		ambisonic->setAmbisonicOrder(newOrder);
	}

	int outModeIndex = 0;
	
	std::shared_ptr<Microphone> microphone;
	std::shared_ptr<Mono> mono;
	std::shared_ptr<Stereo> stereo;
	std::shared_ptr<Ambisonic> ambisonic;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Receiver);

};