// Created by jackzhang on 2021/2/19.
// 预约类，用于创建预约和管理、更新记录

#ifndef INC_20__ORDER_H
#define INC_20__ORDER_H

#include <iostream>
#include <map>
#include <fstream>

#include "global.h"

class Order
{
public:
	Order();
	void updateOrder();    // 更新预约记录
	~Order();

	std::map<int, std::map<std::string, std::string>> m_mOrderData; // 预约记录的容器， key: 记录的行数 value: 那行记录的内容
	int m_orderSize;    // 预约记录条数
};


#endif //INC_20__ORDER_H
