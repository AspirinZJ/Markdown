#include <iostream>
using namespace std;

// 动物类
class Animal
{
    public:
        int mAge;
};

// 羊类
class Sheep : public Animal
{
};

// 驼类
class Tuo : public Animal
{};

//羊驼类
class YangTuo : public Sheep, public Tuo
{};

void test1()
{
    YangTuo yangTuo;
    // 当菱形继承，两个父类拥有相同数据，需要加以作用域区分
    yangTuo.Sheep::mAge = 18;
    yangTuo.Tuo::mAge = 28;
    cout << yangTuo.Sheep::mAge << '\t' << yangTuo.Tuo::mAge << endl;

    // 这份数据我们知道，只需要一份就可以，菱形继承导致资源浪费
}

int main()
{
    test1();
    return 0;
}
