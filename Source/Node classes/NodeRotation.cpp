#include "NodeRotation.h"

using namespace Eigen;

NodeRotation::NodeRotation() :
	xyzRotation(Vector3f(0, 0, 0))
{
	prevRotation = MathUtils::eulerXYZ_to_Quaternion(xyzRotation);
	currentRotation = MathUtils::eulerXYZ_to_Quaternion(xyzRotation);
	targetRotation = MathUtils::eulerXYZ_to_Quaternion(xyzRotation);
}

void NodeRotation::init(double samplerate)
{
	xyzRotation = Vector3f(0, 0, 0);
	prevRotation = MathUtils::eulerXYZ_to_Quaternion(xyzRotation);
	currentRotation = MathUtils::eulerXYZ_to_Quaternion(xyzRotation);
	targetRotation = MathUtils::eulerXYZ_to_Quaternion(xyzRotation);

	smoothingDuration = samplerate * Parameters::SMOOTHING_TIME_SECONDS;
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
	prevRotation = currentRotation;
	targetRotation = MathUtils::eulerXYZ_to_Quaternion(xyzRotation);
	interpolationIndex = 0;
}

void NodeRotation::sync()
{
	if (prevRotation != targetRotation)
	{
		prevRotation = targetRotation;
		currentRotation = targetRotation.normalized();
		interpolationIndex = smoothingDuration + 1;
	}
}

void NodeRotation::interpolateQuaternions()
{
	if (interpolationIndex <= smoothingDuration)
	{
		currentRotation = prevRotation.slerp((float)interpolationIndex / (float)smoothingDuration, targetRotation).normalized();
		interpolationIndex++;
	}
}

