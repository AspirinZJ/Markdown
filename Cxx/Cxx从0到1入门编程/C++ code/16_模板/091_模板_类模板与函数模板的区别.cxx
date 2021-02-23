// 类模板没有自动类型推导
#include <iostream>
using namespace std;

template<class NameType, class AgeType=int>
class Person
{
    public:
        Person(NameType name, AgeType age) {this->_age = age; this->_name = name;}
        void _showPerson() {cout << "Name: " << this->_name << ". Age: " << this->_age << endl;}
        NameType _name;
        AgeType _age;
};

void test1()
{
    // Person person("Alice", 20); //但是这句自动类型推导似乎能用
    Person<string, int> person("Alice", 20);
    person._showPerson();

    Person<string> person2("Bob", 'a'); // 有默认参数int
    person2._showPerson();
}

int main()
{
    test1();
    return 0;
}
