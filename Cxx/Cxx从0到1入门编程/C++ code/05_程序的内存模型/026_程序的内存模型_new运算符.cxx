#include <iostream>

using namespace std;

// new的基本语法
int * func()
{
    // 在堆区创建一个整形数据
    int *p = new int(10); // new 返回该数据类型对应的指针
    return p;
}

void test1()
{
    int *p = func();
    cout << *p << endl;
    // new开辟的数据由delete释放
    delete p;
    // cout << *p << endl; // 内存已经被释放
}

// 在堆区利用new开辟数组
void test2()
{
    // 在堆区创建10个整形数据的数组
    int *arr = new int[10]; // 10代表数组有10个元素
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i;
        cout << arr[i] << " ";
    }
    cout << endl;
    // 释放堆区数组
    delete[] arr;
}

int * test3()
{
    int *arr2 = new int[3]{1, 2, 3};
    return arr2;
}

int main(int argc, char **argv)
{
    test1(); // 堆区的数据由程序员管理、开辟和释放
    test2();
    int *arr = test3();
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}
