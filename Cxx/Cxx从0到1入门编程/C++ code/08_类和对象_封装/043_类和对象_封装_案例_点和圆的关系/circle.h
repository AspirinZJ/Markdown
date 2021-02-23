#pragma once
#include <iostream>
#include "point.h"

using namespace std;

class Circle
{
private:
	float mRadius;
	Point mCenter;
public:
	void setRadius(float r);
	void setCenter(Point &center);
	float getRadius();
	Point getCenter();
};
