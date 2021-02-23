// 引用的基本语法
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int a = 10;
    int &b = a; // 创建引用
    cout << "a = : " << a << endl;
    cout << "b = : " << b << endl;
    b = 20;
    cout << "a = : " << a << endl;
    cout << "b = : " << b << endl;

    return 0;
}
