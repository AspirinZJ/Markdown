// 访问权限
// 1. public 公共权限， 类内可以访问，类外可以访问
// 2. protected 保护权限， 类内可以访问， 类外不可以访问
// 3. private 私有权限， 类内可以访问，类外不可以访问
#include <iostream>
#include <string>

using namespace std;

class Person
{
    public:
        string mName;

    protected:
        string mCarName;

    private:
        string mCardNumber;

    public:
        void func()
        {
            mName = "Alice";
            mCarName = "Car1";
            mCardNumber = "0000";
        }
};

int main(int argc, char **argv)
{
    Person person1;
    person1.mName = "Bob";

    return 0;
}
