// 继承方式
#include <iostream>
using namespace std;

class Base
{
    public:
        int mA;
    protected:
        int mB;
    private:
        int mC;
};

//公共继承
class Son1 : public Base
{
    public:
        void func()
        {
            this->mA = 10; // 基类中public，子类依然是public
            this->mB = 20; // 基类中protected，子类依然是protected
            // this->mC = 30; // 基类中private，子类无法继承
        }
};

// 保护继承
class Son2 : protected Base
{
    public:
        void func()
        {
            this->mA = 10; // 基类中public，子类是protected
            this->mB = 20; // 基类中protected，子类依然是protected
            // this->mC = 30; // 基类中private，子类无法继承
        }
};

// 私有继承
class Son3 : private Base
{
    public:
        void func()
        {
            this->mA = 10; // 基类中public，子类是private
            this->mB = 20; // 基类中protected，子类是private
            // this->mC = 30; // 基类中private，子类无法继承
        }
};


class GrandSon3 : public Son3
{
    public:
        void func()
        {
            // this->mA = 10; // 到了Son3里面变为了private
        }
};


int main()
{
    return 0;
}
