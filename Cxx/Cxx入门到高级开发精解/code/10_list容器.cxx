#include <iostream>
#include <list>
#include <iterator>

typedef std::list<int> intList;    // typedef a new typename

int main()
{
	intList lst;    // list<int> lst;

	for (int i = 0; i < 5; ++i)    // i++有可能会产生临时变量，++i不会，所以++i效率更高
	{
		lst.push_front(i);
		lst.push_back(i);
	}

	intList::iterator iter = lst.begin();

	// for (int i = 0; i < lst.size(); ++i)
	while (iter != lst.end()) { std::cout << *(iter++) << ' '; }
	std::cout << std::endl;

	return 0;
}