// 模板并不是万能的，有些特定的数据类型需要用具体化的方式做特殊实现
#include <iostream>
using namespace std;

class Person
{
    public:
        Person(string name, int age) {this->_name = name; this->_age = age;}
        string _name;
        int _age;
};

template<typename T>
bool compareT(T &a, T &b) { if (a == b) {return true;} else {return false;}}

// 利用具体化的Person的版本来实现代码，具体化会优先调用
template<> bool compareT(Person &p1, Person &p2) // template<> 表示重载了模板函数
{
    if (p1._age == p2._age && p1._name == p2._name) {return true;}
    else {return false;}
}

void test1()
{
    int a = 10, b = 5;
    cout << compareT<int>(a, b) << endl;
}

void test2()
{
    Person p1 = Person("Tom", 10);
    Person p2("Tom", 10);
    cout << compareT(p1, p2) << endl;
}

int main()
{
    // test1();
    test2();
    return 0;
}
