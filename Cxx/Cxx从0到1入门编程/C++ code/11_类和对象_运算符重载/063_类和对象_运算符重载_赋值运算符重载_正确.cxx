// 赋值运算符重载
#include <iostream>
using namespace std;

class Person
{
    public:
        Person(int age) {mAge = new int(age);}
        int *mAge;
        // 重载赋值运算符，防止浅拷贝
        Person &operator=(Person &person1)
        {
            // 应该先判断是否有属性在堆区，如果有，先释放
            if (this->mAge) {delete this->mAge; mAge = NULL;}
            this->mAge = new int(*person1.mAge);
            return *this;
        }
        ~Person()
        {
            if (this->mAge) {delete this->mAge;}
        }
};

void test1()
{
    Person person1(18);
    cout << "Person 1's age: " << *person1.mAge << endl;
    Person person2(20);
    cout << "Person 2's age: " << *person2.mAge << endl;
    person2 = person1;
    cout << "Person 1's age: " << *person1.mAge << endl;
    cout << "Person 2's age: " << *person2.mAge << endl;
    Person person3(50);
    person3 = person2 = person1;    // 链式编程
    cout << "Person 1's age: " << *person1.mAge << endl;
    cout << "Person 2's age: " << *person2.mAge << endl;
    cout << "Person 3's age: " << *person3.mAge << endl;
}

int main()
{
    test1();
    return 0;
}
