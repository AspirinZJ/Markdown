#include <iostream>

using namespace std;

class Base1
{
    public:
        Base1() {this->mA = 200;}
        int mA;
};

class Base2
{
    public:
        Base2() {this->mA = 434; this->mB = 200;}
        int mA;
        int mB;
};

// 子类，继承两个父类
class Son : public Base1, public Base2
{
    public:
        Son() {this->mC = 300; this->mD = 400;}
        int mC;
        int mD;
};

void test1()
{
    // 所有父类中的所有成员都会被继承，虽然private属性被编译器隐藏，但是也继承了
    cout << "size of son " << sizeof(Son) << endl; 
    Son son;
    // 访问同名成员属性，需要加作用域
    cout << son.Base1::mA << endl;
    cout << son.Base2::mA << endl;
}

int main()
{
    test1();
    return 0;
}
