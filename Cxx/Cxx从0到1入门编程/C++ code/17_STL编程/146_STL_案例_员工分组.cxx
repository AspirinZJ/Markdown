// 公司新招聘10名员工，需要指派员工字在哪个部门工作
// 员工信息有：姓名，工资组成
// 部门分为：策划，美术，研发
// 随机给10名员工分配部门和工资
// 通过multimap进行信息的插入，key(部门编号)和value(员工)
// 分部门显示信息
#include <iostream>
#include <ctime>
#include <vector>
#include <map>
#include <string>

#define PLANNING 0
#define ART 1
#define RESEARCH 2

using namespace std;

class CWorker
{
public:
//	CWorker(string name, int salary)
//	{ this->m_name = name, this->m_salary = salary; }

	string m_name;
	int m_salary;
};

void createWorker(vector <CWorker> &vec)
{
	string nameSeed = "0123456789";
	for (int i = 0; i < 10; i++)
	{
		CWorker worker;
		worker.m_name = "Worker_";
		worker.m_name += nameSeed[i];
		worker.m_salary = rand() % 10000 + 10000;
		vec.push_back(worker);
	}
}

void setGroup(const vector <CWorker> &vec, multimap<int, CWorker> &mmp)
{
	for (vector<CWorker>::const_iterator wit = vec.begin(); wit != vec.end(); ++wit)
	{
		int depId = rand() % 3;
		// 将员工插入到分组中
		mmp.insert(pair<int, CWorker>(depId, *wit)); // key是编号，value是员工
	}

/*
	for (multimap<int, CWorker>::iterator it = mmp.begin(); it != mmp.end(); ++it)
	{cout << "DeptId: " << it->first << ". Name: " << (*it).second.m_name << ". Salary: " << it->second.m_salary << endl;}
	cout << endl;
*/
}

void showWorkerByGroup(const multimap<int, CWorker> &mpWorker)
{
	cout << "Planning department info: " << endl;
	multimap<int, CWorker>::const_iterator pos = mpWorker.find(PLANNING);
	int count = mpWorker.count(PLANNING);
	while (count > 0)
	{
		cout << "Name :" << pos->second.m_name << ". Salary: " << (*pos).second.m_salary << endl;
		++pos;
		--count;
	}

	cout << "Art department info: " << endl;
	pos = mpWorker.find(ART);
	count = mpWorker.count(ART);
	while (count > 0)
	{
		cout << "Name :" << pos->second.m_name << ". Salary: " << (*pos).second.m_salary << endl;
		++pos;
		--count;
	}

	cout << "Research department info: " << endl;
	pos = mpWorker.find(RESEARCH);
	count = mpWorker.count(RESEARCH);
	while (count > 0)
	{
		cout << "Name :" << pos->second.m_name << ". Salary: " << (*pos).second.m_salary << endl;
		++pos;
		--count;
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	// 1. 创建员工vector
	vector <CWorker> vWorker;
	createWorker(vWorker);

	// 2. 员工分组
	multimap<int, CWorker> mpWorker;
	setGroup(vWorker, mpWorker);

	// 3. 分组显示员工
	showWorkerByGroup(mpWorker);

	return 0;
}
