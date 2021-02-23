// 动态多态的满足条件
// 1. 有继承关系
// 2. 子类要重写父类的虚函数

// 动态多态使用：父类的指针或引用指向子类对象

#include <iostream>
using namespace std;

class Animal
{
    public:
        // 虚函数
        virtual void speak() {cout << "Animal is speaking." << endl;}
};

class Cat : public Animal
{
    public:
        void speak() {cout << "Cat is speaking." << endl;}
};

class Dog : public Animal
{
    public:
        // 子类重写父类虚函数时，子类的virtual可写可不写
        virtual void speak() {cout << "Dog is speaking." << endl;}
};

// 地址早绑定，在编译阶段就确定了函数的地址
// 如果想执行让猫说话，这个函数的地址就不能提前绑定，需要在运行阶段绑定，地址晚绑定
// 动态多态使用：父类的指针或引用指向子类对象
void doSpeak(Animal &animal) // Animal &animal = cat;
{
    animal.speak();
}

int main()
{
    Cat cat;
    doSpeak(cat); // 父类Animal的引用接收子类Cat的对象
    Dog dog;
    doSpeak(dog);
    return 0;
}
