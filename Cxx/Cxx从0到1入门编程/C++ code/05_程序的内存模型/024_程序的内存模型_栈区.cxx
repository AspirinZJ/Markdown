// 栈区数据的注意事项
// 不要返回局部变量的地址
//
// 栈区的数据由编译器管理、开辟和释放
#include <iostream>

using namespace std;

int * func(int b) // 形参数据也存放在栈区
{
    int a = 10;// 存放在栈区，自动释放
    return &a; // 返回局部变量的地址
}

int main(int argc, char **argv)
{
    int *p = func();
    cout << "*p: " << *p << endl; // 段错误
    return 0;
}
