#include <iostream>
#include <cstring>

int *fun(int a, int b)
{
    int *p = (int *)malloc(sizeof(int));
    memset(p, 0, sizeof(int));
    *p = a+b;
    return p;
}

int main()
{
    int *p = nullptr;
    p = fun(1, 2);
    std::cout << *p << std::endl;

    return 0;
}
