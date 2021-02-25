// Created by jackzhang on 2021/2/23.
#include <stdio.h>

void bubbleSort(int *, int);
void swapInt(int *, int *);

int main(int argc, char **argv)
{
	int arr[] = {134, 4, 2, 1234, 4, 434, 1, 3, 23, 324, 21, 3215, 62, 2435, 234};
	int len = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, len);
	for (int i = 0; i < len; ++i) { printf("%d ", arr[i]); }

	return 0;
}

void bubbleSort(int *arr, int len)
{
	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = 0; j < len - 1 - i; ++j)
		{
			if (arr[j] > arr[j + 1]) { swapInt(arr + j, arr + j + 1); }
		}
	}
}

void swapInt(int *p, int *q)
{
	int tmp = *p;
	*p = *q;
	*q = tmp;
}