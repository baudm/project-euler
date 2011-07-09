#include <iostream>
#include <cstdint>
#include "euler.hpp"


int main(void)
{
	uint32_t n, d;
	uint32_t last_n;
	uint32_t hcf;
	double diff;

	for (d = 1000000; d > 1; d--) {
		n = 1;
		last_n = 0;
		while (1) {
			// get numerator of midpoint
			n = (7*n + 3*d)/14;
			if (last_n == n)
				break;
			last_n = n;
		}
		/*
		 * Get the difference between 3/7 and the current fraction
		 * and multiply it by 1,000,000 to "magnify" it.
		 */
		diff = 1000000 * (3*d - 7*n)/(7.0*d);
		/*
		 * If the difference (multiplied by 1M) is "close enough"
		 * to 1.0, then this is the closest fraction to 3/7.
		 */
		if (diff - 1.0 < 0.0001)
			break;
	}

	// reduce to lowest terms
	hcf = euler::gcf(n, d);
	n /= hcf;

	std::cout<< n << std::endl;

	return 0;
}
