#pragma once
#include <iostream>
#include "PointClass.h"

using namespace std;

class Circle
{
private:
	int circleRadius;
	Point circleCenter;

public:
	void setRadius(int radius);
	int getRadius();
	void setCenter(Point center);
	Point getCenter();
};
