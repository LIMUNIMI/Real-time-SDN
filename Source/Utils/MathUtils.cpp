#include "MathUtils.h"

using namespace Eigen;

Vector3f MathUtils::dirVector(Point3d& a, Point3d& b)
{
	return Vector3f( a.x - b.x, a.y - b.y, a.z - b.z );
}

Point3d MathUtils::reflectionPoint(Point3d a, Point3d b, char reflAxis, float wallPosition)
{
	Vector3f direction;
	float positionParam;

	switch (reflAxis)
	{
	case 'x':
		a.x = (2 * wallPosition) - a.x;
		direction = MathUtils::dirVector(a, b);
		positionParam = (wallPosition - a.x) / direction.x();
		return { wallPosition, a.y + direction.y() * positionParam, a.z + direction.z() * positionParam };
		break;

	case 'y':
		a.y = (2 * wallPosition) - a.y;
		direction = MathUtils::dirVector(a, b);
		positionParam = (wallPosition - a.y) / direction.y();
		return { a.x + direction.x() * positionParam, wallPosition, a.z + direction.z() * positionParam };
		break;

	case 'z':
		a.z = (2 * wallPosition) - a.z;
		direction = MathUtils::dirVector(a, b);
		positionParam = (wallPosition - a.z) / direction.z();
		return { a.x + direction.x() * positionParam, a.y + direction.y() * positionParam, wallPosition };
		break;
	}

	return { 0, 0, 0 };

}

//float MathUtils::magnitude(Point3d vector)
//{
//	float magnitude = sqrt(powf(vector.x, 2) + powf(vector.y, 2)
//		+ powf(vector.z, 2));
//
//	return magnitude;
//}
//
//float MathUtils::distanceCalc(Point3d& vector)
//{
//	float dist = MathUtils::magnitude(vector);
//	return dist < 1 ? 1.0f : dist;
//}

float MathUtils::distanceCalc(Point3d& startPos, Point3d& endPos)
{
	float distance = sqrtf(powf((startPos.x - endPos.x), 2) + powf((startPos.y - endPos.y), 2)
		+ powf((startPos.z - endPos.z), 2));

	if (distance < 1) distance = 1.0f;

	return distance;
}

//Point3d MathUtils::crossProduct(Vector3f& vector1, Vector3f& vector2)
//{
//	float x, y, z;
//	x = vector1.y() * vector2.z() - vector1.z() * vector2.y();
//	y = -(vector1.x() * vector2.z() - vector1.z() * vector2.x());
//	z = vector1.x() * vector2.y() - vector1.y() * vector2.x();
//
//	return { x, y, z };
//}

float MathUtils::sinOfVectorsAngle(Vector3f vector1, Vector3f vector2)
{
	float numerator = (vector1.cross(vector2)).norm();
	float denum = vector1.norm() * vector2.norm();

	return numerator / denum;
}

float MathUtils::sinOfAzimuth(Vector3f vector1, Vector3f vector2)
{
	return sinOfVectorsAngle(Vector3f( vector1.x(), 0, vector1.z()), Vector3f(vector2.x(), 0, vector2.z()));
}


Quaternionf MathUtils::eulerXYZ_to_Quaternion(Vector3f eulerXYZ)
{
	double cr = cos(eulerXYZ.z() * 0.5);
	double sr = sin(eulerXYZ.z() * 0.5);
	double cp = cos(eulerXYZ.x() * 0.5);
	double sp = sin(eulerXYZ.x() * 0.5);
	double cy = cos(eulerXYZ.y() * 0.5);
	double sy = sin(eulerXYZ.y() * 0.5);

	float w = cp * cy * cr + sp * sy * sr;
	float x = sp * cy * cr - cp * sy * sr;
	float y = cp * sy * cr + sp * cy * sr;
	float z = cp * cy * sr - sp * sy * cr;

	return Quaternionf(w, x, y, z);
}