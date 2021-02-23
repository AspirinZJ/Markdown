// 重载关系运算符
#include <iostream>
#include <string>

using namespace std;

class Person
{
    public:
        Person(string name, int age) : mName(name), mAge(age) {}
        // 重载==运算符
        bool operator==(Person &p)
        {
            if (p.mName == this->mName && p.mAge == this->mAge) { return true;}
            else {return false;}
        }

        // 重载!=运算符
        bool operator!=(Person &p)
        {
            if (p.mName == this->mName && p.mAge == this->mAge) { return false;}
            else {return true;}
        }

        string mName;
        int mAge;
};

void test1()
{
    Person person1("Alice", 18);
    Person person2("Alice", 18);
    Person person3("Alice", 19);
    
    if (person1 == person2) {cout << "person1 and person2 are equal." << endl;}
    if (person3 != person2) {cout << "person1 and person2 are not equal." << endl;}
}

int main()
{
    test1();
    return 0;
}
