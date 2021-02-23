//`random_shuffle(iterator beg, iterator end)`
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

void myPrint(int val)
{ cout << val << ' '; }

int main()
{
	srand((unsigned int) time(NULL));
	vector<int> iVec;
	for (int i = 0; i < 20; i++) { iVec.push_back(i); }
	random_shuffle(iVec.begin(), iVec.end());
	for_each(iVec.begin(), iVec.end(), myPrint);
	cout << endl;
	return 0;
}
