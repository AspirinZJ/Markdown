#pragma once
#include <iostream>
using namespace std;

class Point
{
private:
	float mX;
	float mY;
public:
	void setX(float x);
	void setY(float y);
	float getX();
	float getY();
};
