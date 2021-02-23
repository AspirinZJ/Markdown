#include <iostream>
#include <queue>
#include <string>

using namespace std;

class CPerson
{
public:
	CPerson(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	string m_name;
	int m_age;
};

int main()
{
	queue <CPerson> que;
	CPerson person1("Alice", 19);
	CPerson person2("Bob", 20);
	CPerson person3("Charlie", 21);
	que.push(person1);
	que.push(person2);
	que.push(person3);
	cout << "Queue size: " << que.size() << endl;

	// 只要队列不为空，查看队头和队尾，做出队操作
	while (!que.empty())
	{
		cout << "Queue front: " << que.front().m_name << ' ' << que.front().m_age << endl;
		cout << "Queue back: " << que.back().m_name << ' ' << que.back().m_age << endl;
		que.pop();
	}
	cout << "Queue size: " << que.size() << endl;

	return 0;
}
