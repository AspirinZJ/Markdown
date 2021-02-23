// 函数的占位参数
// 占位参数调用时必须填补
#include <iostream>

using namespace std;

// 占位参数可以有默认值
void func(int a, int, int = 20)
{
    cout << "a: " << a << endl;
}

int main(int argc, char **argv)
{
// 占位参数调用时必须填补
    func(10, 10);
    return 0;
}
