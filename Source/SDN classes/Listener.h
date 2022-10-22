#pragma once
#include "Point3d.h"
#include "HasBuffer.h"

class Listener : public HasBuffer
{
public:

	Listener();
	~Listener() {};
	void init(Point3d position, int nChannels, int numSamples);

	Point3d forward = {0, 0, -1};

private:

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Listener);

};

