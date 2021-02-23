#include <iostream>
#include <string>

using namespace std;

class Base
{
    public:
        Base() {this->mA = 10;}
        void func() {cout << "Calling Base func." << endl;}
        void func(string str) {cout << str << endl;}
        int mA;
};

class Son : public Base
{
    public:
        Son() { this->Base::mA = 50; this->mA = 20;}
        void func() {cout << "Calling Son func." << endl;}
        int mA;
};

void test1()
{
    Son s;
    cout << "Son.mA: " << s.mA << endl; // 直接访问就是子类成员属性
    cout << "Base.mA: " << s.Base::mA << endl; // 加入作用域访问父类同名成员属性
}

void test2()
{
    // 同名成员函数处理方式
    Son s;
    s.func(); // 直接调用，调用的是子类中的同名成员函数
    s.Base::func();     // 加入作用域访问父类同名成员函数
    // s.func("ABC."); // 如果子类中出现和父类同名的成员函数，子类的成员函数会隐藏掉×所有×父类中的成员函数,包括重载版本
    s.Base::func("ABC.");
}

int main()
{
    test1();
    test2();
    return 0;
}
