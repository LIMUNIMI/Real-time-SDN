#pragma once

#include "Point3d.h"
#include "Node.h"
#include "NormalPosition.h"
#include <WaveGuide.h>
#include <Microphone.h>
#include <Stereo.h>
#include <Mono.h>
#include <Ambisonic.h>

//Listener node in the SDN architecture, can output mono, stereo or ambisonics
class Receiver : public Node, public NormalPosition
{
public:
	Receiver();
	~Receiver() { microphone.reset(); };

	//initialize all output instances to save performance during playback
	void init(Point3d normalPosition, int nOfConnections, double samplerate, Point3d dimensions);

	void process(AudioBuffer<float>& sourceBuffer, int sampleIndex, int maxIndex, bool hasChanged);

	void updatePosition();
	

	void setRotation(float newValue, const char& axis)
	{
		stereo->setRotation(newValue, axis);
	}

	void updateQuaternion()
	{
		stereo->updateQuaternion();
	}

	void setOutputMode(int mode);

	std::vector<WaveGuide*> inWaveguides;

private:

	//currently selected output mode 0-Mono 1-Stereo 2->6 Ambisonic
	int outModeIndex = 0;
	
	std::shared_ptr<Microphone> microphone;
	std::shared_ptr<Mono> mono;
	std::shared_ptr<Stereo> stereo;
	std::shared_ptr<Ambisonic> ambisonic;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Receiver);

};