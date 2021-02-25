#include <iostream>
#include "../config/config.hpp"

using namespace std;

#ifdef USE_MYMATH
#include "mymath.hpp"
#else

#include <cmath>

#endif

int main(int argc, char *argv[])
{
	double base;
	int exponent;
	cout << "Input base: " << endl;
	cin >> base;
	cout << "Input exponent: " << endl;
	cin >> exponent;
#ifdef USE_MYMATH
	cout << "mymath's result" << endl
		 << power(base, exponent);
#else
	cout << "standard-math's result: " << pow(base, exponent) << endl;
#endif
	return 0;
}
