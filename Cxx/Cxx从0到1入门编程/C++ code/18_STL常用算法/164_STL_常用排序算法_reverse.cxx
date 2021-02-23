//reverse(iterator beg, iterator end)`
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void myPrint(int val) {cout << val << ' ';}

int main()
{
	vector<int> iVec = {1, 2, 4523, 23};
	reverse(iVec.begin(), iVec.end());
	for_each(iVec.begin(), iVec.end(), myPrint);
    return 0;
}
