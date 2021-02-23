// 重载递增运算符
#include <iostream>
using namespace std;

class MyInt
{
    friend ostream & operator<<(ostream &cout, MyInt myInt);
    public:
        MyInt() {mNum = 0;}

        // 重载前置++运算符
        // 前置递增返回引用是为了一直对一个对象进行操作，不返回引用会调用拷贝构造函数 
        MyInt &operator++(){mNum++; return *this;} 

        // 重载后置++运算符
        // int 代表展位参数，可以用于区分前置和后置
        // 后置递增返回值，因为不能返回局部变量的引用
        MyInt operator++(int)
        {
            // 先记录当时的信息
            MyInt tmp = *this;
            // 再递增
            this->mNum++;
            // 最后返回当时记录的信息
            return tmp;
        }

    private:
        int mNum;
};

//重载左移运算符
ostream & operator<<(ostream &cout, MyInt myInt)
{
    cout << myInt.mNum;
    return cout;
}

void test1()
{
    MyInt myInt;
    cout << myInt << endl;
    cout << ++myInt << endl;
    cout << ++(++myInt) << endl;
}

void test2()
{
    MyInt myInt;
    cout << myInt++ << endl;
    cout << myInt << endl;
}

int main()
{
    test1();
    test2();
    return 0;
}
