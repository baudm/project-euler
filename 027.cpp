#include <iostream>
#include <cstdint>
#include "euler.hpp"


int main(void)
{
	int16_t a, b;
	int16_t best_a, best_b;
	uint8_t n, max_n = 0;
	uint32_t p;

	for (a = -999; a <= 999; a++) {
		for (b = -999; b <= 999; b++) {
			for (n = 0; ; n++) {
				p = n * n + a * n + b;
				if (p < 0 || !euler::is_prime(p))
					break;
			}
			if (n > max_n) {
				max_n = n;
				best_a = a;
				best_b = b;
			}
		}
	}

	std::cout << best_a * best_b << std::endl;

	return 0;
}
