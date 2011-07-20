#include <iostream>
#include <cstdint>
#include <cmath>
#include "euler.hpp"

bool is_pentagonal(uint32_t num)
{
	uint32_t expr = 1 + 24 * num;
	uint16_t s = std::sqrt(expr);

	// if root is not an integer, then num is not pentagonal
	if (uint32_t(s*s) != expr)
		return false;

	return (1 + s) % 6 == 0;
}

int main(void)
{
	uint16_t k, j;
	uint32_t two_Pk, Psum, Pdiff;
	bool found = false;

	/*
	 * 70 + 22 = 92 (sum)
	 * 70 - 22 = 48 (diff)
	 * -----------------
	 * 2(70)   = 92 + 48
	 *
	 * In general:
	 * 2*Pk = Psum + Pdiff
	 */
	for (k = 1; ; k++) {
		two_Pk = 2*euler::pentagonal<uint32_t>(k);

		for (j = k + 1; ; j++) {
			Psum = euler::pentagonal<uint32_t>(j);
			if (Psum > two_Pk)
				break;

			Pdiff = two_Pk - Psum;
			if (is_pentagonal(Pdiff) && is_pentagonal(Psum - two_Pk/2)) {
				found = true;
				break;
			}
		}
		if (found)
			break;
	}

	std::cout << Pdiff << std::endl;

	return 0;
}
