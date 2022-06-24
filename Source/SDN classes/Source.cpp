#include "Source.h"


Source::Source(Point3d position) 
{
	setPosition(position);
	numChannels = 0;
	bufferSize = 0;
}

Source::Source(Point3d position, int nChannels, int bufferS)
{
	setPosition(position);
	numChannels = nChannels;
	bufferSize = bufferS;
}

Source::Source()
{
	setPosition({0, 0, 0});
	numChannels = 0;
	bufferSize = 0;
}