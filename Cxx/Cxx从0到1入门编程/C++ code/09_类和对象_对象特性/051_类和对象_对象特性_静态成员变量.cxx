// 静态成员变量：
// 所有对象共享同一份数据
// 在编译阶段分配内存的全局区
// 类内声明，类外初始化
#include <iostream>
using namespace std;

class Person
{
    public:
        static int mA; // 所有对象共享同一份数据，编译阶段分配内存，类内声明，类外初始化

    // 静态成员变量也是有访问权限的
    private:
        static int mB;
};

//静态成员类外初始化
int Person::mA = 100;
int Person::mB = 50; // private权限类外无法访问

void test1()
{
    Person person;
    cout << person.mA << endl;
    Person person2;
    person2.mA = 200; // 所有对象共享同一份数据
    cout << person.mA << endl;
}

void test2()
{
    // 静态成员变量不属于某个对象，因为所有对象共享同一份数据
    // 因此静态成员变量有两种访问方式
    // 1. 通过对象进行访问
    // 2. 通过类名进行访问
    cout << Person::mA << endl;
    // cout << Person::mB << endl; // private权限类外无法访问
}

int main()
{
    test1();
    test2();
    return 0;
}
