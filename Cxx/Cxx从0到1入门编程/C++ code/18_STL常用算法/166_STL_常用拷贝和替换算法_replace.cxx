//`replace(iterator beg, iterator end, oldvalue, newvalue)`
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class CMyPrint
{
public:
	bool operator()(const int &val) const {cout << val << ' ';}
};

int main()
{
	vector<int> iVec = {1, 2, 3, 3, 5, 6};
	replace(iVec.begin(), iVec.end(), 3, 20);
	for_each(iVec.begin(), iVec.end(), CMyPrint()); cout << endl;

    return 0;
}
