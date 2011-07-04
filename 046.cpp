#include <iostream>
#include <cstdint>
#include "euler.hpp"


int main(void)
{
	uint32_t num, p, s;
	uint16_t i;
	bool found;

	for (num = 35; ; num += 2) {
		// filter out odd primes
		if (euler::is_prime(num))
			continue;
		found = true;
		s = 2; // 2 * 1^2
		for (i = 1; s < num; i++) {
			s = 2 * i * i;
			p = num - s;
			if (euler::is_prime(p)) {
				found = false;
				break;
			}
		}
		if (found)
			break;
	}

	std::cout << num << std::endl;

	return 0;
}
