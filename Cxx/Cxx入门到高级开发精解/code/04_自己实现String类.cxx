#include <iostream>
#include <cstring>

class CString
{
	friend std::ostream &operator<<(std::ostream &os, CString &str); // 重载<<运算符
public:
	CString(const char *str); // 普通构造
	CString(const CString &str); // 拷贝构造
	CString &operator=(const CString &str); // 重载=运算符
	~CString();
private:
	char *m_rep;
};

CString::CString(const char *str)
{
	if (str != NULL)
	{
		this->m_rep = new char[strlen(str)+1];
		strcpy(this->m_rep, str);
	}
	else
	{
		this->m_rep = new char[1];
		this->m_rep[0] = '\0';
	}
}

CString::CString(const CString &str)
{
	this->m_rep = new char[strlen(str.m_rep) + 1];
	strcpy(this->m_rep, str.m_rep);
}

CString &CString::operator=(const CString &str)
{
	// 防止自己给自己赋值
	if (this == &str) { return *this;}
	else
	{
		delete[] this->m_rep; // 删除原有数据
		this->m_rep = new char[strlen(str.m_rep)+1];
		strcpy(this->m_rep, str.m_rep);
		return *this;
	}
}

std::ostream &operator<<(std::ostream &os, CString &str)
{
	os << str.m_rep << std::endl;
	return os;
}

CString::~CString()
{
	delete[] this->m_rep;
	this->m_rep = nullptr;
}

int main()
{
	CString str1("Hello ");
	CString str2(str1);
	CString str3(str1);
	str3 = str2;

	std::cout << str1;
	std::cout << str2;
	std::cout << str3;

	return 0;
}
