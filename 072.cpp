#include <iostream>
#include <cstdint>
#include <cmath>


int main(void)
{
	uint32_t d;
	uint16_t factor, s;
	uint32_t c, counts[1000001] = {0};
	uint64_t total = 0;

	for (d = 2; d <= 1000000; d++) {
		// initial fraction count
		c = d - 1;
		/*
		 * Subtract the counts from d's factors.
		 * I found out that the number of duplicates in the initial count is
		 * equal to the counts from the factors of d.
		 */
		s = std::sqrt(d);
		for (factor = 2; factor <= s; factor++) {
			if (d % factor == 0) {
				c -= counts[factor];
				if (d/factor != factor)
					c -= counts[d/factor];
			}
		}
		// save the count for this d
		counts[d] = c;
		total += c;
	}

	std::cout << total << std::endl;

	return 0;
}
