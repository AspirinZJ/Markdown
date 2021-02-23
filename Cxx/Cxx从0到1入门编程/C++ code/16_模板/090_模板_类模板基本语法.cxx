#include <iostream>
#include <string>
using namespace std;

template<class NameType, class AgeType>
class Person
{
    public:
        Person(NameType name, AgeType age) {this->_name = name; this->_age = age;}

        void _showPerson() {cout << "Name: " << this->_name << ". Age: " << this->_age << endl;}
        NameType _name;
        AgeType _age;
};

void test1()
{
    Person<string, int> person("Alice", 20);
    person._showPerson();
}

int main()
{
    test1();
    return 0;
}
