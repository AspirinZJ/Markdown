// struct 和 class区别： 访问权限struct默认public， class默认private
#include <iostream>

using namespace std;

class C1
{
    int m_A; // 默认为private
};

struct S1
{
    int m_A;
};

int main(int argc, char **argv)
{
    C1 c1;
    S1 s1;
    // c1.m_A = 100; // 错误
    s1.m_A = 100;
    return 0;
}
