#include <iostream>
#include <fstream>

#include "identity.h"
#include "global.h"
#include "student.h"
#include "administrator.h"
#include "teacher.h"
#include "order.h"

// 登录函数，根据用户的选择，进入不同的身份登录
// type: 1. Teacher 2. Student 3. Administrator
void logIn(const std::string &fileName, int type);

// 管理员子菜单
// 功能：添加帐号、查看帐号、查看机房、清空预约、注销登录
void adminMenu(Identity *&identity);

// 学生子菜单
void studentMenu(Identity *&identity);

// 教师子菜单
void teacherMenu(Identity *&identity);

int main()
{
	Order order;
	order.updateOrder();
	int select;
	while (true)
	{
		std::cout << "欢迎来到机房预约系统\n\n"
				  << "请输入您的身份：\n"
				  << "\t\t----------------------------\n"
				  << "\t\t|                          |\n"
				  << "\t\t|        1. 学生代表        |\n"
				  << "\t\t|                          |\n"
				  << "\t\t|        2. 教师            |\n"
				  << "\t\t|                          |\n"
				  << "\t\t|        3. 管理员          |\n"
				  << "\t\t|                          |\n"
				  << "\t\t|        0. 退出            |\n"
				  << "\t\t|                          |\n"
				  << "\t\t----------------------------\n";
		std::cout << "请输入您的选择：\n";
		std::cin >> select;

		switch (select)
		{
			case 1:    // 学生
				logIn(STUDENT_FILE, 1);
				break;
			case 2:    // 老师
				logIn(TEACHER_FILE, 2);
				break;
			case 3:    // 管理员
				logIn(ADMIN_FILE, 3);
				break;
			case 0:    // 退出
				std::cout << "Quitting system...\n";
				return 0;
			default:
				std::cout << "Wrong input.\n";
				break;
		}
		system("clear");
	}
}

void logIn(const std::string &fileName, int type)
{
	Identity *person = nullptr;    //	父类指针，用于指向子类对象

	//	读文件
	// TODO: close it
	std::ifstream ifs(fileName, std::ios::in);
	if (!ifs.is_open())
	{
		std::cout << "File does not exist.\n";
		ifs.close();
		return;
	}

	// 准备接收用户的信息
	int id;
	std::string name;
	std::string passwd;

	if (1 == type) // 学生身份
	{
		std::cout << "请输入学号：" << std::endl;
		std::cin >> id;
	}
	else if (2 == type)    //	教师身份
	{
		std::cout << "请输入教师号：" << std::endl;
		std::cin >> id;
	}
	std::cout << "请输入用户名：" << std::endl;
	std::cin >> name;
	std::cout << "请输入密码: " << std::endl;
	std::cin >> passwd;

	// 身份验证
	if (1 == type)    // 学生身份
	{
		// 文件中的id，name和passwd
		int fId;
		std::string fName, fPasswd;

		while (ifs >> fId && ifs >> fName && ifs >> fPasswd)
		{
			if (fId == id && fName == name && fPasswd == passwd)
			{
				std::cout << "student login successfully.\n";
				person = new Student(id, name, passwd);
				studentMenu(person);
				ifs.close();
				return;
			}
		}
	}
	else if (2 == type) // 教师身份
	{
		int fId;
		std::string fName, fPasswd;

		while (ifs >> fId && ifs >> fName && ifs >> fPasswd)
		{
			if (fId == id && fName == name && fPasswd == passwd)
			{
				std::cout << "teacher login successfully.\n";
				person = new Teacher(id, name, passwd);
				teacherMenu(person);
				ifs.close();
				return;
			}
		}
	}
	else if (3 == type)    //	管理员身份
	{
		std::string fName, fPasswd;

		while (ifs >> fName && ifs >> fPasswd)
		{
			if (fName == name && fPasswd == passwd)
			{
				std::cout << "admin login successfully.\n";
				person = new Administrator(name, passwd);
				adminMenu(person);
				ifs.close();
				return;
			}
		}
	}

	std::cout << "Failed to login.\n";
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 注意，这里传递的是指针的引用
// 如果直接传递指针的话，传递的是指针的值，即使在函数内部修改指针，也不会影响到实际的指针
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void adminMenu(Identity *&identity)
{
	while (true)
	{
		identity->operMenu(); // 多态，admin可以调用子类重写的虚函数
		auto *pAdmin = (Administrator *) identity; // 转换之后，可以调用子类里特有的接口

		int select;
		std::cin >> select;

		switch (select)
		{
			case 1: // 添加帐号
				pAdmin->addAccount();
				break;
			case 2: // 查看帐号
				pAdmin->showAccountInfo();
				break;
			case 3: // 查看机房
				pAdmin->showComputerRoomInfo();
				break;
			case 4: // 清空预约
				pAdmin->clearOrder();
				break;
			default: // 注销
				delete identity;
				std::cout << "log out successfully.\n";
				return;
		}
	}
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 注意，这里传递的是指针的引用
// 如果直接传递指针的话，传递的是指针的值，即使在函数内部修改指针，也不会影响到实际的指针
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void studentMenu(Identity *&identity)
{
	while (true)
	{
		identity->operMenu();    // 多态
		auto *pStu = (Student *) identity;    // 转换成子类指针

		int select;
		std::cout << "请输入选项：\n";
		std::cin >> select;

		switch (select)
		{
			case 1:    // 申请预约
				pStu->applyOrder();
				break;
			case 2: // 查看自身预约
				pStu->showMyOrder();
				break;
			case 3: // 查看所有预约
				pStu->showAllOrder();
				break;
			case 4: // 取消预约
				pStu->cancelOrder();
				break;
			default: // 注销登录
				delete identity;
				std::cout << "注销成功.\n";
				return;
		}
	}
}

void teacherMenu(Identity *&identity)
{
	while (true)
	{
		identity->operMenu();
		auto *pTeacher = (Teacher *) identity;
		int select = 0;
		std::cin >> select;

		switch (select)
		{
			case 1:    // 查看所有预约
				pTeacher->showAllOrder();
				break;
			case 2:    // 审核预约
				pTeacher->validOrder();
				break;
			case 0:
				delete identity;
				std::cout << "注销成功.\n";
				return;
			default:
				std::cout << "输入有误，请重新输入.\n";
				break;
		}
	}
}