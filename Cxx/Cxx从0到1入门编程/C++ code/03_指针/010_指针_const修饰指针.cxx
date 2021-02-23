#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
  int num1 = 10, num2 = 20;

  // 常量指针,指针指向的值不能通过指针更改，指针的指向可以改
  const int *p1 = &num1;
  // wrong
  // *p1 = 200;
  // right
  p1 = &num2;

  // 指针常量，指针的指向不可以改，指针指向的值可以改
  int *const p2 = &num1;
  // wrong
  // p2 = &num2
  // right
  *p2 = 200;

  // 都加
  const int *const p3 = &num1;
  //wrong
  // p3 = &num2;
  // *p3 = 200;
  return 0;
}
