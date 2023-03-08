#include "NormalPosition.h"

NormalPosition::NormalPosition()
{
	normalPos = { 0, 0, 0 };
}


void NormalPosition::initRange(int samplerate, Point3d& startNormalPos, Point3d dimensions)
{
	int numSamples = samplerate * Parameters::SMOOTHING_TIME_SECONDS;
	smoothedX.reset(numSamples);
	smoothedY.reset(numSamples);
	smoothedZ.reset(numSamples);

	normalPos = startNormalPos;

	smoothedX.setCurrentAndTargetValue(normalPos.x * dimensions.x);
	smoothedY.setCurrentAndTargetValue(normalPos.y * dimensions.y);
	smoothedZ.setCurrentAndTargetValue(normalPos.z * dimensions.z);
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
