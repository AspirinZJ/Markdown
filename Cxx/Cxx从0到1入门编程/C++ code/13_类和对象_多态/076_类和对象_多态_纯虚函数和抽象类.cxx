#include <iostream>
using namespace std;

// 纯虚函数和抽象类
class Base // 只要类中有一个纯虚函数，这个类就是抽象类
{
    public:
        virtual void func() = 0; // 纯虚函数
};

// 抽象类的子类必须重写父类中的纯虚函数，否则子类也是抽象类
class Son : public Base
{
    public:
        virtual void func() {cout << "Calling Son::func(). " << endl;}
};

void test1()
{
    // Base base; // 抽象类无法实例化对象
    // Base *p = new Base; // 抽象类无法实例化对象
    Base *pBase = new Son; // 多态，父类指针接收子类对象
    pBase->func();
    delete pBase;
}

int main()
{
    test1();
    return 0;
}
