#pragma once
#include <Point3d.h>
#include <JuceHeader.h>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Geometry>

#define DEG2RAD(x) (x * MathConstants<float>::pi / 180.0f)
#define RAD2DEG(x) (x * 180.0f / MathConstants<float>::pi)

namespace MathUtils
{
	Eigen::Vector3f dirVector(Point3d& a, Point3d& b);

	Point3d reflectionPoint(Point3d a, Point3d b, char reflAxis, float wallPosition);

	//float magnitude(Point3d vector);

	//float distanceCalc(Point3d& vector);

	float distanceCalc(Point3d& startPos, Point3d& endPos);

	//Point3d crossProduct(Eigen::Vector3f& vector1, Eigen::Vector3f& vector2);

	float sinOfVectorsAngle(Eigen::Vector3f vector1, Eigen::Vector3f vector2);

	float sinOfAzimuth(Eigen::Vector3f vector1, Eigen::Vector3f vector2);

	Eigen::Quaternionf eulerXYZ_to_Quaternion(Eigen::Vector3f eulerXYZ);

}