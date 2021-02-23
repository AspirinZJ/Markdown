// Created by jackzhang on 2/23/21.
#include <stdio.h>

void printArr(const int *, unsigned int);

int main(int argc, char **argv)
{
	int a[10] = {1, 2, 3};
	int b[5];
	// a = b;	// 错误，一维数组名是一个指针常量

	// 一维数组名存放第一个元素的地址
	printf("%#X\n%#X\n", &a[0], a);

	printArr(a, 10);

	// 指针变量不能相加，相乘，相除，如果两个指针变量指向的是同一快连续空间中的不同存储单元，则这两个指针变量可以相减
	int *p = a;
	int *q = &a[2];
	printf("p和q相隔: %ld个单元.\n", q - p);

	// 64位指针变量占用的内存大小为8, 32位指针变量占用内存大小为4。 无论什么类型的指针
	printf("size of int *: %lu, char *: %lu, double *: %lu", sizeof(int *), sizeof(char *), sizeof(double *));

	return 0;
}

// 确定一个一维数组需要地址和长度两个
void printArr(const int *arr, unsigned int len)
{
	for (int i = 0; i < len; ++i) { printf("%d ", *(arr + i)); }
	printf("\n");
}