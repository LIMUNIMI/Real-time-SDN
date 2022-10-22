#pragma once
#include "Point3d.h"
#include <JuceHeader.h>

class Node
{
public:

	void setPosition(Point3d newPos) { position = newPos; };
	Point3d getPosition() { return position; };

	virtual void addToBuffer(AudioBuffer<float>& inWave) = 0;

	virtual ~Node() = default;

private:
	Point3d position;

};

