#include <iostream>
using namespace std;

// 动物类
class Animal
{
    public:
        int mAge;
};

// 利用虚继承，解决菱形继承问题
// 在继承前加上virtual
// 此时Animal类称为虚基类
// 羊类
class Sheep : virtual public Animal {};

// 驼类
class Tuo : virtual public Animal {};

//羊驼类
class YangTuo : public Sheep, public Tuo {};

void test1()
{
    YangTuo yangTuo;
    yangTuo.Sheep::mAge = 18;
    yangTuo.Tuo::mAge = 28;
    cout << yangTuo.Sheep::mAge << '\t' << yangTuo.Tuo::mAge << endl;

    // 此时数据只有一份，解决了资源浪费问题
    // 此时继承的不是数据，而是指针，指针通过偏移量找到唯一的数据
    // 甚至可以用以下方式访问
    cout << yangTuo.mAge << endl;
}

int main()
{
    test1();
    return 0;
}
