#include <iostream>

using namespace std;

int func(int a, int b = 20, int c = 30)
{
    return a + b + c;
}

// 如果函数声明有默认参数，那么函数实现不能有默认参数
int func2(int a = 10, int b = 20);

int main(int argc, char **argv)
{
    int result = func(1, 2, 3);
    cout << "result: " << result << endl;
    int result2 = func(1, 5);
    cout << "result2: " << result2 << endl;
    int result3 = func(1);
    cout << "result3: " << result3 << endl;

    int result4 = func2();
    cout << "result4: " << result4 << endl;
    return 0;
}


// 如果函数声明有默认参数，那么函数实现不能有默认参数
// int func2(int a = 10, b = 20) // 报错
int func2(int a, int b)
{
    return a + b;
}

