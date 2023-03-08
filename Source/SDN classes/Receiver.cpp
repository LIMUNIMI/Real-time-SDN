#include "Receiver.h"

using namespace Eigen;

Receiver::Receiver()
{
	setPosition({ 0, 0, 0 });
	mono = std::make_shared<Mono>();
	stereo = std::make_shared<Stereo>();
	ambisonic = std::make_shared<Ambisonic>();
	microphone = stereo;
}

void Receiver::init(Point3d normalPosition, int nOfConnections, double samplerate, Point3d dimensions, int nChannels)
{
	initRange(samplerate, normalPosition, dimensions);
	
	setPosition(getSmoothedPos());
	inWaveguides = std::vector<WaveGuide*>(nOfConnections, 0);

	setOutputMode(outModeIndex);
	microphone->init();
}

void Receiver::process(AudioBuffer<float>& currentSample, AudioBuffer<float>& sourceBuffer, int sampleIndex, int maxIndex, bool hasChanged)
{
	currentSample.clear();

	microphone->process(inWaveguides, getPosition(), currentSample, sourceBuffer, sampleIndex, maxIndex, hasChanged);
}

void Receiver::updatePosition()
{
	setPosition(getSmoothedPos());
}

void Receiver::setOutputMode(int mode)
{

	outModeIndex = mode;

	if (mode == 0)
	{
		microphone = mono;
	}
	else if (mode == 1)
	{
		microphone = stereo;
	}
	else
	{
		microphone = ambisonic;
		ambisonic->setAmbisonicOrder(mode - 1);
	}
	
}
