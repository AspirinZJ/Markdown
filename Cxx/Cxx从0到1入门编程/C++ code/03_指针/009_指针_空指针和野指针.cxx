#include <iostream>


using namespace std;


int main(int argc, char **argv)
{
  int *p = NULL;
  // error: cannot access NULL pointer
  // *p = 10;
  // cout << *p << endl;


  // 野指针，没有申请内存空间就指向（非法内存空间）
  int *p2 = (int *)0x1100;
  // cout << *p << endl;

  return 0;
}
