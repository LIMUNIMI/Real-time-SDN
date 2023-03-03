#include "Receiver.h"

using namespace Eigen;

Receiver::Receiver()
{
	setPosition({ 0, 0, 0 });
	mono = std::make_shared<Mono>();
	stereo = std::make_shared<Stereo>();
	ambisonic = std::make_shared<Ambisonic>();
}

void Receiver::init(Point3d normalPosition, int bufferSize, int nOfConnections, Point3d dimensions, int nChannels)
{
	initRange(bufferSize, normalPosition, dimensions);
	
	setPosition(getSmoothedPos());
	inWaveguides = std::vector<WaveGuide*>(nOfConnections, 0);

	switch (nChannels)
	{
	case 1:
		//microphone = std::make_unique<Mono>();
		microphone = mono;
		break;
	case 2:
		microphone = stereo;
		break;
	default:
		microphone = stereo;
		break;
	}
	microphone->init();
}

void Receiver::process(AudioBuffer<float>& currentSample, AudioBuffer<float>& sourceBuffer, int sampleIndex, int maxIndex)
{
	currentSample.clear();

	microphone->process(inWaveguides, getPosition(), currentSample, sourceBuffer, sampleIndex, maxIndex);
}

void Receiver::updatePosition()
{
	setPosition(getSmoothedPos());
}

void Receiver::setOutputMode(int mode)
{

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
