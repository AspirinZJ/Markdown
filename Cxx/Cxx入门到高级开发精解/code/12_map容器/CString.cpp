#include "CString.h"


std::ostream &operator<<(std::ostream &os, const CString &str)
{
	os << str.pData;
	return os;
}

CString::CString()
{
	this->pData = new char[1];
	(this->pData)[0] = '\0';
}

CString::CString(const char *s)
{
	if (s)
	{
		this->pData = new char[strlen(s) + 1];
		strcpy(this->pData, s);
	}
	else { this->pData = nullptr; }
}

CString::CString(const CString &s)
{
	if (s.pData)
	{
		this->pData = new char[strlen(s.pData) + 1];
		strcpy(this->pData, s.pData);
	}
	else { this->pData = nullptr; }
}

CString::~CString()
{
	if (this->pData)
	{
		delete[] this->pData;
		this->pData = nullptr;
	}
}

CString &CString::operator=(const CString &str)
{
	// in case use = to the object itself
	if (&str == this) { return *this; }
	else
	{
		delete[] this->pData;
		this->pData = new char[strlen(str.pData) + 1];
		strcpy(this->pData, str.pData);
		return *this;
	}
}

bool CString::operator<(const CString &str) const
{
	return strcmp(this->pData, str.pData) < 0;
}
