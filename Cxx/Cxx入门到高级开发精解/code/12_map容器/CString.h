#ifndef CODE_STRING_H
#define CODE_STRING_H

#include <iostream>
#include <map>
#include <cstring>

class CString
{
	friend std::ostream &operator<<(std::ostream &os, const CString &str);
public:
	CString();
	CString(const char *s);
	CString(const CString &s);
	~CString();

	CString &operator=(const CString &str);
	bool operator<(const CString &str) const;

private:
	char *pData;
};

#endif //CODE_STRING_H
