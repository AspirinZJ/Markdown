// 左移运算符重载
#include <iostream>
using namespace std;

class Person
{
    friend ostream &operator<<(ostream &cout, Person &p);
    public:
    Person(int a, int b) : mA(a), mB(b){}
    private:
        // 通常不会利用成员函数重载左移运算符，因为无法实现cout在左侧像cout << person;
        int mA;
        int mB;
};

ostream &operator<<(ostream &cout, Person &p) // 本质operator<<(cout, p), 这样就可以cout << p;
{
    cout << "mA = " << p.mA << ". mB = " << p.mB;
    return cout;
}

void test1()
{
    Person person(10, 10);
    cout << person << endl;
}

int main()
{
    test1();
    return 0;
}
