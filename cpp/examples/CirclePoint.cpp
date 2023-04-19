#include <iostream>
#include <math.h>
#include "PointClass.h"
#include "CircleClass.h"

using namespace std;

void isPointInCircle(Circle& circle, Point& point)
{
	int squareDistance = pow(circle.getCenter().getPointX() - point.getPointX(), 2) +
		pow(circle.getCenter().getPointY() - point.getPointY(), 2);
	int squareRadius = pow(circle.getRadius(), 2);

	if (squareDistance > squareRadius)
	{
		cout << "The point is outside the circle" << endl;
	}
	else if (squareDistance < squareRadius)
	{
		cout << "The point is inside the circle" << endl;
	}
	else
	{
		cout << "The point is on the circle" << endl;
	}
}

int main()
{
	Point point;
	Point center;
	Circle circle;

	center.setPoint(10, 0);
	circle.setCenter(center);
	circle.setRadius(10);
	point.setPoint(10, 10);

	isPointInCircle(circle, point);

	system("pause");
	return 0;
}
