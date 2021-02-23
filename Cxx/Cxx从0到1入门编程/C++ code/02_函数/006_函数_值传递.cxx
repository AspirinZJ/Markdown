#include <iostream>

using namespace std;

void swap(int num1, int num2)
{
  cout << "Before swapping" << num1 << '\t' << num2 << endl;
  int tmp = num1;
  num1 = num2;
  num2 = tmp;

  cout << "Before swapping" << num1 << '\t' << num2 << endl;
  return;
}

int main(int argc, char **argv)
{
  int a = 10, b = 20;
  swap(a, b);
  cout << "a" << a << '\t' << "b" <<  b << endl;
  return 0;
}
