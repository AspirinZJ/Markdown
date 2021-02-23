// 继承中的构造和析构顺序
#include <iostream>
using namespace std;

class Base
{
    public:
        Base() {cout << "Base Constructor." << endl;}
        ~Base() {cout << "Base Destructor." << endl;}
};

class Son : public Base
{
    public:
        Son() {cout << "Son Constructor." << endl;}
        ~Son() {cout << "Son Destructor." << endl;}
};

void test1()
{
    Son son;
}

int main()
{
    test1();
    return 0;
}
