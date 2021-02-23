#include <iostream>
using namespace std;

class Animal
{
    public:
        void speak() {cout << "Animal is speaking." << endl;}
};

class Cat : public Animal
{
    public:
        void speak() {cout << "Cat is speaking." << endl;}
};

// 地址早绑定，在编译阶段就确定了函数的地址
// 如果想执行让猫说话，这个函数的地址就不能提前绑定，需要在运行阶段绑定，晚绑定
void doSpeak(Animal &animal) // Animal &animal = cat;
{
    animal.speak();
}

int main()
{
    Cat cat;
    doSpeak(cat); // 父类Animal的引用接收子类Cat的对象
    return 0;
}
