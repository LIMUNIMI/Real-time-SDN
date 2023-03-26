#pragma once

#include <Eigen/Geometry>
#include "MathUtils.h"
#include <Parameters.h>

//handles rotation for any node object, Y-up left handed system
class NodeRotation
{
public:

	NodeRotation();
	~NodeRotation() {};

	void init(double samplerate);

	//change current xyz rotation
	void setRotation(float newValue, const char axis);
	//set target rotation quaternion to current xyz rotation
	void updateQuaternion();

	bool isRotating() { return interpolationIndex <= smoothingDuration; };

protected:
	
	//updates currentRotation to interpolation point (interpolationIndex/smoothingDuration) between prevRotation and targetRotation
	void interpolateQuaternions();

	Eigen::Quaternionf prevRotation, targetRotation;
	Eigen::Matrix3f currentRotation;
	Eigen::Vector3f xyzRotation;

	int smoothingDuration = 0;
	int interpolationIndex = 0;

private:

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(NodeRotation);

};