#include "Listener.h"

Listener::Listener(Point3d position, int nChannels, int numSamples)
{
	setPosition(position);
	newBuffer(nChannels, numSamples);
	cleanBuffer();
}

Listener::Listener()
{
	setPosition({ 0, 0, 0 });
	newBuffer(0, 0);
}