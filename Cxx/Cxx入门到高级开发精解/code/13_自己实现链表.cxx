// 实现链表
#include <iostream>

using namespace std;

// 用结构体表示一个学生的节点
typedef struct node
{
	char name[20];
	int age;
	struct node *next;
} Student; // 以后Student就是struct node 的同名

// 创建链表函数
Student *createList(int n) // n:节点个数
{
	//Student head; // 栈上函数运行后会被释放掉
	Student *head = new Student; // 头节点, 存放在堆上
	// 一般头节点不用来存储数据，只作为遍历的头

	Student *pre = head; // 记录上一个节点

	for (int i = 0; i < n; ++i)
	{
		Student *p = new Student;
		printf("Please input the name and age of the %d th student.\n", i + 1);
		cin >> p->name >> p->age;
		pre->next = p; // 让上一个节点的指针指向此节点
		pre = p; // 存储pre的指向为此节点
		p->next = NULL;
	}

	return head;
}

int getLength(Student *head)
{
	Student *p = head->next;
	int len = 0;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

void insertElement(Student *head, int index) // index 是插入位置
{
	if (index < 0 || index > getLength(head)) { throw "Error: out of range"; }
	Student *pre = head;

	for (int i = 0; i < index; ++i) { pre = pre->next; }

	Student *newNode = new Student;
	cout << "Input the name and age of new student.\n";
	cin >> newNode->name >> newNode->age;

	newNode->next = pre->next;
	pre->next = newNode;
}

void removeElement(Student *head, int index)
{
	if (index < 0 || index > getLength(head) - 1) {throw "Error: out of range";}
	Student *pre = head;

	for (int i = 0; i < index; ++i) { pre = pre->next;}
	Student *p = pre->next; // p就是要删除的节点
	pre->next = p->next;
	delete p;
}

void displayList(Student *head)
{
	Student *p = head->next;
	while (p != NULL)
	{
		cout << p->name << " " << p->age << endl;
		p = p->next;
	}
}

int main()
{
	int n = 2;
	Student *sList = createList(n);
	displayList(sList);
	cout << "Length of the list: " << getLength(sList) << endl;
	insertElement(sList, 2);
	displayList(sList);

	int index;
	cout << "Please input the index of the node you want to delete: \n";
	cin >> index;
	removeElement(sList, index);
	displayList(sList);

	return 0;
}