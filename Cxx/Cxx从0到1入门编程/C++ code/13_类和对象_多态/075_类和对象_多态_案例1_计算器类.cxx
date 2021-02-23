// 分别利用普通写法和多态技术，实现两个操作数进行运算的计算器类
#include <iostream>
#include <string>
using namespace std;

// 普通写法
class Calculator
{
    public:
        int getResult(string oper)
        {
            if ("+" == oper) {return this->mNum1 + this->mNum2;}
            else if ("-" == oper) {return this->mNum1 - this->mNum2;}
            else if ("*" == oper) {return this->mNum1 * this->mNum2;}
            // 如果想扩展新的功能如除法，需要修改源码
            // 在真实开发中，提倡开闭原则
            // 开闭原则：对扩展进行开放，对修改进行关闭
        }
        int mNum1;
        int mNum2;
};

// 利用多态实现计算器
// 1. 实现计算器的基类（抽象类）
// 多态好处：组织结构清晰，可读性强，对于前期和后期的扩展和维护性高
class AbstractCalculator
{
    public:
        int mNum1;
        int mNum2;
        virtual int getResult() {return 0;}
};

// 设计加法计算器类
class CalculatorAdd : public AbstractCalculator
{
    public:
        int getResult() {return this->mNum1 + this->mNum2;}
};

// 设计减法计算器类
class CalculatorSub : public AbstractCalculator
{
    public:
        int getResult() {return this->mNum1 - this->mNum2;}
};

// 设计乘法计算器类
class CalculatorMul : public AbstractCalculator
{
    public:
        int getResult() {return this->mNum1 * this->mNum2;}
};

void test1()
{
    Calculator calc;
    calc.mNum1 = 10;
    calc.mNum2 = 5;
    cout << calc.getResult("+") << endl;
}

void test2()
{
    // 多态使用条件：父类指针或引用指向子类对象
    AbstractCalculator *abc = new CalculatorAdd;
    abc->mNum1 = 10;
    abc->mNum2 = 5;
    cout << abc->getResult() << endl;
    // 记得销毁堆区的数据
    // *********注意，销毁的只是数据，abc指针数据类型没有变，再次使用时不需要重新声明
    delete abc;

    abc = new CalculatorSub;
    // 注意，数据已经销毁了，需要重新给属性赋值
    abc->mNum1 = 10;
    abc->mNum2 = 5;
    cout << abc->getResult() << endl;
    delete abc;
}

int main()
{
    // test1();
    test2();
    return 0;
}
