// 继承中的对象模型
#include <iostream>
using namespace std;

class Base
{
    public:
        int mA;
    protected:
        int mB;
    private:
        int mC;
};

class Son : public Base
{
    public:
        int mD;
};

void test1()
{
    cout << "Size of Son: " << sizeof(Son) << endl; // 16
    // 父类中所有的非静态成员属性都会被子类继承
    // 父类中私有成员属性，被编译器隐藏，但是确实被继承
}

int main()
{
    test1();
    return 0;
}
