// 拷贝构造函数的使用时机
#include <iostream>

using namespace std;

class Person
{
    public:
        int mAge;
        Person() {cout << "Person default constructor." << endl;}
        Person(int age) { mAge = age; cout << "有参构造" << endl;}
        Person(const Person &p) {mAge = p.mAge; cout << "拷贝构造" << endl;}
        ~Person() {cout << "Person class destructor." << endl;}
};

void test1()
{
// 1. 使用一个已经创建完毕的对象来初始化一个新对象
    Person person1(10);
    Person person2(person1);
}

void doWork(Person p)
{
    p.mAge = 1000; // 值传递改变拷贝的副本不会改变原来的值
}

void test2()
{
// 2. 以值传递的方式给函数传值
    Person person3(10);
    doWork(person3); // 会调用拷贝构造函数，因为值传递时会拷贝一份副本
    cout << "person3 age: " << person3.mAge << endl;
}

// 3. 以值方式来返回局部对象
Person doWork2()
{
    Person localPerson; // 局部对象
    cout << &localPerson << endl;
    return localPerson; // 值返回，会创建一个新对象然后返回
}
void test3()
{
    Person person = doWork2();
    cout << &person << endl;
}
int main(int argc, char **argv)
{
    // test1();
    // test2();
    test3();
    return 0;
}
