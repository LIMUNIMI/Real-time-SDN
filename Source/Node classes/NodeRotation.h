#pragma once

#include <Eigen/Geometry>
#include "MathUtils.h"

//handles rotation for any node object, Y-up left handed system
class NodeRotation
{
public:

	NodeRotation();
	~NodeRotation() {};

	void init();

	//change current xyz rotation
	void setRotation(float newValue, const char axis);
	//set target rotation quaternion to current xyz rotation
	void updateQuaternion();
	//set current rotation quaternion to target rotation
	void sync();

protected:

	Eigen::Quaternionf prevRotation, targetRotation;
	Eigen::Matrix3f currentRotation;
	Eigen::Vector3f xyzRotation;

private:

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(NodeRotation);

};