#include <iostream>
#include <cmath>


bool is_prime(unsigned n)
{
	unsigned k, p = 0, s = sqrt(n);

	if ((n % 2 == 0 && n != 2) || (n % 3 == 0 && n != 3))
		return false;

	for (k = 1; p <= s; k++) {
		p = 6 * k + 1;
		if ((n % p == 0 || n % (p - 2) == 0) && (n / p != 1 && n / (p - 2) != 1))
			return false;
	}
	return true;
}


int main(void)
{
	int i = 0, p = 1;

	while (i < 10001) {
		if (is_prime(++p))
			i++;
	}

	std::cout << p << std::endl;

	return 0;
}
