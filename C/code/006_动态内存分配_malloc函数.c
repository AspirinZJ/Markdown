// Created by jackzhang on 2/23/21.
#include <stdio.h>
#include <malloc.h>

void test1();
void fun(int *);

int main(int argc, char **argv)
{
	test1();

	int *p = (int *) malloc(sizeof(int));    // 动态分配了int型所占空间的内存
	*p = 10;
	fun(p);
	// printf("*p: %d\n", *p); // p指向的地址已经被释放掉了

	return 0;
}

void test1()
{
	// int num = 0;	// 分配类4个字节，静态分配
	// int arr[5];	// 如果int占4个字节，那么分配了20个字节，每4个字节当作一个int变量使用

	// 指针指向了其指向变量的第一个字节，但是指针指向的地址长度由指针变量的类型指定
	// 如`int a = 0; int *p = &a;`, a长度为4,p只指向了第一个字节，长度4由`int *`指定。
	// p本身所占的内存是静态分配的，p指向的内存是动态分配的
	int *p = (int *) malloc(4);
	*p = 5;

	// p本身的内存是静态分配的，不能由程序员释放，只能p所在函数终止时由系统释放
	free(p);    // 表示把p所指向的内存释放掉，p所指向的内存内容无法再读写
}

void fun(int *p)
{
	*p = 100;
	printf("*p: %d\n", *p);
	free(p);
	p = NULL;
}
