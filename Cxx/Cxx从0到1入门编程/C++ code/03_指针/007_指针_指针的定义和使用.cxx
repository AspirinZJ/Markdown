#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
  int a = 0;
  int *p;
  p = &a;

  cout << "The address of a:" << &a << endl;
  cout << "The address of a:" << p << endl;
  cout << "The value of a:" << *p << endl;
  
  *p = 1000;

  cout << "The value of a:" << *p << endl;
  cout << "The value of a:" << *(&a) << endl;
  return 0;
}
