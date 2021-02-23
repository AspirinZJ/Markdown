// 赋值运算符重载
#include <iostream>
using namespace std;

class Person
{
    public:
        Person(int age) {mAge = new int(age);}
        int *mAge;
        ~Person()
        {
            if (mAge) {delete mAge;}
        }
};

void test1()
{
    Person person1(18);
    cout << "Person 1's age: " << *person1.mAge << endl;
    Person person2(20);
    cout << "Person 2's age: " << *person2.mAge << endl;
    person2 = person1; // 浅拷贝，调用析构函数时会delete两次同一个地址,错误
    cout << "Person 1's age: " << *person1.mAge << endl;
    cout << "Person 2's age: " << *person2.mAge << endl;
}

int main()
{
    test1();
    return 0;
}
