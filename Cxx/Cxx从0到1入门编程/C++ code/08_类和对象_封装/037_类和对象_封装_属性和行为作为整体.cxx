// 设计圆类，求圆的周长
#include <iostream>

using namespace std;

const float pi = 3.14;

class Circle
{
    // 访问权限： 属性/行为;
    public:
        // 属性
        double radius;

        // 行为
        double calCircumference()
        {
            return 2 * pi * radius;
        }
};

int main(int argc, char **argv)
{
    Circle circle1;
    circle1.radius = 10.0;
    cout << "The circumference of the circle is: " << circle1.calCircumference() << endl;
    return 0;
}
