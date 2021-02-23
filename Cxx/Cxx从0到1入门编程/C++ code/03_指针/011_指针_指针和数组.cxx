#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
  int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int *p = arr;

  cout << "The first element in the array:" << arr[0] << endl;
  cout << "The first element in the array:" << *p << endl;

  // access the second element
  p++;  // move pointer by 4 bytes
  cout << "The second element in the array:" << arr[1] << endl;
  cout << "The second element in the array:" << *p << endl;

  // go through the array using pointer
  int *p2 = arr;
  for (int i = 0; i < 10; i++)
  {
    cout << *p2 << endl;
    p2++;
  }

  return 0;
}
