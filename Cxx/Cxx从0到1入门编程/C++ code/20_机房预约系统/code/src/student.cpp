// Created by jackzhang on 2021/2/18.

#include "student.h"

Student::Student() = default;

Student::Student(int id, std::string name, std::string passwd) : m_id(id), Identity(std::move(name), std::move(passwd))
{
	// 初始化机房信息
	std::ifstream ifs(COMPUTER_ROOM_FILE, std::ios::in);
	if (!ifs.is_open())
	{
		std::cerr << "Error: cannot open " << COMPUTER_ROOM_FILE << std::endl;
		ifs.close();
		return;
	}

	ComputerRoom com{};
	while (ifs >> com.m_computerRoomId && ifs >> com.m_maxNum) { this->m_vCom.push_back(com); }

	ifs.close();
}

//  菜单界面
void Student::operMenu()
{
	std::cout << "欢迎学生代表: " << this->m_name << " 登录.\n"
			  << "\t\t---------------------------------\n"
			  << "\t\t|                               |\n"
			  << "\t\t|        1. 申请预约             |\n"
			  << "\t\t|                               |\n"
			  << "\t\t|        2. 查看我的预约          |\n"
			  << "\t\t|                               |\n"
			  << "\t\t|        3. 查看所有预约          |\n"
			  << "\t\t|                               |\n"
			  << "\t\t|        4. 取消预约             |\n"
			  << "\t\t|                               |\n"
			  << "\t\t|        0. 注销登录             |\n"
			  << "\t\t|                               |\n"
			  << "\t\t---------------------------------\n"
			  << "请选择：\n";
}

// 申请预约: 1. 选择日期 2. 选择时间段 3. 选择机房 4. 生成记录
void Student::applyOrder()
{
	int date = 0, interval = 0, room = 0; // 一周的第几日， 上午或下午， 机房编号

	std::cout << "机房开放时间为周一至周五.\n请输入申请预约的时间:\n1. 周一\n2. 周二\n3. 周三\n4. 周四\n5. 周五\n";
	while (true)
	{
		std::cin >> date;
		if (date >= 1 && date <= 5) { break; }
		std::cout << "错误的日期，请重新输入.\n";
	}

	std::cout << "请输入时间段:\n1. 上午\n2. 下午\n";
	while (true)
	{
		std::cin >> interval;
		if (interval >= 1 && interval <= 2) { break; }
		std::cout << "错误的时间段，请重新输入.\n";
	}

	std::cout << "请选择机房：\n";
	for (auto &i : this->m_vCom)
	{
		std::cout << i.m_computerRoomId << "号机房容量为: " << i.m_maxNum << std::endl;
	}
	while (true)
	{
		std::cin >> room;
		if (room >= 1 && room <= this->m_vCom.size()) { break; }
		std::cout << "错误的机房，请重新输入.\n";
	}

	std::ofstream ofs(ORDER_FILE, std::ios::in | std::ios::app);
	ofs << "date:" << date << " " << "interval:" << interval << " " << "stuId:" << this->m_id << " "
		<< "stuName:" << this->m_name << " " << "roomId:" << room << " " << "status:" << ORDER_PROCESSING << std::endl;
	ofs.close();

	std::cout << "预约成功，审核中.\n";
}

// 查看自身预约
void Student::showMyOrder() const
{
	Order order;
	if (order.m_orderSize == 0)
	{
		std::cout << "无预约记录.\n";
		return;
	}

	for (int i = 0; i < order.m_orderSize; ++i)
	{
		if (this->m_id == std::atoi(order.m_mOrderData[i]["stuId"].c_str()))
		{
			std::cout << "预约时间，周" << order.m_mOrderData[i]["date"] << ". 时间段: " << order.m_mOrderData[i]["interval"]
					  << ". 机房: " << order.m_mOrderData[i]["roomId"] << ". 状态: " << order.m_mOrderData[i]["status"]
					  << std::endl;
		}
	}
}

// 查看所有预约
void Student::showAllOrder()
{
	Order order;
	if (0 == order.m_orderSize)
	{
		std::cout << "无预约记录.\n";
		return;
	}

	for (int i = 0; i < order.m_orderSize; ++i)
	{
		std::cout << i + 1 << ": " << "预约日期，周: " << order.m_mOrderData[i]["date"] << ". 时间段: "
				  << order.m_mOrderData[i]["interval"] << ". 学号: " << order.m_mOrderData[i]["stuId"]
				  << ". 姓名: " << order.m_mOrderData[i]["stuName"] << ". 机房: " << order.m_mOrderData[i]["roomId"]
				  << ". 状态: " << order.m_mOrderData[i]["status"] << std::endl;
	}
}

// 取消预约
void Student::cancelOrder() const
{
	Order order;
	if (0 == order.m_orderSize)
	{
		std::cout << "无预约记录.\n";
		return;
	}

	std::cout << "审核中或预约成功的记录可以取消，请输入取消的记录:\n";

	int ind = 1;
	std::vector<int> vInd;    // 存放
	for (int i = 0; i < order.m_orderSize; ++i)
	{
		if (this->m_id == std::atoi(order.m_mOrderData[i]["stuId"].c_str()))
		{
			if (ORDER_PROCESSING == order.m_mOrderData[i]["status"] ||
				ORDER_SUCCESSFULLY == order.m_mOrderData[i]["status"])
			{
				vInd.push_back(i);
				std::cout << ind++ << ": " << "预约日期: 周" << order.m_mOrderData[i]["date"] << ". 时间段: "
						  << (order.m_mOrderData[i]["interval"] == "1" ? "上午" : "下午") << ". 机房编号: "
						  << order.m_mOrderData[i]["roomId"] << ". 状态: " << order.m_mOrderData[i]["status"]
						  << std::endl;
			}
		}
	}

	std::cout << "请输入取消的记录, 0返回: " << std::endl;
	int select;
	while (true)
	{
		std::cin >> select;
		if (select == 0) { return; }
		else if (select > 0 && select <= vInd.size())
		{
			order.m_mOrderData[vInd[select - 1]]["status"] = "0";
			order.updateOrder();
			std::cout << "已经取消预约.\n";
			return;
		}
		else { std::cout << "输入有误，请重新输入.\n"; }
	}
}
