// 利用函数模板封装一个排序的函数，可以对不同数据类型的数组排序
// 用选择排序算法，从大到小排列
#include <iostream>
using namespace std;

template<typename T>
void mySwap(T &a, T &b) {T tmp = a; a = b; b = tmp;}

// 排序算法
template<typename T>
void selectSort(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int maxInd = i;// 初始最大值下标
        for (int j = i+1; j < len; j++)
        {
            if (arr[j] > arr[maxInd]) {maxInd = j;}
        }
        // 交换两个元素
        if (maxInd != i) {mySwap<T>(arr[maxInd], arr[i]);}
    }
}

// 打印数组的模板
template<typename T>
void printArr(T arr[], int len)
{for (int i = 0; i < len; i++) {cout << arr[i] << ' ';} cout << endl;}

void test1()
{
    char charArr[] = {'d', 'c', '3', 'g', 's'};
    selectSort<char>(charArr, sizeof(charArr)/sizeof(char));
    printArr<char>(charArr, sizeof(charArr)/sizeof(char));

    int intArr[] = {4, 64, 345, 2453, 243, 4};
    selectSort<int>(intArr, sizeof(intArr)/sizeof(int));
    printArr<int>(intArr, sizeof(intArr)/sizeof(int));
}

int main()
{
    test1();
    return 0;
}
