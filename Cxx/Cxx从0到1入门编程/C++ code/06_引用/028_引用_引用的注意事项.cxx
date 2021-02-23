// 引用的注意事项
// 1. 引用必须初始化
// 2. 引用初始化后，不可以改变
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int a = 10, c = 20;
    // int &b; // 错误，引用必须初始化
    int &b = a;
    b = c; // 此处为赋值操作而非更改引用
    cout << "a: " << a << ". b: " << b << ". c: " << c << endl;
    
    return 0;
}
