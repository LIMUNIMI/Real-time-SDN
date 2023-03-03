#pragma once

#include <Eigen/Geometry>
#include "MathUtils.h"

class NodeRotation
{
public:

	NodeRotation();
	~NodeRotation() {};

	void init();

	void setRotation(float newValue, const char axis);
	void updateQuaternion();
	void sync();

protected:

	Eigen::Quaternionf prevRotation, targetRotation;
	Eigen::Matrix3f currentRotation;
	Eigen::Vector3f xyzRotation;

private:

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(NodeRotation);

};