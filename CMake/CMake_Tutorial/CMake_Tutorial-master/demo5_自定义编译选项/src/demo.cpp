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
	if (argc < 3)
	{
		cout << "Usage:" << argv[0] << endl;
		return 1;
	}

	double base = atof(argv[1]);
	int exponent = atoi(argv[2]);
#ifdef USE_MYMATH
	cout<<"mymath's result"<<endl<<power(base,exponent);
#else
	cout << "standard-math's result: " << pow(base, exponent) << endl;
#endif
	return 0;
}
