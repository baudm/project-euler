#include <iostream>
#include <cstdint>
#include "euler.hpp"

int main(void)
{
	uint32_t num = 1;
	uint16_t diff = 2, count = 1, primes = 0;
	uint8_t i;

	while (10 * primes >= count || primes == 0) {
		// four corners of each 'layer' of the spiral
		for (i = 0; i < 4; i++) {
			num += diff;
			if (euler::is_prime(num))
				primes++;
			count++;
			if (10 * primes < count)
				break;
		}
		diff += 2;
	}

	std::cout << (count - 1) / 2 + 1 << std::endl;

	return 0;
}
