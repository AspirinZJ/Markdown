/*使用面向对象实现
 * 从键盘中输入年月日，计算这一天是这一年的第几天*/
#include <iostream>

class CDate
{
public:
	void setDate(int year, int month, int day);

	void printDate();

	bool isLeap() const; // 判断是不是润年
	int numOfDay() const; // 求第几天

private:
	int m_year;
	int m_month;
	int m_day;
};


void CDate::setDate(int year, int month, int day)
{
	this->m_year = year;
	this->m_month = month;
	this->m_day = day;
}

void CDate::printDate()
{}

bool CDate::isLeap() const
{ if ((this->m_year % 4 == 0 && this->m_year % 100 != 0) || this->m_year % 400 == 0) return true; else return false; }

int CDate::numOfDay() const
{
	int dateArr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 平年每个月有几天的数组
	if (this->isLeap()) { dateArr[1] = 29; } // 润年二月加一天
	int number = 0;

	for (int i = 0; i < this->m_month - 1; i++) { number += dateArr[i]; }
	number += this->m_day;

	return number;
}

int main()
{
	CDate date{};
	int year, month, day;
	std::cout << "Input year, month and day: " << std::endl;
	std::cin >> year >> month >> day;
	date.setDate(year, month, day);
	date.printDate();

	std::cout << "Number of day: " << date.numOfDay() << std::endl;

	return 0;
}