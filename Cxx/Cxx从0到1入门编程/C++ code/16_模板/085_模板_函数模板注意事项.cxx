// 函数模板的注意事项
// 2. 模板必须要确定出T的数据类型才能使用
#include <iostream>
using namespace std;

// template<typename T> // typename可以替换成class
template<class T>
void swapT(T &a, T &b) {T tmp = a; a = b; b = tmp;}

void test1()
{
    int a = 0, b = 1;
    swapT(a, b);
    // char c = 'a';
    // 1. 自动类型推导，必须推导出一致的数据类型T，才能使用
    // swapT(a, c); // 推导不出一致的T数据类型
    cout << "a: " << a << ". b: " << b << endl;
}

template<typename T>
void func(){cout << "Calling func." << endl;} // 是一个模板函数，紧跟了template之后

void test2() {func<int>();} // 必须确定出T的类型

int main()
{
    test1();
    test2();
    return 0;
}
