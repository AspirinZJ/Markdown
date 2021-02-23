// 引用做函数参数
// 引用传递，形参也会修改实参值
#include <iostream>

using namespace std;
// 1. 值传递
void swap1(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 2. 地址传递
void swap2(int *p1, int *p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

// 3. 引用传递
void swap3(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main(int argc, char **argv)
{
    int a = 10, b = 20;
    cout << "a: " << a << ". b: " << b << endl;
    swap1(a, b);
    cout << "a: " << a << ". b: " << b << endl;
    swap2(&a, &b);
    cout << "a: " << a << ". b: " << b << endl;
    swap3(a, b);
    cout << "a: " << a << ". b: " << b << endl;

    return 0;
}
