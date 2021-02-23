// 引用的本质： 指针常量
#include <iostream>

using namespace std;

// 发现是引用，转换为int * const ref = &a;
void func(int &ref)
{
    ref = 100; // ref是引用，转换为*ref = 100;
}

int main(int argc, char **argv)
{
    int a = 10;
    // 自动转换为int * const ref = &a;
    // 指针常量指向的区域不可以更改，这也是引用为什么不可以更改
    int &ref = a;
    ref = 20; // 内部发现ref是引用，自动转换为 *ref = 20;
    cout << "a: " << a << ". ref: " << ref << endl;
    func(a);
    cout << "a: " << a << ". ref: " << ref << endl;
    return 0;
}
