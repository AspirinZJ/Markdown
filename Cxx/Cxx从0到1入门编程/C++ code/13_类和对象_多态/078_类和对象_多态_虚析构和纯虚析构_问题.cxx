#include <iostream>
using namespace std;

class Animal
{
    public:
        Animal() {cout << "Animal constructor." << endl;}
        ~Animal() {cout << "Animal destructor." << endl;}
        virtual void speak() = 0; // 纯虚函数
};

class Cat : public Animal
{
    public:
        Cat(string name) {cout << "Cat constructor." << endl; mName = new string(name);}
        virtual void speak() {cout << *this->mName << " is speaking." << endl;}
        ~Cat()
        {
            if (this->mName) {cout << "Cat destructor." << endl; delete this->mName; this->mName = NULL;}
        }
        string *mName; // 子类堆区属性
};

void test1()
{
    Animal *pAnimal = new Cat("Tom");
    pAnimal->speak();
    delete pAnimal; // 父类的指针在析构时，不会调用子类析构函数，导致子类堆区属性的内存泄漏
}

int main()
{
    test1();
    return 0;
}
