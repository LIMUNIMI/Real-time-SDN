#pragma once
#include <Point3d.h>
#include <JuceHeader.h>

namespace MathUtils
{
	Point3d dirVector(Point3d& a, Point3d& b);

	Point3d reflectionPoint(Point3d a, Point3d b, char reflAxis, float wallPosition);

	float magnitude(Point3d vector);

	float distanceCalc(Point3d& vector);

	float distanceCalc(Point3d& startPos, Point3d& endPos);

	Point3d crossProduct(Point3d& vector1, Point3d& vector2);

	float sinOfVectorsAngle(Point3d vector1, Point3d vector2);

	float sinOfAzimuth(Point3d vector1, Point3d vector2);

}