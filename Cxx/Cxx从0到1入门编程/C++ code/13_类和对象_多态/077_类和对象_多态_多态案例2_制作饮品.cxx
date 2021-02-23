// 制作饮料大致流程：注水，冲泡，倒入杯中，加入辅料
// 利用多态，提供抽象制作饮品基类，提供子类制作咖啡和茶叶
#include <iostream>
using namespace std;

class AbstractDrinking
{
    public:
        virtual void boil() = 0; // 纯虚函数, 注水
        virtual void brew() = 0; // 冲泡
        virtual void pour() = 0; // 倒入杯中
        virtual void put() = 0; // 加入辅料
        void makeDrink() {boil(); brew(); pour(); put();}
};

class MakeCoffe : public AbstractDrinking
{
    public:
        virtual void boil() {cout << "煮咖啡水" << endl;}
        virtual void brew() {cout << "冲泡咖啡" << endl;}
        virtual void pour() {cout << "倒入咖啡" << endl;}
        virtual void put() { cout << "加入咖啡伴侣" << endl;}
};

class MakeTea: public AbstractDrinking
{
    public:
        virtual void boil() {cout << "煮茶水" << endl;}
        virtual void brew() {cout << "冲泡茶叶" << endl;}
        virtual void pour() {cout << "倒入茶叶" << endl;}
        virtual void put() { cout << "加入枸杞" << endl;}
};

void makeDrink(AbstractDrinking *pAbD)
{
    pAbD->makeDrink();
    delete pAbD;
}

void test1()
{
    makeDrink(new MakeCoffe);
    makeDrink(new MakeTea);
}

int main()
{
    test1();
    return 0;
}
