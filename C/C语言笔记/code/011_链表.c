// Created by jackzhang on 2021/2/24.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 创建非循环单向链表
struct Node *createList(void);

void traverseList(struct Node *);

bool isEmptyList(struct Node *);

// 链表节点的数据类型
struct Node
{
	int data;    // 数据域
	struct Node *pNext;    // 指针域
};

int main(int argc, char **argv)
{
	struct Node *pHead = NULL;    // 头指针，用来存放链表头节点的地址

	pHead = createList();
	traverseList(pHead);

	return 0;
}

struct Node *createList(void)
{
	int len; // 存放有效节点个数
	int val;

	// 分配了一个不存放有效数据的头节点
	struct Node *pHead = (struct Node *) malloc(sizeof(struct Node));
	if (NULL == pHead)
	{
		printf("分配失败!\n");
		exit(-1);
	}

	struct Node *pTail = pHead;
	pTail->pNext = NULL;

	printf("请输入链表节点个数:\n");
	scanf("%d", &len);

	for (int i = 0; i < len; ++i)
	{
		printf("请输入第%d个节点的值:\n", i);
		scanf("%d", &val);

		struct Node *pNew = (struct Node *) malloc(sizeof(struct Node));
		if (NULL == pNew)
		{
			printf("分配失败!\n");
			exit(-1);
		}
		pNew->data = val;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
	}
	return pHead;
}

bool isEmptyList(struct Node *pHead)
{
	return NULL == pHead->pNext;
}

void traverseList(struct Node *pHead)
{
	if (isEmptyList(pHead)) // 空链表
	{
		printf("空链表.\n");
		return;
	}

	while (NULL != pHead->pNext)
	{
		// ++pHead; // 错误，链表不连续
		pHead = pHead->pNext;
		printf("%d ", pHead->data);
	}
}