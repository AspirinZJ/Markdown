#include "mymath.hpp"

double power(double base, double exponent)
{
	double res = base;

	if (base == 1) { return 1; }

	for (int i = 1; i < exponent; i++) { res = res * base; }

	return res;
}
  

