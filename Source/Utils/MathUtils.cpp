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
	float cRoll = cosf(eulerXYZ.z() * 0.5);
	float sRoll = sinf(eulerXYZ.z() * 0.5);
	float cPitch = cosf(eulerXYZ.x() * 0.5);
	float sPitch = sinf(eulerXYZ.x() * 0.5);
	float cYaw = cosf(-eulerXYZ.y() * 0.5);
	float sYaw = sinf(-eulerXYZ.y() * 0.5);

	float w = cPitch * cYaw * cRoll + sPitch * sYaw * sRoll;
	float x = sPitch * cYaw * cRoll - cPitch * sYaw * sRoll;
	float y = cPitch * sYaw * cRoll + sPitch * cYaw * sRoll;
	float z = cPitch * cYaw * sRoll - sPitch * sYaw * cRoll;

	return Quaternionf(w, x, y, z);
}