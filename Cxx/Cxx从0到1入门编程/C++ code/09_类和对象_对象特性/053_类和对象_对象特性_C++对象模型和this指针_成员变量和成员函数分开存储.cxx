// 成员变量和成员函数分开存储
#include <iostream>
using namespace std;

class Person
{};

class Person2
{
    public:
        int mA; // 非静态成员变量，属于类的对象上
        static int mB; //静态成员变量，不属于类的对象上
        void func() {} // 非静态成员函数, 不属于类的对象上
        static void func2() {} // 静态成员函数，不属于类的对象上
};

int Person2::mB = 10;

void test1()
{
    Person person;
    // 空对象占用的内存空间为: 1, C++编译器会给每个空对象分配一个字节空间，是为了区分空对象占内存的位置
    // 每个空对象也有单独的内存地址
    cout << "Size of person: " << sizeof(person) << endl;
}

void test2()
{
    Person2 person2;
    cout << "Size of person2: " << sizeof(person2) << endl;
}

int main()
{
    test1();
    test2();
    return 0;
}
