#include "CircleClass.h"

void Circle::setRadius(int radius)
{
	circleRadius = radius;
}

int Circle::getRadius()
{
	return circleRadius;
}

void Circle::setCenter(Point center)
{
	circleCenter = center;
}

Point Circle::getCenter()
{
	return circleCenter;
}
