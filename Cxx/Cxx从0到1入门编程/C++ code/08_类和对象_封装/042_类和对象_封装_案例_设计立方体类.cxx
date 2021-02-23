// 设计立方体类
// 1. 求出立方体面积和体积
// 2. 分别用全局函数和成员函数判断两个立方体是否相等
#include <iostream>

using namespace std;

// 创建立方体类
class Cube
{
    private:
        float mLength;
        float mWidth;
        float mHeight;

    public:
        void setLength(float length)
        {
            mLength = length;
        }

        float getLength()
        {
            return mLength;
        }

        void setHeight(float height)
        {
            mHeight = height;
        }

        float getHeight()
        {
            return mHeight;
        }

        void setWidth(float width)
        {
            mWidth= width;
        }

        float getWidth()
        {
            return mWidth;
        }

        float calArea()
        {
            return 2*(mLength * mHeight + mLength * mWidth + mHeight * mWidth);
        }

        float calVolume()
        {
            return mLength * mHeight * mWidth;
        }

        bool isCubeSame(Cube &c)
        {
    if (c.getLength() == getLength() && c.getHeight() == getHeight() && c.getWidth() == getWidth())
    {
        cout << "They are equal." << endl;
        return true;
    }
    else
    {
        cout << "They are not equal. " << endl;
        return false;
    }
        }
};

// 利用全局函数判断两个立方体是否相等
bool isSame(Cube &c1, Cube &c2)
{
    if (c1.getLength() == c2.getLength() && c1.getHeight() == c2.getHeight() && c1.getWidth() == c2.getWidth())
    {
        cout << "They are equal." << endl;
        return true;
    }
    else
    {
        cout << "They are not equal. " << endl;
        return false;
    }
}

int main()
{
    Cube cube1;
    cube1.setLength(2.0);
    cube1.setWidth(1.0);
    cube1.setHeight(3.0);

    float area = cube1.calArea();
    float volume = cube1.calVolume();

    cout << "Area: " << area << ". Volume: " << volume << endl;

    Cube cube2;
    cube2.setLength(2.0);
    cube2.setWidth(1.0);
    cube2.setHeight(4.0);
    isSame(cube1, cube2);

    cube1.isCubeSame(cube2);

    return 0;
}
