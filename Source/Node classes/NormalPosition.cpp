#include "NormalPosition.h"

NormalPosition::NormalPosition()
{
	normalPos = { 0, 0, 0 };
}


void NormalPosition::initRange(int numSamples, Point3d& startPos)
{
	smoothedX.reset(numSamples);
	smoothedY.reset(numSamples);
	smoothedZ.reset(numSamples);

	smoothedX.setCurrentAndTargetValue(startPos.x);
	smoothedY.setCurrentAndTargetValue(startPos.y);
	smoothedZ.setCurrentAndTargetValue(startPos.z);
}

void NormalPosition::scaleToDim(float newValue, const char& axis)
{

	switch (axis)
	{
	case 'x':
		smoothedX.setCurrentAndTargetValue(normalPos.x * newValue);
		break;
	case 'y':
		smoothedY.setCurrentAndTargetValue(normalPos.y * newValue);
		break;
	case 'z':
		smoothedZ.setCurrentAndTargetValue(normalPos.z * newValue);
		break;
	default:
		break;
	}

}

void NormalPosition::setNormalPos(float newPos, Point3d& dimensions, const char& axis)
{

	switch (axis)
	{
	case 'x':
		smoothedX.setTargetValue(newPos * dimensions.x);
		normalPos.x = newPos;
		break;
	case 'y':
		smoothedY.setTargetValue(newPos * dimensions.y);
		normalPos.y = newPos;
		break;
	case 'z':
		smoothedZ.setTargetValue(newPos * dimensions.z);
		normalPos.z = newPos;
		break;
	default:
		break;
	}

}
