#include <iostream>
#include <string>
using namespace std;

class Base
{
    public:
        static int mA;
        static void func() {cout << "Calling Base func()." << endl;}
        static void func(string str) {cout << str << endl;} // 如果子类中出现和父类同名的成员函数，子类的成员函数会隐藏掉所有父类的同名成员函数，包括父类中重载的函数。如果想访问父类中的同名成员函数，需要加作用域
};

int Base::mA = 100;

class Son : public Base
{
    public:
        static int mA;
        static void func() {cout << "Calling Son func()." << endl;}
};

int Son::mA = 200;

void test1()
{
    // 同名静态成员属性
    // 1. 通过对象访问
    Son son;
    cout << son.mA << endl; // 直接访问，访问子类静态成员
    cout << son.Base::mA << endl; // 加作用域，访问父类同名静态成员
    // 2. 通过类名访问
    cout << Son::mA << endl; // 直接通过子类访问子类同名静态成员
    cout << Base::mA << " or "<< Son::Base::mA << endl; // 加作用域访问父类同名静态成员Son::Base::mA, 第一个::表示通过类名的方式访问静态成员，第二个::表示访问父类作用域下的静态成员
}

void test2()
{
    // 同名静态成员函数
    Son son;
    // 1. 通过对象访问
    son.func();
    son.Base::func();
    // 2. 通过类名访问
    Son::func();
    Base::func(); Son::Base::func();

    // 如果子类中出现和父类同名的成员函数，子类的成员函数会隐藏掉所有父类的同名成员函数，包括父类中重载的函数。如果想访问父类中的同名成员函数，需要加作用域
    Son::Base::func("ABC.");
}

int main()
{
    test1();
    test2();
    return 0;
}
