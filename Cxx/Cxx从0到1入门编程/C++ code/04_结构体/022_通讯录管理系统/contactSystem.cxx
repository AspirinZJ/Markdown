// 通讯录系统中的功能如下：
// 1. 添加联系人：包括姓名、性别、年龄、联系电话和家庭住址，上限1000
// 2. 显示联系人：
// 3. 删除联系人：按照姓名删除
// 4. 查找联系人：按照姓名查找
// 5. 修改联系人：
// 6. 清空联系人：
// 7. 退出通讯录系统：
#include <iostream>
#include <string>

#define MAX_USER 1000

using namespace std;

struct Person   // 联系人结构体
{
	string mName;
	char mSex;
	int mAge;
	string mPhoneNum;
	string mAddress;
};

struct ContactBook  // 通讯录结构体
{
	Person personArr[MAX_USER];
	int numUser;    // 当前通讯录人数个数
};

void showMenu(); // 封装函数voidShow()显示菜单
void addContact(ContactBook *pContactBook); // 往通讯录添加联系人函数
void showContactInfo(const ContactBook *pContactBook); // 显示通讯录中的联系人
int ifContactExist(const ContactBook *pContactBook, const string &name); // 判断联系人是否存在，返回联系人的位置，不存在返回1
void deleteContact(ContactBook *pContactBook); // 删除联系人
void searchContact(const ContactBook *pContactBook); // 查找联系人
void changeContact(ContactBook *pContactBook); // 修改联系人信息
void clearContact(ContactBook *pContactBook); // 清空联系人

int main()
{
	ContactBook contactBook;
	contactBook.numUser = 0;
	int userChoice = 0; // 创建用户输入变量

	while (true)
	{
		showMenu();

		cin >> userChoice;
		switch (userChoice)
		{
			case 1: // 添加联系人
				addContact(&contactBook);
				break;
			case 2: // 显示联系人
				showContactInfo(&contactBook);
				break;
			case 3: // 删除联系人
				deleteContact(&contactBook);
				break;
			case 4: // 查找联系人
				searchContact(&contactBook);
				break;
			case 5: // 修改联系人
				changeContact(&contactBook);
				break;
			case 6: // 清空通讯录
                clearContact(&contactBook);
				break;
			case 0: // 退出
				cout << "欢迎下次使用" << endl;
				return 0;
			default:
				break;
		}
	}
}

void showMenu()
{
	cout << "*************************" << endl;
	cout << "***** 1. 添加联系人 *****" << endl;
	cout << "***** 2. 显示联系人 *****" << endl;
	cout << "***** 3. 删除联系人 *****" << endl;
	cout << "***** 4. 查找联系人 *****" << endl;
	cout << "***** 5. 修改联系人 *****" << endl;
	cout << "***** 6. 清空通讯录 *****" << endl;
	cout << "***** 0. 退出通讯录 *****" << endl;
	cout << "*************************" << endl;
}

void addContact(ContactBook *pContactBook) // 往通讯录添加联系人函数
{
	if (pContactBook->numUser >= MAX_USER)
	{
		cout << "通讯录已满" << endl;
		return;
	}
	else
	{
		// 姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		pContactBook->personArr[pContactBook->numUser].mName = name;

		// 性别
		while (true)
		{
			char sex;
			cout << "请输入性别" << endl;
			cin >> sex;
			if ('F' == sex || 'M' == sex)
			{
				pContactBook->personArr[pContactBook->numUser].mSex = sex;
				break;
			}
			else
			{
				cout << "输入有误" << endl;
			}
		}

		// 年龄
		int age;
		cout << "请输入年龄" << endl;
		cin >> age;
		pContactBook->personArr[pContactBook->numUser].mAge = age;

		// 电话
		string phoneNum;
		cout << "请输入电话" << endl;
		cin >> phoneNum;
		pContactBook->personArr[pContactBook->numUser].mPhoneNum = phoneNum;

		// 住址
		string address;
		cout << "请输入地址" << endl;
		cin >> address;
		pContactBook->personArr[pContactBook->numUser].mAddress = address;

		system("clear"); // 清屏操作
		cout << "添加成功" << endl;

		pContactBook->numUser++;
	}
}


void showContactInfo(const ContactBook *pContactBook) // 显示通讯录中的联系人
{
	if (0 == pContactBook->numUser)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < pContactBook->numUser; i++)
		{
			cout << "Name: " << pContactBook->personArr[i].mName
				 << " Sex: " << (pContactBook->personArr[i].mSex == 'M' ? "Male" : "Female")
				 << " Age: " << pContactBook->personArr[i].mAge
				 << " Phone: " << pContactBook->personArr[i].mPhoneNum
				 << " Address: " << pContactBook->personArr[i].mAddress
				 << endl;
		}
	}

}

int ifContactExist(const ContactBook *pContactBook, const string &name)
{
	for (int i = 0; i < pContactBook->numUser; i++)
	{
		if (name == pContactBook->personArr[i].mName) { return i; } // 找到则返回此人在数组中的下标
	}
	return -1;
}

void deleteContact(ContactBook *pContactBook)
{
	cout << "请输入要删除的联系人" << endl;
	string name;
	cin >> name;
	int ret = ifContactExist(pContactBook, name);
	if (ret != -1)
	{
		for (int i = ret; i < pContactBook->numUser; i++)
		{
			pContactBook->personArr[i] = pContactBook->personArr[i + 1];
		}
		pContactBook->numUser--;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "没有此人，请重新输入" << endl;
	}
}

void searchContact(const ContactBook *pContactBook)
{
	cout << "请输入查找的联系人" << endl;
	string name;
	cin >> name;

	int ret = ifContactExist(pContactBook, name);
	if (-1 != ret)
	{
		cout << "Name: " << pContactBook->personArr[ret].mName << " Sex: " << pContactBook->personArr[ret].mSex
			 << " Age: " << pContactBook->personArr[ret].mAge << " Phone: " << pContactBook->personArr[ret].mPhoneNum
			 << " Address: " << pContactBook->personArr[ret].mAddress << endl;
	}
	else
	{
		cout << "No such a person!" << endl;
	}
}

void changeContact(ContactBook *pContactBook)
{
	cout << "请输入要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = ifContactExist(pContactBook, name);
	if (-1 != ret)
	{
		cout << "请输入要修改的项\n1:Name, 2:Sex, 3:Age, 4:Phone, 5:Address\n";
		int choice;
		cin >> choice;
		switch (choice)
		{
			case 1:
			{
				cout << "请输入：\n";
				string newName;
				cin >> newName;
				pContactBook->personArr[ret].mName = newName;
			}
				break;
			case 2:
			{
				cout << "请输入：\n";
				char newSex;
				cin >> newSex;
				pContactBook->personArr[ret].mSex = newSex;
			}
				break;
			case 3:
			{
				cout << "请输入：\n";
				int newAge;
				cin >> newAge;
				pContactBook->personArr[ret].mAge = newAge;
			}
				break;
			case 4:
			{
				cout << "请输入：\n";
				string newPhone;
				cin >> newPhone;
				pContactBook->personArr[ret].mPhoneNum = newPhone;
			}
				break;
			case 5:
			{
				cout << "请输入：\n";
				string newAddress;
				cin >> newAddress;
				pContactBook->personArr[ret].mAddress = newAddress;
			}
				break;
			default:
			{
				cout << "Wrong Input\n";
			}
				break;
		}
	}
	else
	{
		cout << "未找到联系人" << endl;
	}
}


void clearContact(ContactBook *pContactBook)
{
    pContactBook->numUser = 0;  // 只需要将联系人数量设置为0即可
    system("clear");
    cout << "Clear Successfully" << endl;
}
