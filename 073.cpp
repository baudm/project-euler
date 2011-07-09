#include <iostream>
#include <cstdint>
#include "euler.hpp"


int main(void)
{
	const uint16_t limit = 12000;
	uint16_t n, d;
	uint32_t count = 0;

	for (n = 2; n < limit/2; n++) {
		for (d = 2*n + 1; d <= limit && d < 3*n; d++) {
			if (euler::gcf(n, d) == 1)
				count++;
		}
	}

	std::cout << count << std::endl;

	return 0;
}
