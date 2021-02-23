// 加号运算符重载
// 运算符重载，也可以发生函数重载
#include <iostream>
using namespace std;

class Person
{
    public:
        Person() {}
        Person(int a, int b) : m_A(a), m_B(b) {}
        // 1. 通过成员函数重载+运算符
        Person operator+(Person &person)
        {
            Person tmp;
            tmp.m_A = this->m_A + person.m_A;
            tmp.m_B = this->m_B + person.m_B;
            return tmp;
        }
        
        // 运算符重载，也可以发生函数重载
        Person operator+(int a)
        {
            Person tmp;
            tmp.m_A = this->m_A + a;
            tmp.m_B = this->m_B;
            return tmp;
        }
    public:
        int m_A;
        int m_B;
};

// 2. 通过全局函数重载+运算符
// Person operator+(Person &p1, Person &p2)
// {
//     Person tmp;
//     tmp.m_A = p1.m_A + p2.m_A;
//     tmp.m_B = p1.m_B + p2.m_B;
//     return tmp;
// }


void test1()
{
    Person person1(10, 20);
    Person person2 = Person(20, 30);
    Person person3 = person1 + person2;
    // 成员函数重载的本质调用
    // 本质上和下面这行话作用相同，把operator+看作一个成员函数名
    person3 = person1.operator+(person2);
    // 全局函数重载的本质调用
    // person3 = operator+(person1, person2); 把operator+看作一个全局函数名
    cout << person3.m_A << endl << person3.m_B << endl;
    Person person4 = person1 + 100;
    cout << person4.m_A << endl << person4.m_B << endl;
}

int main()
{
    test1();
    return 0;
}
