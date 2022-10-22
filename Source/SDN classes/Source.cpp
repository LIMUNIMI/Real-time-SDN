#include "Source.h"

void Source::init(Point3d position, int nChannels, int bufferSize)
{
	setPosition(position);
	numChannels = nChannels;
	this->bufferSize = bufferSize;
}

Source::Source()
{
	setPosition({0, 0, 0});
	numChannels = 0;
	bufferSize = 0;
}