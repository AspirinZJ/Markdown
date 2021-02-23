#include <iostream>
using namespace std;

class Person
{
    public:
        Person(int a, int b) {this->m_A = a; this->m_B = b;}
        void showPerson() const  // 常函数
        {
            cout << "Person class." << endl;
            // 常函数不可以修改成员属性
            // m_A = 10; // 报错，这里面的this指针相当于const Person * const this;
            m_B = 10;  // 但是，常函数可以修改mutable修饰的成员属性
        }

        void func() {} // 不能被常对象调用
        int m_A;
        mutable int m_B; // 可以被常函数修改
};

void test1()
{
    Person person1(10, 20);
    person1.showPerson();
}

void test2()
{
    const Person person(20, 20); // 常对象
    // person.m_A = 100; // 常对象不能修改成员
    person.m_B = 100; // 常对象可以修改mutable修饰的成员
    person.showPerson();
    // person.func(); // 常对象只能调用常函数
}

int main()
{
    test1();
    return 0;
}
