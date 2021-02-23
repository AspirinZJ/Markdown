// 引用做函数返回值
// 1. 不要返回局部变量的引用
// int & test1()
// {
//     int a = 10;
//     return a;
// }
int &test2()
{
    static int a = 10; // 静态变量放在全局区
    return a;
}
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    // int &ref = test1();
    int &ref2 = test2();
    cout << "ref2: " << ref2 << endl;
// 2. 函数的调用可以作为左值
    test2() = 1000; // 为static int a赋值
    cout << "ref2: " << ref2 << endl; // ref2 是a的别名

    return 0;
}
