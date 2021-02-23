// Created by jackzhang on 2/18/21.

#include "teacher.h"

Teacher::Teacher() = default;

Teacher::Teacher(int empId, std::string name, std::string passwd) : m_empId(empId),
																	Identity(std::move(name), std::move(passwd))
{
}

// 显示菜单
void Teacher::operMenu()
{
	std::cout << "欢迎教师: " << this->m_name << " 登录!\n"
			  << "\t\t---------------------------------\n"
			  << "\t\t|                               |\n"
			  << "\t\t|        1. 查看所有预约          |\n"
			  << "\t\t|                               |\n"
			  << "\t\t|        2. 审核预约             |\n"
			  << "\t\t|                               |\n"
			  << "\t\t|        0. 注销登录             |\n"
			  << "\t\t|                               |\n"
			  << "\t\t---------------------------------\n"
			  << "请选择：\n";
}

// 显示所有预约
void Teacher::showAllOrder()
{
	Order order;
	if (0 == order.m_orderSize)
	{
		std::cout << "无预约记录.\n";
		return;
	}

	for (int i = 0; i < order.m_orderSize; ++i)
	{
		std::cout << i + 1 << ": " << "预约日期，周: " << order.m_mOrderData[i]["date"]
				  << ". 时间段: " << (order.m_mOrderData[i]["interval"] == "1" ? "上午" : "下午") << ". 学号: "
				  << order.m_mOrderData[i]["stuId"] << ". 姓名: " << order.m_mOrderData[i]["stuName"]
				  << ". 机房编号: " << order.m_mOrderData[i]["roomId"] << ". 状态: " << order.m_mOrderData[i]["status"]
				  << std::endl;
	}
}

// 审核预约
void Teacher::validOrder()
{
	Order order;
	if (0 == order.m_orderSize)
	{
		std::cout << "无预约记录.\n";
		return;
	}

	int ind = 0;
	std::vector<int> vInd; // 记录索引的vector容器

	for (int i = 0; i < order.m_orderSize; ++i)
	{
		if (order.m_mOrderData[i]["status"] == ORDER_PROCESSING) // 1. 审核中 2. 预约成功 0. 取消的预约 -1. 预约失败
		{
			vInd.push_back(i);
			std::cout << ++ind << ": " << "预约时间，周: " << order.m_mOrderData[i]["date"] << ". 时间段: "
					  << order.m_mOrderData[i]["interval"] << ". 机房: " << order.m_mOrderData[i]["roomId"]
					  << ". 状态: " << order.m_mOrderData[i]["status"] << std::endl;
		}
	}

	int select;
	int select2;

	while (true)
	{
		std::cout << "请输入审核的预约记录，0返回:\n";
		std::cin >> select;

		if (0 == select) { return;}
		else if (select > 0 && select <= vInd.size())
		{
			std::cout << "请输入审核结果:\n1. 通过\n2. 不通过\n";
			std::cin >> select2;

			if (1 == select2) { order.m_mOrderData[vInd[select-1]]["status"] = ORDER_SUCCESSFULLY; }
			else { order.m_mOrderData[vInd[select-1]]["status"] = ORDER_FAILED; }
			order.updateOrder();
			std::cout << "审核完毕!\n";
		}
		else { std::cout << "输入的数字有误，请重新输入.\n"; }
	}
}

