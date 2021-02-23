#include <iostream>

using namespace std;

// 值传递
void swap(int a, int b);

// 地址传递
void swap2(int *a, int *b);

int main(int argc, char **argv)
{
  int a = 10, b = 20;
  swap(a, b);
  cout << "a:" << a << "\tb:" << b << endl;
  swap2(&a, &b);
  cout << "a:" << a << "\tb:" << b << endl;

  return 0;
}

void swap(int a, int b)
{
  int temp = a;
  a = b; 
  b = temp;
  return;
}

void swap2(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
  return;
}
