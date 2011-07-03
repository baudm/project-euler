#include <iostream>
#include <cstdint>
#include "euler.hpp"


int main(void)
{
	uint32_t p, n, base, sum = 0;
	uint8_t count = 0;

	for (p = 11; count < 11; p += (p % 6 == 5) ? 2 : 4) {
		if (!euler::is_prime(p))
			continue;
		/**
		 * Remove digits from right to left
		 */
		n = p / 10;
		base = 1;
		while (n) {
			if (!euler::is_prime(n))
				break;
			n /= 10;
			base *= 10;
		}
		// if the while loop finished, n must be 0
		if (n)
			continue;
		/**
		 * Remove digits from left to right
		 */
		n = p % base;
		while (n) {
			if (!euler::is_prime(n))
				break;
			n %= base;
			base /= 10;
		}
		if (!n) {
			count++;
			sum += p;
		}
	}

	std::cout << sum << std::endl;

	return 0;
}
