#pragma once
#include <iostream>

using namespace std;

class Point
{
private:
	int pointX;
	int pointY;

public:
	void setPoint(int x, int y);
	int getPointX();
	int getPointY();
};
