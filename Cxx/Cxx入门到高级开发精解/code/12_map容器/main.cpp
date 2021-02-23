#include "CString.h"
#include <iostream>
#include <map>

int main()
{
	std::map<CString, double> mp; // define a map, key:CString, value:double

	// value_type to create
	mp.insert(std::map<CString, double>::value_type("pi", 3.14));
	mp.insert(std::map<CString, double>::value_type("e", 2.71));
	mp.insert(std::map<CString, double>::value_type("zero", 0.0));

	// same key will be ignored
	mp.insert(std::map<CString, double>::value_type("zero", 10.0));

	// insert through key
	mp[(const char *)"one"] = 1.0;
	mp[CString("pi")] = 3.1415; // change the value of a key

	std::map<CString, double>::const_iterator citer;
	for (citer = mp.begin(); citer != mp.end(); ++citer)
	{std::cout << citer->first << ": " << (*citer).second << std::endl;}

	std::cout << "pi: " << mp.find("pi")->second << std::endl;


	return 0;
}