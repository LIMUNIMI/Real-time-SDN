#pragma once
#include "Point3d.h"
#include <JuceHeader.h>

//virtual class for all objects with a position
class Node
{
public:

	void setPosition(Point3d newPos) { position = newPos; };
	void setX(float newPos) { position.x = newPos; };
	void setY(float newPos) { position.y = newPos; };
	void setZ(float newPos) { position.z = newPos; };
	Point3d& getPosition() { return position; };

	virtual ~Node() = default;

private:

	Point3d position = {0, 0, 0};

};

