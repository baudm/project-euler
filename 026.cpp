#include <iostream>
#include <cstdint>
#include "euler.hpp"


int main(void)
{
	uint16_t longest = 0;
	uint16_t n = 0, d, ord;

	for (d = 7; d < 1000; d += (d % 6 == 5) ? 2 : 4) {
		if (!euler::is_prime(d))
			continue;
		ord = euler::order(10, d);
		if (ord > longest) {
			longest = ord;
			n = d;
		}
	}

	std::cout << n << std::endl;

	return 0;
}
