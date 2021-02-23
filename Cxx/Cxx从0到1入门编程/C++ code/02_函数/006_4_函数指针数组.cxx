#include <iostream>
#include <algorithm>
#include <cmath>

// 可以用typedef来减少输入量
typedef const double * (*pf)(const double [], int); // 将pf定义为一个类型名称

const double * f1(const double arr[], int n);
const double * f2(const double [], int);
const double * f3(const double *, int);

int main()
{
    double a[3] = {1.23, 12.3, 52.2};

    // 声明指针
    const double * (*p1)(const double *, int) = f1;
    // pf p1 = f1;
    // pf p2 = f2;
    // pf p3 = f3;
    std::cout << "Pointer 1: " << (*p1)(a, 3) << ' ' << *((*p1)(a, 3)) << std::endl;

    // 声明一个指针数组，存储三个函数的地址
    const double * (*pArray[3])(const double *, int) = {f1, f2, f3};
    std::cout << "Pointer array: " << (*pArray[2])(a, 3) << ' ' << *((*pArray[2])(a, 3)) << std::endl;

    return 0;
}

const double * f1(const double arr[], int n)
{
    return arr; // 首地址
}

const double * f2(const double arr[], int n)
{
    return arr+1;
}

const double * f3(const double *arr, int n)
{
    return arr+2;
}
