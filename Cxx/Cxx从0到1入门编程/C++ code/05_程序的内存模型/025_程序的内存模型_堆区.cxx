// 堆区
#include <iostream>

using namespace std;

int * func()
{
    // 利用new关键字将数据开辟到堆区
    int *p = new int(10); // p仍是局部变量,放在栈区，指针保存的数据放在堆区
    return p;
}

int main(int argc, char **argv)
{
    int *p = func();
    cout << *p << endl;
    return 0;
}
