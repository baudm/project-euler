#include <iostream>
#include <cstdint>
#include "euler.hpp"


int main(void)
{
	uint8_t n, r;
	uint16_t counter = 0;

	for (n = 23; n <= 100; n++) {
		for (r = 1; r <= (n + 1) / 2 - 1; r++) {
			// increment by 2 to account for its duplicate in the other half
			if (euler::combination<double>(n, r) > 1000000.0)
				counter += 2;
		}
		// if n is even, then there's a middle value
		// the value of r here is what we already need.
		if (n % 2 == 0 && euler::combination<double>(n, r) > 1000000.0)
			counter++;
	}

	std::cout << counter << std::endl;

	return 0;
}
