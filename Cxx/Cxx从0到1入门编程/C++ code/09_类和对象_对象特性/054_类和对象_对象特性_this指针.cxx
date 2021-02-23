#include <iostream>
using namespace std;

class Person
{
    public:
        // this指针指向被调用的成员函数所属的对象
        Person(int mAge) {this->mAge = mAge;}
        void addAge(Person &p) {this->mAge += p.mAge;}
        // 返回对象本身用*this
        Person &addAgeThis(Person &p) {this->mAge += p.mAge; return *this;} // this是指向调用对象的指针，所以*this就是这个对象本体

        Person addAge_(Person &p) {this->mAge += p.mAge; return *this;}
        int mAge;
};

void test1()
{
    Person person1(18);
    cout << person1.mAge << endl;
}

void test2()
{
    Person person1(10);
    Person person2(20);
    // person2.addAge(person1);
    // person2.addAge(person1).addAge(person1); // 报错，因为addAge返回void类型，所以person2.Addage(person1)是void类型，不能继续调用addAge
    person2.addAgeThis(person1).addAgeThis(person1); // 链式编程思想
    
    // **********************
    // 值传递会调用拷贝构造函数！！！
    person2.addAge_(person1).addAge_(person1); // 调用了拷贝构造函数，返回的不是person2本身而是他的一个拷贝
    cout << person2.mAge <<endl;
}

int main()
{
    // test1();
    test2();
    return 0;
}
