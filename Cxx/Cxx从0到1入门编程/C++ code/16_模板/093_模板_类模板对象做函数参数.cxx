// 1. 指定传入类型 2. 参数模板化 3. 整个类模板化
#include <iostream>
#include <string>
using namespace std;

template<class T1, class T2>
class Person
{
    public:
        Person(T1 name, T2 age) {this->_name = name; this->_age = age;}
        void _showPerson() {cout << "Name: " << this->_name << ". Age: " << this->_age << endl;}
        T1 _name;
        T2 _age;
};

// 1. 指定传入类型
void printPerson1(Person<string, int> &person) {person._showPerson();}

void test1()
{
    Person<string, int> person("Alice", 100);
    printPerson1(person);
}

// 参数模板化
template<class T1, class T2>
void printPerson2(Person<T1, T2> &person)   
{
    person._showPerson();
    // 利用typeid查看模板中的数据类型
    cout << "T1 类型: " << typeid(T1).name() << endl;
    cout << "T2 类型: " << typeid(T2).name() << endl;
}

void test2()
{
    Person<string, int> person("Bob", 10);
    printPerson2(person);
}

// 整个类模板化
template<class T>
void printPerson3(T &p) {p._showPerson();}

void test3()
{
    Person<string, int> person("Charlie", 30);
    printPerson3(person);
}

int main()
{
    test1();
    test2();
    test3();
    return 0;
}
