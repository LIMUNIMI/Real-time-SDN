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

void Receiver::init(Point3d normalPosition, int nOfConnections, double samplerate, Point3d dimensions)
{
	initRange(samplerate, normalPosition, dimensions);
	
	setPosition(getSmoothedPos());
	inWaveguides = std::vector<WaveGuide*>(nOfConnections, 0);

	setOutputMode(outModeIndex);
	mono->init();
	stereo->init(samplerate);
	ambisonic->init();
}

void Receiver::process(AudioBuffer<float>& sourceBuffer, int sampleIndex, int maxIndex, bool hasChanged)
{
	microphone->process(inWaveguides, getPosition(), sourceBuffer, sampleIndex, maxIndex, hasChanged);
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
