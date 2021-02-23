// 点和圆的关系，点在圆的内部，边缘，外部
#include <iostream>
#include <cmath>
#include "point.h"
#include "circle.h"

using namespace std;

void isPointInCircle(Point &p, Circle &c)
{
	float dis = pow((c.getCenter().getX() - p.getX()), 2) + pow((c.getCenter().getY() - p.getY()), 2);
	if (dis > pow(c.getRadius(), 2))	{cout << "Point is outside of Circle." << endl;}
	else if(dis == pow(c.getRadius(), 2))	{cout << "Point is on Circle." << endl;}
	else	{cout << "Point is within the Circle." << endl;}
}

int main(int argc, char **argv)
{
	Point point1;
	point1.setX(10);
	point1.setY(10);

	Point center1;
	center1.setX(1);
	center1.setY(2);

	Circle circle1;
	circle1.setCenter(center1);
	circle1.setRadius(50);

	isPointInCircle(point1, circle1);
    return 0;
}
