#pragma once
#include <Point3d.h>
#include <JuceHeader.h>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Geometry>

#define DEG2RAD(x) (x * MathConstants<float>::pi / 180.0f)
#define RAD2DEG(x) (x * 180.0f / MathConstants<float>::pi)

//Namespace with some generic math functions
namespace MathUtils
{	
	//returns vector from point a to point b
	Eigen::Vector3f dirVector(Point3d& a, Point3d& b);

	//return point of specular reflection between a and b on the wall aligned with reflAxis at distance WallPosition
	Point3d reflectionPoint(Point3d a, Point3d b, char reflAxis, float wallPosition);

	float distanceCalc(Point3d& startPos, Point3d& endPos);

	//Convert euler angle in XYZ coordinates to a quaternion (uses Y-up left hand convention)
	Eigen::Quaternionf eulerXYZ_to_Quaternion(Eigen::Vector3f eulerXYZ);

}