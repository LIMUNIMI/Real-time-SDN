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

float MathUtils::distanceCalc(Point3d& startPos, Point3d& endPos)
{
	float distance = sqrtf(powf((startPos.x - endPos.x), 2) + powf((startPos.y - endPos.y), 2)
		+ powf((startPos.z - endPos.z), 2));

	if (distance < 1) distance = 1.0f;

	return distance;
}


Quaternionf MathUtils::eulerXYZ_to_Quaternion(Vector3f eulerXYZ)
{
	float cr = cosf(eulerXYZ.z() * 0.5);
	float sr = sinf(eulerXYZ.z() * 0.5);
	float cp = cosf(eulerXYZ.x() * 0.5);
	float sp = sinf(eulerXYZ.x() * 0.5);
	float cy = cosf(eulerXYZ.y() * 0.5);
	float sy = sinf(eulerXYZ.y() * 0.5);

	float w = cp * cy * cr + sp * sy * sr;
	float x = sp * cy * cr - cp * sy * sr;
	float y = cp * sy * cr + sp * cy * sr;
	float z = cp * cy * sr - sp * sy * cr;

	return Quaternionf(w, x, y, z);
}