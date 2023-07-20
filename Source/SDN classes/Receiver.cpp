#include "Receiver.h"

using namespace Eigen;

Receiver::Receiver()
{
	setPosition({ 0, 0, 0 });
	mono = std::make_shared<Mono>();
	stereo = std::make_shared<Stereo>();
	ambisonic = std::make_shared<Ambisonic>();
#ifdef _BRT_LIBRARY_
	hrtf = std::make_shared<HRTF_output>();
#endif
	microphone = stereo;
}

void Receiver::init(Point3d normalPosition, int numsamples, int nOfConnections, double samplerate, Point3d dimensions)
{
	initRange(samplerate, normalPosition, dimensions);
	NodeRotation::init(samplerate);
	
	setPosition(getSmoothedPos());
	inWaveguides = std::vector<WaveGuide*>(nOfConnections, 0);

	setOutputMode(outModeIndex);
	mono->init();
	stereo->init(samplerate);
	ambisonic->init();
#ifdef _BRT_LIBRARY_
	hrtf->init(samplerate, numsamples);
#endif
}

void Receiver::process(AudioBuffer<float>& sourceBuffer, int sampleIndex, int maxIndex, bool hasChanged)
{
	interpolateQuaternions();
	microphone->process(inWaveguides, getPosition(), currentRotation, sourceBuffer, 
		sampleIndex, maxIndex, hasChanged, isRotating());
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
#ifdef _BRT_LIBRARY_
	else if (mode == 2)
	{
		microphone = hrtf;
	}
	else if (mode > 2 )
	{
		microphone = ambisonic;
		ambisonic->setAmbisonicOrder(mode - 2);
	}
#else
	else if (mode > 1)
	{
		microphone = ambisonic;
		ambisonic->setAmbisonicOrder(mode - 1);
	}
#endif
	
}
