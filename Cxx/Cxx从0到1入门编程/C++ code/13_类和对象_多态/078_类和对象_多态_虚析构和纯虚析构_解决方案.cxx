#include <iostream>
using namespace std;

class Animal
{
    public:
        Animal() {cout << "Animal constructor." << endl;}
        // virtual ~Animal() {cout << "Animal destructor." << endl;} // 虚析构
        virtual ~Animal() = 0; // 纯虚析构, 有了纯虚析构，这个类属于抽象类，无法实例化对象
        virtual void speak() = 0; // 纯虚函数
};

// 纯虚析构需要具体的函数实现
Animal::~Animal() {cout << "Animal 纯虚析构" << endl;}

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
    // 利用虚析构可以解决父类指针释放子类对象时内存泄漏问题
}

int main()
{
    test1();
    return 0;
}
