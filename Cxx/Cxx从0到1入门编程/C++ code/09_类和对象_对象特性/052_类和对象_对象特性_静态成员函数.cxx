// 静态成员函数
// 所有对象共享同一个函数
// 静态成员函数只能访问静态成员变量
#include <iostream>
using namespace std;

class Person
{
    public:
        static void func()  
        {
            mA = 10; // 静态成员函数只能访问静态成员变量
            // mB = 10; // 静态成员函数不可以访问非静态成员变量
            cout << "static function" << endl;
        } 
        static int mA;
        int mB;

    //  静态成员函数也是有访问权限
    private:
        static void func2() {cout << "static function2." << endl;}
};

int Person::mA = 0;

void test1()
{
    //1. 通过对象访问静态成员函数
    // Person person;
    // person.func();
    //2. 通过类名访问静态成员函数
    Person::func();
    // Person::func2(); // 类外不能访问私有静态成员函数
}

int main()
{
    test1();
    return 0;
}
