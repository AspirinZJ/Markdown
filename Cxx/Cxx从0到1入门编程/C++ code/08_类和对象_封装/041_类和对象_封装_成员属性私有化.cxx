// 成员属性设置为私有优点
// * 可以自己控制读写权限
// * 对于写权限，我们可以检测数据有效性
#include <iostream>
#include <string>

using namespace std;

class Person
{
    private:
        string mName; // readable, writable
        int mAge = 1; // readonly
        string mLover; // write only

    public:
        // 提供公共成员函数来修改
        void setName(string name)
        {
            mName = name;
        }

        string getName()
        {
            return mName;
        }

        int getAge()
        {
            return mAge;
        }

        void setLover(string loverName)
        {
          mLover = loverName;
        }
};

int main()
{
    Person p1;
    p1.setName("Alice");
    string name = p1.getName();
    cout << name << endl;
    int age = p1.getAge();
    cout << "Age: " << age <<endl;
    p1.setLover("Bob");
    return 0;
}
