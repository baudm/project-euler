#include <iostream>
#include <cmath>
#include <cstdint>
#include "euler.hpp"


int main(void)
{
	uint64_t n = 600851475143LL;
	uint32_t i, j, gpf = 1, s = sqrt(n);

	for (i = 5; i <= s; i += (i % 6 == 5) ? 2 : 4) {
		if (n % i == 0) {
			j = n / i;
			if (!euler::is_prime(j)) {
				if (euler::is_prime(i) && i > gpf)
					gpf = i;
			} else if (j > gpf) {
				gpf = j;
				break;
			}
		}
	}

	std::cout << gpf << std::endl;

	return 0;
}
