#include <iostream>

using namespace std;

class Person
{
    // 构造函数
    // 没有返回值，不写void
    // 函数名于类名相同
    // 可以有参数，可以发生重载
    // 在创建对象时，构造函数会自动调用，无需手动调用，而且只会调用一次
    public:
        Person()    {cout << "Creating Person object." << endl;}
        // 析构函数
        // 没有返回值，不写void
        // 函数名为～类名
        // 不可以有参数，不可发生重载
        // 在销毁对象时，系统自动调用，无需手动调用，而且只调用一次
        ~Person()   {cout << "Destroying Person object" << endl;}
};

void test1()    {Person person1;} // 在栈上的数据，在执行完test1后，自动释放这个对象

int main()
{
    test1(); // 在栈上的数据，在执行完test1后，自动释放这个对象
    return 0;
}
