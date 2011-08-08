#include <iostream>
#include <cstdint>
#include <algorithm>
#include "euler.hpp"


int main(void)
{
	uint8_t number[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	uint8_t primes[] = {2, 3, 5, 7, 11, 13, 17};
	uint8_t i;
	uint64_t sum = 0;
	bool interesting;

	do {
		interesting = true;

		for (i = 0; i < 7; i++) {
			if (euler::digits_to_int<uint16_t>(10, number + i + 1, number + i + 4) % primes[i] != 0) {
				interesting = false;
				break;
			}
		}

		if (interesting)
			sum += euler::digits_to_int<uint64_t>(10, number, number + 10);

	} while (std::next_permutation(number, number + 10));

	std::cout << sum << std::endl;

	return 0;
}
