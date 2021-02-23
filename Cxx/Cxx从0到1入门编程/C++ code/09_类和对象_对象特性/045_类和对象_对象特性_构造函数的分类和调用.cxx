#include <iostream>

using namespace std;

class Person
{
    private:
        int mAge;
    public:
    // 构造函数的分类
    // 1. 按参数： 有参构造和无参构造
    // 2. 按类型： 普通构造函数和拷贝构造函数
    Person()    {cout << "Creating Person class." << endl;} // 无参构造或者默认构造
    Person(string name, int age) {
        cout << "The name of the person is: " << name << endl;
        mAge = age;
    }
    // 拷贝构造函数
    Person(const Person &person)   {cout << "拷贝构造函数" << endl; mAge = person.mAge;} // 注意是const 的引用传入
    ~Person()   {cout << "Destroying Person object." << endl;}
};

void test1()
{
    // 构造函数的调用
    // 1. 括号法
    // 2. 显式法
    // 3. 隐式转换法
    Person person1; // 默认构造函数调用
    Person person2("Alice", 20); // 括号法调用构造函数
    Person person3(person2); // 拷贝法调用构造函数
    // *******注意事项
    // 1. 调用默认构造函数的时候，不要加(), 下面的代码不会创建对象，因为编译器认为是函数的声明
    // Person person4(); // Person 是返回类型，person4是函数名，这是一个函数声明，而不是创建一个对象

    // 显式法
    Person person5 = Person("Alice", 20); // 括号法调用构造函数, 显式法
    Person person6 = Person(person5); // 拷贝构造，显式法
    Person("Unnamed", 20); // 匿名对象，当前的行执行后，系统会自动回收匿名对象
    
    //*********注意事项2
    //不要利用拷贝构造函数来初始化匿名对象,编译器会认为Person(person6); 等同于 Person person6; 重复定义
    // Person(person6); // 编译器会认为这是对象声明

    // 隐式法
    Person person7 = {"Alice", 10}; // 相当于Person person7 = Person("Alice", 10);
    Person person8 = person7;
}
int main()
{
    test1();
    return 0;
}
