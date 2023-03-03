#include "NodeRotation.h"

using namespace Eigen;

NodeRotation::NodeRotation()
{
	xyzRotation = Vector3f(0, 0, 0);
	prevRotation = MathUtils::eulerXYZ_to_Quaternion(xyzRotation);
	currentRotation = MathUtils::eulerXYZ_to_Quaternion(xyzRotation);
	targetRotation = MathUtils::eulerXYZ_to_Quaternion(xyzRotation);
}

void NodeRotation::init()
{
	xyzRotation = Vector3f(0, 0, 0);
	prevRotation = MathUtils::eulerXYZ_to_Quaternion(xyzRotation);
	currentRotation = MathUtils::eulerXYZ_to_Quaternion(xyzRotation);
	targetRotation = MathUtils::eulerXYZ_to_Quaternion(xyzRotation);
}

void NodeRotation::setRotation(float newValue, const char axis)
{

	switch (axis)
	{
	case 'x':
		xyzRotation.x() = newValue;
		break;
	case 'y':
		xyzRotation.y() = newValue;
		break;
	case 'z':
		xyzRotation.z() = newValue;
		break;
	}

}

void NodeRotation::updateQuaternion()
{
	targetRotation = MathUtils::eulerXYZ_to_Quaternion(xyzRotation);
}

void NodeRotation::sync()
{
	if (prevRotation != targetRotation) prevRotation = targetRotation;
}