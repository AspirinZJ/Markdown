// Created by jackzhang on 2021/2/18.
/*
 * 学生类主要功能：
 * 	1. 显示菜单
 * 	2. 申请预约
 * 	3. 查看自身预约
 * 	4. 查看所有预约
 * 	5. 取消预约
 * */

#ifndef INC_20__STUDENT_H
#define INC_20__STUDENT_H

#include <iostream>
#include <fstream>
#include <utility>
#include <vector>

#include "identity.h"
#include "computerRoom.h"
#include "global.h"
#include "order.h"


class Student : public Identity
{
public:
	Student();    // 默认构造
	Student(int id, std::string name, std::string passwd);    // 有参构造（id，姓名，密码）
	void operMenu() override;    // 显示菜单
	void applyOrder();    // 申请预约
	void showMyOrder() const;    //	查看预约
	static void showAllOrder();    //	查看所有预约
	void cancelOrder() const;    //	取消预约

	int m_id;    //	学号
	std::vector<ComputerRoom> m_vCom; // 机房信息的容器
};


#endif //INC_20__STUDENT_H
