// 类模板与继承
#include <iostream>
using namespace std;

template<class T>
class Base
{
    public:
        T m;
};

// class Son : public Base{}; // 错误，必须知道父类中的数据类型才能继承给子类
class Son : public Base<int> {};

void test1()
{
    Son son;
    cout << sizeof(son) << endl;
}

// 如果想灵活地指定父类中的T类型，子类也需要变成类模板
template<class T1, class T2>
class Son2 : public Base<T1> 
{ 
    public: 
        Son2() 
        {
            cout << "T1 的类型：" << typeid(T1).name() << endl;
            cout << "T2 的类型：" << typeid(T2).name() << endl;
        }
        T2 obj;
};

void test2()
{
    Son2<int, char> son2;
}

int main()
{
    test1();
    test2();
    return 0;
}
