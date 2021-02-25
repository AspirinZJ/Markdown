#include <iostream>

using namespace std;

double power(double base, double exponent)
{
	double res = base;

	if (base == 1) { return 1; }

	for (int i = 1; i < exponent; i++) { res *= base; }

	return res;
}

int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		cout << "Usage:" << argv[0] << " base exponent" << endl;
		return 1;
	}

	double base = atof(argv[1]);
	int exponent = atoi(argv[2]);

	cout << "result: " << power(base, exponent) << endl;

	return 0;
}
