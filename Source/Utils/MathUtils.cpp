#include "MathUtils.h"

Point3d MathUtils::dirVector(Point3d& a, Point3d& b)
{
	return { a.x - b.x, a.y - b.y, a.z - b.z };
}

Point3d MathUtils::reflectionPoint(Point3d a, Point3d b, char reflAxis, float wallPosition)
{
	Point3d direction;
	float positionParam;

	switch (reflAxis)
	{
	case 'x':
		a.x = (2 * wallPosition) - a.x;
		direction = MathUtils::dirVector(a, b);
		positionParam = (wallPosition - a.x) / direction.x;
		return { wallPosition, a.y + direction.y * positionParam, a.z + direction.z * positionParam };
		break;

	case 'y':
		a.y = (2 * wallPosition) - a.y;
		direction = MathUtils::dirVector(a, b);
		positionParam = (wallPosition - a.y) / direction.y;
		return { a.x + direction.x * positionParam, wallPosition, a.z + direction.z * positionParam };
		break;

	case 'z':
		a.z = (2 * wallPosition) - a.z;
		direction = MathUtils::dirVector(a, b);
		positionParam = (wallPosition - a.z) / direction.z;
		return { a.x + direction.x * positionParam, a.y + direction.y * positionParam, wallPosition };
		break;
	}

	return { 0, 0, 0 };

}

float MathUtils::magnitude(Point3d vector)
{
	float magnitude = sqrt(powf(vector.x, 2) + powf(vector.y, 2)
		+ powf(vector.z, 2));

	return magnitude;
}

float MathUtils::distanceCalc(Point3d& vector)
{
	float dist = MathUtils::magnitude(vector);
	return dist < 1 ? 1.0f : dist;
}

float MathUtils::distanceCalc(Point3d& startPos, Point3d& endPos)
{
	float distance = sqrtf(powf((startPos.x - endPos.x), 2) + powf((startPos.y - endPos.y), 2)
		+ powf((startPos.z - endPos.z), 2));

	if (distance < 1) distance = 1.0f;

	return distance;
}

Point3d MathUtils::crossProduct(Point3d& vector1, Point3d& vector2)
{
	float x, y, z;
	x = vector1.y * vector2.z - vector1.z * vector2.y;
	y = -(vector1.x * vector2.z - vector1.z * vector2.x);
	z = vector1.x * vector2.y - vector1.y * vector2.x;

	return { x, y, z };
}

float MathUtils::sinOfVectorsAngle(Point3d vector1, Point3d vector2)
{
	float numerator = MathUtils::magnitude(MathUtils::crossProduct(vector1, vector2));
	float denum = MathUtils::magnitude(vector1) * MathUtils::magnitude(vector2);

	return numerator / denum;
}

float MathUtils::sinOfAzimuth(Point3d vector1, Point3d vector2)
{
	return sinOfVectorsAngle({ vector1.x, 0 , vector1.z }, { vector2.x, 0 , vector2.z });
}
