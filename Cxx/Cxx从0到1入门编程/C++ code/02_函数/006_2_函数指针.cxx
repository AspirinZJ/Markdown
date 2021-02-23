#include <iostream>

int addFunc(int a, int b)
{
    return a+b;
}

void test(int i, int (*add)(int a, int b))
{
    std::cout << "i: " << i << std::endl;
    std::cout << (*add)(1, 2) << std::endl;
}

int main()
{
    int (*add)(int, int) = addFunc; // addFunc函数名转换成指针，传递给add
    int (*add2)(int, int) = &addFunc; // 直接获取函数指针

    //函数指针的使用
    std::cout << (*add)(1, 2) << std::endl;
    std::cout << (*add2)(1, 2) << std::endl;
    std::cout << add(1, 2) << std::endl; // 不推荐
    std::cout << add2(1, 2) << std::endl; // 不推荐

    test(1, addFun); // 函数指针作为参数传入

    return 0;
}
