// 电脑组成：CPU，显卡，内存条
// 将每个零件封装成抽象基类，并提供不同厂商生产不同零件
// 创建电脑类提供让电脑工作的函数, 并且调用每个零件的接口
#include <iostream>
using namespace std;

// 抽象出不同的零件类
class CPU
{
    public:
        virtual void calculate() = 0;
};

class GPU
{
    public:
        virtual void display() = 0;
};

class Memory
{
    public:
        virtual void store() = 0;
};

class Computer
{
    public:
        Computer(CPU *pCpu, GPU *pGpu, Memory *pMemory)
        {this->pCpu = pCpu; this->pGpu = pGpu; this->pMemory = pMemory;}
        void work()
        {
            pCpu->calculate();
            pGpu->display();
            pMemory->store();
        }

        // 提供析构函数释放三个零件
        ~Computer() 
        {
            if (this->pCpu) {delete this->pCpu; this->pCpu = NULL;}
            if (this->pGpu) {delete this->pGpu; this->pGpu = NULL;}
            if (this->pMemory) {delete this->pMemory; this->pMemory= NULL;}
        }
    private:
        CPU *pCpu;
        GPU *pGpu;
        Memory *pMemory;
};

class IntelCPU : public CPU
{
    public:
        virtual void calculate() {cout << "Intel CPU is working." << endl;}
};

class IntelGPU : public GPU
{
    public:
        virtual void display() {cout << "Intel GPU is displaying." << endl;}
};

class IntelMemory : public Memory
{
    public:
        virtual void store() {cout << "Intel memory is working." << endl;}
};

class LenovoCPU : public CPU
{
    public:
        virtual void calculate() {cout << "Lenovo CPU is working." << endl;}
};

class LenovoGPU : public GPU
{
    public:
        virtual void display() {cout << "Lenovo GPU is displaying." << endl;}
};

class LenovoMemory : public Memory
{
    public:
        virtual void store() {cout << "Lenovo memory is working." << endl;}
};

void test1()
{
    // 电脑零件1
    CPU *pIntelCpu = new IntelCPU;
    GPU *pIntelGpu = new IntelGPU;
    Memory *pIntelMemory = new IntelMemory;
    // 电脑1
    Computer *computer = new Computer(pIntelCpu, pIntelGpu, pIntelMemory);
    computer->work();
    delete computer;
    
    // 电脑2
    Computer *computer2 = new Computer(new LenovoCPU, new LenovoGPU, new LenovoMemory);
    computer2->work();
    delete computer2;
}

int main()
{
    test1();
    return 0;
}
