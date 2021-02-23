#include <iostream>
using namespace std;

class Person
{
    public:
        Person() : mA(10), mB(20), mC(30){} // 初始化列表赋初值
        Person(int a, int b, int c) : mA(a), mB(b), mC(c) {} // 初始化列表赋初值
        int mA;
        int mB;
        int mC;
};

void test1()
{
    Person person1(1, 2, 3); 
    cout << person1.mA << person1.mB << person1.mC << endl;
    Person person2; // 初始化列表赋初值
    cout << person2.mA << person2.mB << person2.mC << endl;
}

int main()
{
    test1();
    return 0;
}
