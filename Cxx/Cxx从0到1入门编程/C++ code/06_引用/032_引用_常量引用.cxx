// 常量引用：用来修饰形参，防止形参修改实参
#include <iostream>

using namespace std;

void showValue(int &val)
{
    cout << "val = " << val << endl;
    val = 2000;
}

void showValue2(const int &val)
{
    cout << "val = " << val << endl;
    // 不能修改实参的值了
    // val = 2000;
}

int main(int argc, char **argv)
{
    int a = 10;

    // int &ref = 10; // 非法操作，引用必须引用一块合法的内存空间
    const int &ref = 10; // 合法操作，相当于int tmp = 10; int &ref = tmp;
    // ref = 20; // 非法，不能修改常量引用的值

    showValue(a); // 修改了实参的值
    cout << "a: " << a << endl;

    return 0;
}
