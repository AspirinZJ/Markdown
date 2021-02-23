// 继承
#include <iostream>
using namespace std;

// 公共页面类
class Base 
{
    public:
        void header()   {cout << "Header." << endl;}
        void footer()   {cout << "Footer." << endl;}
        void left()     {cout << "Left." << endl;}
};

// Java页面
class Java: public Base
{
    public:
    void content()  {cout << "Java content." << endl;}
};

// C++页面
class CPP: public Base
{
    public:
    void content()  {cout << "CPP content." << endl;}
};

void test1()
{
    Java java;
    cout << "Java页面如下:" << endl;
    java.header();
    java.footer();
    java.left();
    java.content();
}

int main()
{
    test1();
    return 0;
}
