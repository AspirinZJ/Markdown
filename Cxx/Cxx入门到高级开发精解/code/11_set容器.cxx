#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>

int main()
{
	std::set<int> st = {32, 3, -4, 72, 1};
	st.insert(10);
	st.insert(10); // cannot insert 10 so it is ignored

	std::set<int>::iterator iter;
	for (iter = st.begin(); iter != st.end(); ++iter) { std::cout << *iter << ' '; }
	std::cout << std::endl;

	int key;
	std::cout << "Please input a key to find.\n";
	std::cin >> key;
	iter = st.find(key);
	if (st.end() != iter) { std::cout << "Found: " << key << std::endl; }
	else { std::cout << "Cannot find " << key << std::endl; }

	return 0;
}