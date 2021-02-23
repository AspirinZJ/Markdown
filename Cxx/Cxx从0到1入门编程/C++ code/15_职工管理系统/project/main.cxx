#include <iostream>
#include "workerManager.h"

using namespace std;

int main()
{
	WorkerManager wm;
	int choice; // store the choice of the user

	while (true)
	{
		WorkerManager::showMenu();
		cout << "请输入选项: " << endl;
		cin >> choice;

		switch (choice)
		{
			case 0: // 退出系统
				return 0;
			case 1: // 增加职工
				wm.AddEmp();
				break;
			case 2: // 显示职工
				wm.showEmp();
				break;
			case 3: // 删除职工
				wm.delEmp();
				break;
			case 4: // 修改职工
				wm.modEmp();
				break;
			case 5: // 查找职工
				wm.findEmp();
				break;
			case 6: // 排序职工
				wm.sortEmp();
				break;
			case 7: // 清空数据
				wm.cleanFile();
				break;
			default:
				WorkerManager::showMenu();
		}
	}
}
