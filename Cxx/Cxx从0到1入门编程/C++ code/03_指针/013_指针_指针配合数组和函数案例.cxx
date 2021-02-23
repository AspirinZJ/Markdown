/*
 * 封装一个函数，利用冒泡排序，实现对整形数组的升序排序
 */

#include <iostream>

using namespace std;

void bubbleSort(int *arr, int len);
void printArr(int *arr, int len);

int main(int argc, char **argv)
{
  int arr[10] = {23, 65, 3464, 234, 4356, 345, 345, 213, 5432, 232};
  int len = sizeof(arr) / sizeof(arr[0]);

  // bubble sort
  bubbleSort(arr, len);
  printArr(arr, len);
  

  return 0;
}

void bubbleSort(int *arr, int len)
{
  for (int i = 0; i < len - 1; i++)
  {
    for (int j = 0; j < len - i - 1; j++)
    {
      if (arr[j] > arr[j+1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  return;
}

void printArr(int *arr, int len)
{
  cout << "Arr:\t";
  for (int i = 0; i < len; i++)
  {
    cout << arr[i] << '\t';
  }
  cout << endl;

  return;
}
