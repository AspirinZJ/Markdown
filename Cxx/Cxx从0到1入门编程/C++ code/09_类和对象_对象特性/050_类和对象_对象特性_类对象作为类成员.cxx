// 类对象作为类成员： 对象成员
// 当其他类的对象作为本类成员，先构造其他类的对象，再构造自身
// 析构的顺序与构造相反
#include <iostream>
#include <string>
using namespace std;

class Phone
{
    public:
        Phone(string phoneName) {cout << "Phone constructor." << endl; mPhoneName = phoneName;}
        ~Phone() {cout << "Phone destructor." << endl;}
        string mPhoneName;
};

class Person
{
    public:
        Person(string name, string phoneName) : mName(name), mPhone(phoneName) {cout << "Person constructor." << endl;}
        // 相当于Phone mPhone = Phone(phoneName); // 隐式转换法
        ~Person() {cout << "Person destructor." << endl;}

        string mName;
        Phone mPhone;
};

void test1()
{
    Person person1("Alice", "phone");
}

int main()
{
    test1();
    return 0;
}
