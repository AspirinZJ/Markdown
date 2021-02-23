#include "workerManager.h"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		// 1. 数据文件不存在
		cout << "Error: cannot open file." << endl;
		this->m_isEmpty = true;
		this->m_empNum = 0;
		this->pEmpArr = nullptr;
		ifs.close();
		return;
	}
	else
	{
		// 2. 文件存在，数据为空
		char ch;
		ifs >> ch;
		if (ifs.eof()) // 读到了文件尾，文件为龙
		{
			cout << "File is Empty." << endl;
			this->m_isEmpty = true;
			this->m_empNum = 0;
			this->pEmpArr = nullptr;
			ifs.close();
			return;
		}

		// 3. 文件存在，并且已经有数据
		int empNum = WorkerManager::getEmpNum(); // 获取文件中员工人数
		cout << "The number of workers: " << empNum << endl;
		this->m_empNum = empNum;
		this->pEmpArr = new Worker *[this->m_empNum];// 开辟空间
		this->initEmp(); // 初始化
		this->m_isEmpty = false;
		// for (int i = 0; i < this->m_empNum; i++) {this->pEmpArr[i]->ShowInfo();} // 输出员工信息
	}
}

int WorkerManager::getEmpNum() // 统计文件中人数
{
	ifstream ifs(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int empNum = 0;

	while (ifs >> id && ifs >> name && ifs >> did) { empNum++; }

	ifs.close();

	return empNum;
}

void WorkerManager::initEmp() const
{
	ifstream ifs(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker *pWorker;

		if (1 == did) { pWorker = new Employee(id, name, did); }
		else if (2 == did) { pWorker = new Manager(id, name, did); }
		else { pWorker = new Boss(id, name, did); }

		this->pEmpArr[index] = pWorker;
		index++;
	}
	ifs.close();
}

WorkerManager::~WorkerManager()
{
	if (this->pEmpArr != nullptr)
	{
		for (int i = 0; i < this->m_empNum; i++)
		{
			if (this->pEmpArr[i] != nullptr)
			{
				delete this->pEmpArr[i];
				this->pEmpArr[i] = nullptr;
			}
		}
		delete[] pEmpArr;
		this->pEmpArr = nullptr;
	}
}

void WorkerManager::showMenu()
{
	cout << "************************************" << endl;
	cout << "************0.退出管理系统**********" << endl;
	cout << "************1.增加职工信息**********" << endl;
	cout << "************2.显示职工信息**********" << endl;
	cout << "************3.删除离职职工**********" << endl;
	cout << "************4.修改职工信息**********" << endl;
	cout << "************5.查找职工信息**********" << endl;
	cout << "************6.按照编号排序**********" << endl;
	cout << "************7.清空所有文档**********" << endl;
	cout << "************************************" << endl;
}

void WorkerManager::showEmp() const    // 展示员工信息
{
	if (this->m_isEmpty)
	{
		cout << "No worker." << endl;
		return;
	}
	else
	{
		for (int i = 0; i < this->m_empNum; i++) this->pEmpArr[i]->ShowInfo();
		return;
	}
}

void WorkerManager::save() const
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	if (!ofs.is_open())
	{
		cout << "Cannot open file." << endl;
		ofs.close();
		return;
	}
	else
	{
		for (int i = 0; i < this->m_empNum; i++)
		{
			ofs << this->pEmpArr[i]->m_id << ' ' << this->pEmpArr[i]->m_name << ' ' << this->pEmpArr[i]->m_deptId
				<< endl;
		}
		ofs.close();
	}
}

void WorkerManager::AddEmp()
{
	int num;
	cout << "Input the number of workers you want to add: " << endl;
	cin >> num;

	if (num > 0)
	{
		int newSize = this->m_empNum + num; // new number of workers

		auto **newSpace = new Worker *[newSize];
		// copy old data to new space
		if (nullptr != this->pEmpArr)
		{
			for (int i = 0; i < this->m_empNum; i++) { newSpace[i] = this->pEmpArr[i]; }
		}

		// Add new information
		for (int j = 0; j < num; j++)
		{
			int id;
			string name;
			int did;
			cout << "Input the " << (j + 1) << "th id of the worker" << endl;
			cin >> id;
			cout << "Input tht " << (j + 1) << "th worker's name." << endl;
			cin >> name;
			cout << "Choose the department of the " << (j + 1) << "th worker." << endl;
			cout << "1. Employee \n2. Manager\n3. Boss" << endl;
			cin >> did;

			Worker *worker = nullptr;
			switch (did)
			{
				case 1:
					cout << "id is: " << id << endl;
					worker = new Employee(id, name, did);
					break;
				case 2:
					worker = new Manager(id, name, did);
					break;
				case 3:
					worker = new Boss(id, name, did);
					break;
				default:
					cout << "Wrong department." << endl;
					break;
			}
			newSpace[j + this->m_empNum] = worker;
		}
		delete[] this->pEmpArr; // 释放原有空间
		this->pEmpArr = newSpace; // 更新新空间指向
		this->m_empNum = newSize; // 更新职工人数
		this->m_isEmpty = false;    // 数据不为空
		this->save(); // 保存数据到文件
		cout << "添加成功" << endl;
	}
	else { cout << "Wrong input number." << endl; }
}

int WorkerManager::isExist(int id) const // 根据编号判断职工是否存在，如果存在，返回所咋数组的位置
{
	int index = -1;
	for (int i = 0; i < this->m_empNum; i++)
	{
		if (this->pEmpArr[i]->m_id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

int WorkerManager::isExist(const string &name) const // 根据姓名进行查找，如果存在，返回所在数组的位置
{
	int index = -1;
	for (int i = 0; i < this->m_empNum; i++)
	{
		if (this->pEmpArr[i]->m_name == name)
		{
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::delEmp()
{
	if (this->m_isEmpty) { cout << "记录为空." << endl; }
	int id;
	cout << "请输入想删除的员工id." << endl;
	cin >> id;
	int ret = this->isExist(id);

	if (ret != -1)
	{
		for (int i = ret; i < this->m_empNum - 1; i++)
		{
			this->pEmpArr[i] = this->pEmpArr[i + 1];
		}
		this->m_empNum--; // 员工人数减1
		this->save(); //同步数据到文件中
		cout << "Delete successfully." << endl;
	}
	else { cout << "No such worker." << endl; }

}

void WorkerManager::modEmp() const // 修改员工信息
{
	if (this->m_isEmpty) { cout << "No worker." << endl; }
	else
	{
		int id;
		cout << "Input id." << endl;
		cin >> id;

		int ret = this->isExist(id);
		if (-1 != ret)
		{
			delete this->pEmpArr[ret]; // 删除原有的数据
			int newId = 0;
			string newName;
			int newDid = 0;
			cout << "New id: " << endl;
			cin >> newId;
			cout << "New Name: " << endl;
			cin >> newName;
			cout << "New Dept: " << endl;
			cin >> newDid;

			Worker *pWorker = nullptr;

			switch (newDid) // 增加啊新数据
			{
				case 1:
					pWorker = new Employee(newId, newName, newDid);
					break;
				case 2:
					pWorker = new Manager(newId, newName, newDid);
					break;
				case 3:
					pWorker = new Boss(newId, newName, newDid);
					break;
				default:
					cout << "Wrong id" << endl;
			}

			this->pEmpArr[ret] = pWorker;
			cout << "Successfully changed." << endl;
			this->save();
		}
		else { cout << "No such worker." << endl; }
	}
}

void WorkerManager::findEmp() const // 查找员工信息
{
	if (this->m_isEmpty) { cout << "No file data." << endl; }
	else
	{
		int select;
		cout << "输入查找方式: 1. 按照编号查找  2. 按照姓名查找" << endl;
		cin >> select;

		if (1 == select)
		{
			int id;
			cout << "输入查找编号" << endl;
			cin >> id;
			int ret = this->isExist(id);
			if (-1 != ret) { this->pEmpArr[ret]->ShowInfo(); }
			else { cout << "No such worker." << endl; }
		}
		else if (2 == select)
		{
			string name;
			cout << "输入查找姓名:" << endl;
			cin >> name;
			int ret = this->isExist(name);
			if (-1 != ret) { this->pEmpArr[ret]->ShowInfo(); }
			else { cout << "No such worker." << endl; }
		}
		else { cout << "Wrong Input." << endl; }
	}
}

void WorkerManager::sortEmp() const // 员工排序
{
	if (this->m_isEmpty) { cout << "No file data." << endl; }
	else
	{
		int sortOpt;
		cout << "1. 升序 2. 降序" << endl;
		cin >> sortOpt;

		for (int i = 0; i < this->m_empNum; i++)
		{
			int minMaxInd = i; // init index of min or max element
			for (int j = i + 1; j < this->m_empNum; j++)
			{
				if (1 == sortOpt)
				{
					if (this->pEmpArr[j] < this->pEmpArr[minMaxInd]) { minMaxInd = j; }
				}
				else if (2 == sortOpt)
				{
					if (this->pEmpArr[j] > this->pEmpArr[minMaxInd]) { minMaxInd = j; }
				}
			}

			if (i != minMaxInd) // 交换元素
			{
				Worker *pTmp = this->pEmpArr[i];
				this->pEmpArr[i] = this->pEmpArr[minMaxInd];
				this->pEmpArr[minMaxInd] = pTmp;
			}
		}
	}

	this->save(); // 保存到文件
	cout << "The sorted data is: " << endl;
	this->showEmp();
}

void WorkerManager::cleanFile() // 清空文件
{
	char select;
	cout << "确定清空? Y/N" << endl;
	cin >> select;

	if ('Y' == select || 'y' == select)
	{
		ofstream ofs(FILENAME, ios::trunc); // ios::trunc删除文件后重新创建，类似于清空文件
		ofs.close();

		// 删除堆区的每个职工对象
		if (!this->m_isEmpty)
		{
			for (int i = 0; i < this->m_empNum; i++)
			{
				delete this->pEmpArr[i];
				this->pEmpArr[i] = nullptr;
			}
		}
		// 删除堆区数组指针
		delete[] this->pEmpArr;
		this->pEmpArr = nullptr;
		this->m_empNum = 0;
		this->m_isEmpty = true;

		cout << "Clear successfully." << endl;
	}
}
