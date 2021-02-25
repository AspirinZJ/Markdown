#include <iostream>
#include "./mylib/mymath.hpp"

using namespace std;


int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		cout << "Usage:" << argv[0] << endl;
		return 1;
	}

	double base = atof(argv[1]);
	int exponent = atoi(argv[2]);
	cout << "result: " << power(base, exponent) << endl;

	return 0;
}
