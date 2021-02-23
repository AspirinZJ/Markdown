// Created by jackzhang on 2/18/21.


#include "administrator.h"

Administrator::Administrator() = default;

Administrator::Administrator(std::string name, std::string passwd)
{
	this->m_name = std::move(name);
	this->m_passwd = std::move(passwd);
	this->initVector();

	// 初始化机房信息
	std::ifstream ifs(COMPUTER_ROOM_FILE, std::ios::in);
	if (!ifs.is_open())
	{
		std::cout << "Error: cannot load computerRoom.txt.\n";
		ifs.close();
		return;
	}
	ComputerRoom com{};
	while (ifs >> com.m_computerRoomId && ifs >> com.m_maxNum) { this->vCom.push_back(com); }
	std::cout << "当前机房数量为： " << this->vCom.size() << std::endl;
	ifs.close();
}

// 操作菜单
void Administrator::operMenu()
{
	std::cout << "欢迎管理员：" << this->m_name << "登录.\n"
			  << "\t\t---------------------------------\n"
			  << "\t\t|                               |\n"
			  << "\t\t|        1. 添加帐号             |\n"
			  << "\t\t|                               |\n"
			  << "\t\t|        2. 查看帐号             |\n"
			  << "\t\t|                               |\n"
			  << "\t\t|        3. 查看机房             |\n"
			  << "\t\t|                               |\n"
			  << "\t\t|        4. 清空预约             |\n"
			  << "\t\t|                               |\n"
			  << "\t\t|        0. 注销登录             |\n"
			  << "\t\t|                               |\n"
			  << "\t\t---------------------------------\n"
			  << "请选择：\n";
}

// 添加帐号
// ID 不能重复
void Administrator::addAccount()
{
	std::cout << "1. 添加学生\n2. 添加教师\n";
	int select;
	std::cin >> select;
	if (select != 1 && select != 2)
	{
		std::cout << "输入错误.\n";
		return;
	}

	std::string fileName = (select == 1 ? STUDENT_FILE : TEACHER_FILE);
	std::ofstream ofs(fileName, std::ios::out | std::ios::app); // 利用追加的方式写入文件
	if (!ofs.is_open())
	{
		std::cerr << "Error: cannot open file!\n";
		return;
	}

	int id;
	std::string name, passwd;

	std::string tip = (select == 1 ? "请输入学号：\n" : "请输入教师号：\n");
	std::cout << tip;
	std::cin >> id;
	// 检查是否重复
	while (true)
	{
		if (this->checkRepeat(id, select))
		{
			std::cout << "id号重复， 请重新输入id.\n";
			std::cin >> id;
		}
		else { break; }
	}
	std::cout << "请输入姓名：\n";
	std::cin >> name;
	std::cout << "请输入密码:\n";
	std::cin >> passwd;

	ofs << id << " " << name << " " << passwd << " " << std::endl;
	std::cout << "添加成功! \n";
	ofs.close();

	// 由于新添加了用户，重新初始化数据
	this->initVector();
}

// 查看帐号
void Administrator::showAccountInfo()
{
	std::cout << "请输入查看内容: \n1. 查看所有学生.\n2. 查看所有教师.\n";
	int select;
	std::cin >> select;

	if (1 == select)
	{
		std::cout << "所有学生信息如下: \n";
		std::for_each(this->vStudent.begin(), this->vStudent.end(), printStudent);
	}
	else if (2 == select)
	{
		std::cout << "所有教师信息如下：\n";
		std::for_each(this->vTeacher.begin(), this->vTeacher.end(), printTeacher);
	}
	else
	{
		std::cout << "Wrong input number.\n";
	}
}

// 查看机房信息
void Administrator::showComputerRoomInfo()
{
	for (auto cit : this->vCom)
	{
		std::cout << "Id: " << cit.m_computerRoomId << ". Max number: " << cit.m_maxNum << std::endl;
	}
}

// 清空所有预约
void Administrator::clearOrder()
{
	std::ofstream ofs(ORDER_FILE, std::ios::trunc); // std::ios::trunc， 先删除原有文件再写入内容，相当于清空
	if (!ofs.is_open())
	{
		std::cerr << "Error: cannot open " << ORDER_FILE << std::endl;
		ofs.close();
		return;
	}
	ofs.close();
	std::cout << "清空成功！\n";
}

// 初始化学生容器和教师容器
void Administrator::initVector()
{
	// 读取学生信息
	std::ifstream ifs(STUDENT_FILE, std::ios::in);
	if (!ifs.is_open())
	{
		std::cerr << "Error: cannot open file!\n";
		return;
	}

	this->vStudent.clear();
	this->vTeacher.clear();

	Student stu;
	while (ifs >> stu.m_id && ifs >> stu.m_name && ifs >> stu.m_passwd) { this->vStudent.push_back(stu); }
	std::cout << "学生数量为：" << vStudent.size() << std::endl;
	ifs.close();

	// 读取教师信息
	ifs.open(TEACHER_FILE, std::ios::in);
	if (!ifs.is_open())
	{
		std::cerr << "Error: cannot open file!\n";
		return;
	}

	Teacher teacher;
	while (ifs >> teacher.m_empId && ifs >> teacher.m_name && ifs >> teacher.m_passwd) { vTeacher.push_back(teacher); }
	std::cout << "教师数量为：" << vTeacher.size() << std::endl;
}

// 检测新添加的学生或教师id是否和已有的重复. type: 1. Student 2. Teacher
bool Administrator::checkRepeat(int id, int type)
{
	if (1 == type)    // Student
	{
		for (const auto &cit : this->vStudent) { if (cit.m_id == id) { return true; }}
	}
	else    // Teacher
	{
		/*
				for (std::vector<Teacher>::const_iterator cit = this->vTeacher.begin(); cit != this->vTeacher.end(); ++cit)
				{
					if (cit->m_empId == id) { return true; }
				}
		*/
		for (const auto &cit : this->vTeacher) { if (cit.m_empId == id) { return true; }}
	}
	return false;
}

void printStudent(Student &stu)
{
	std::cout << "ID: " << stu.m_id << ". Name: " << stu.m_name << ". Passwd: " << stu.m_passwd << std::endl;
}

void printTeacher(Teacher &teacher)
{
	std::cout << "ID: " << teacher.m_empId << ". Name: " << teacher.m_name << ". Passwd: " << teacher.m_passwd
			  << std::endl;
}
