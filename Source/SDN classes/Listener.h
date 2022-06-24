#pragma once
#include "Point3d.h"
#include "HasBuffer.h"

class Listener : public HasBuffer
{
public:
	Listener();
	Listener(Point3d position, int nChannels, int numSamples);
};

