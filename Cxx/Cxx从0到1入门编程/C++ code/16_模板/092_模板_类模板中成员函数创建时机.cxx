// 类模板中成员函数创建时机
// 类模板中成员函数在调用时才创建
#include <iostream>
using namespace std;

class Person1
{
    public:
        void showPerson1() { cout << "Person1 show." << endl;}
};

class Person2
{
    public:
        void showPerson2() { cout << "Person2 show." << endl;}
};

template<class T>
class MyClass
{
    public:
        T obj;
        // 类模板中的成员函数
        void fun1() {obj.showPerson1();} // 只有在调用时才会创建，因为不调用不知道数据类型T
        void fun2() {obj.showPerson2();}
};

void test1()
{
    MyClass<Person1> m;
    m.fun1(); // 可以调用
    // m.fun2(); // 不能运行，因为Peron1的类没有showPerson2成员函数
}

int main()
{
    test1();
    return 0;
}
