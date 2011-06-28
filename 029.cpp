#include <iostream>
#include <vector>
#include <cmath>


/**
 * Returns the factors of num (excluding 1 and num itself)
 */
void get_factors(unsigned short num, std::vector<unsigned short>& factors)
{
	unsigned short i, s = sqrt(num);

	factors.clear();
	for (i = 2; i <= s; i++) {
		if (num % i == 0) {
			factors.push_back(i);
			if (num != i * i)
				factors.push_back(num / i);
		}
	}
}

/**
 * Express num as base^exp
 * e.g. 8 = 2^3
 *      10 = 10^1
 */
void decompose(unsigned short num, unsigned short* base, unsigned short* exp)
{
	double ex, s = sqrt(num);

	*exp = 1;
	for (*base = 2; *base <= s; (*base)++) {
		ex = log(num) / log(*base);
		if (ex == ceil(ex)) {
			*exp = ex;
			break;
		}
	}

	if (*exp == 1)
		*base = num;
}


int main(void)
{
	const unsigned short min_a = 2, max_a = 100;
	const unsigned short min_b = 2, max_b = 100;
	unsigned short a, b;
	unsigned short base, exp;
	unsigned terms;
	std::vector<unsigned short> exp_factors;
	std::vector<unsigned short>::iterator it;

	terms = (max_a - min_a + 1) * (max_b - min_b + 1);
	for (a = min_a; a <= max_a; a++) {
		for (b = min_b; b <= max_b; b++) {
			// base^exp = a
			decompose(a, &base, &exp);
			// base^(exp * b) = a^b
			get_factors(exp * b, exp_factors);
			/**
			 * Check if a^b can be expressed as c^d where a < c <= max_a
			 * e.g. 4^6 = (2^2)^6 = 2^12 = (2^3)^4 = 8^4
			 */
			for (it = exp_factors.begin(); it != exp_factors.end(); it++) {
				if (*it > exp && pow(base, *it) <= max_a) {
					terms--;
					break;
				}
			}
		}
	}

	std::cout << terms << std::endl;

	return 0;
}
