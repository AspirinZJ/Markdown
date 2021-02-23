// Created by jackzhang on 2/18/21.

#ifndef INC_20__ADMINISTRATOR_H
#define INC_20__ADMINISTRATOR_H

#include <vector>
#include <utility>
#include <iostream>
#include <fstream>
#include <algorithm>

#include "identity.h"
#include "global.h"
#include "student.h"
#include "teacher.h"
#include "computerRoom.h"

void printStudent(Student &);
void printTeacher(Teacher &);


class Administrator : public Identity
{
public:
	Administrator();
	Administrator(std::string name, std::string passwd);
	void operMenu() override;    // 选择菜单
	void addAccount();    // 添加帐号
	void showAccountInfo();    // 查看帐号
	void showComputerRoomInfo();    // 查看机房信息
	static void clearOrder();    //	清空预约记录
	void initVector(); // 初始化学生容器和教师容器
	bool checkRepeat(int id, int type);	 // 检测新添加的学生或教师id是否和已有的重复

	std::vector<Student> vStudent; // 学生容器
	std::vector<Teacher> vTeacher;  // 教师容器
	std::vector<ComputerRoom> vCom; // 机房容器
};


#endif //INC_20__ADMINISTRATOR_H
