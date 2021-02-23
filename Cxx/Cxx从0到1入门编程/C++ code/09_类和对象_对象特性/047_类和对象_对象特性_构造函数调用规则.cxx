// 1. 默认构造函数（无参构造，函数体为空）
// 2. 默认析构函数（无参，函数体为空）
// 3. 拷贝构造函数，对属性值进行拷贝
// 构造函数调用规则如下：
// 1 如果用户定义有参构造函数，c++不提供默认的无参构造，但是会提供默认拷贝构造
// 2 如果用户定义拷贝构造函数，c++不会再提供其他构造函数 
#include <iostream>

using namespace std;

class Person
{
    public: 
        int mAge;
        // Person() {cout << "Default constructor." << endl;}
        Person(int age) {cout << "有参构造" << endl; mAge = age;}
        // Person(const Person &p) {cout << "拷贝构造" << endl; mAge = p.mAge;}
        ~Person() {cout << "Default destructor." << endl;}
};

// void test1()
// {
//     Person person;
//     person.mAge = 18;
// 
//     Person person2(person);
//     cout << "the age of person2: " << person2.mAge << endl;
// }

void test2()
{
    Person person(15);
}

int main()
{
    // test1();
    test2();
    return 0;
}
