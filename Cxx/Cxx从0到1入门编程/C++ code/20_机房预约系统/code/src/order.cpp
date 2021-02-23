// Created by jackzhang on 2021/2/19.
#include "order.h"

Order::Order()
{
	this->m_orderSize = 0;

	std::ifstream ifs(ORDER_FILE, std::ios::in);
	if (!ifs.is_open())
	{
		std::cerr << "Error: cannot open " << ORDER_FILE << std::endl;
		ifs.close();
		return;
	}

	std::string strArr[6]; // 日期， 时间段， 学生id， 学生姓名， 机房id， 预约状态
	while (ifs >> strArr[0] && ifs >> strArr[1] && ifs >> strArr[2] && ifs >> strArr[3] && ifs >> strArr[4] &&
		   ifs >> strArr[5])    // 一次读取一行
	{
		std::string key, value;
		std::map<std::string, std::string> mTmp;
		int pos;
		for (auto &str : strArr)
		{
			pos = str.find(':');
			if (-1 != pos)
			{
				key = str.substr(0, pos);
				value = str.substr(pos + 1, str.size() - pos);
				mTmp.insert(std::make_pair(key, value));
			}
		}

		// 将这行的map插入到m_mOrderData中
		this->m_mOrderData.insert(std::make_pair((this->m_orderSize)++, mTmp));
	}
	ifs.close();

/*
	std::cout << "共有" << this->m_orderSize << "条预约记录。\n";

	for (auto &cit : this->m_mOrderData)
	{
		for (const auto &cit2 : cit.second) { std::cout << cit2.first << ", " << cit2.second << ", "; }
		std::cout << std::endl;
	}
*/
}

// 更新记录，写入文件
void Order::updateOrder()
{
	if (0 == this->m_orderSize) { return; }
	std::ofstream ofs(ORDER_FILE, std::ios::out | std::ios::trunc);

	std::string keyStrArr[6] = {"date", "interval", "stuId", "stuName", "roomId", "status"};
	for (int i = 0; i < this->m_orderSize; ++i)
	{
		for (auto &j : keyStrArr)
		{
			ofs << j << ":" << this->m_mOrderData[i][j] << " ";
		}
		ofs << std::endl;
	}
	ofs.close();
}

Order::~Order() = default;
