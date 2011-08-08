#include <iostream>
#include <algorithm>
#include <cstdint>
#include "euler.hpp"

int main(void)
{
	uint16_t p, diff, next;
	uint8_t digits[4];
	bool finished = false;

	for (p = 1009; p <= 9999; p += (p % 6 == 5) ? 2 : 4) {
		// skip non-primes and the given
		if (!euler::is_prime(p) || p == 1487)
			continue;
		euler::int_to_digits(p, 10, digits, digits + 4);
		while (std::next_permutation(digits, digits + 4)) {
			next = euler::digits_to_int<uint16_t>(10, digits, digits + 4);
			if (euler::is_prime(next)) {
				diff = next - p;
				next += diff;
				/**
				 * The third term of the sequence should also be
				 * a permutation of p and should also be prime.
				 */
				if (euler::is_permutation(p, next) && euler::is_prime(next)) {
					finished = true;
					break;
				}
			}
		}
		if (finished)
			break;
	}

	std::cout << p << p + diff << p + 2 * diff << std::endl;

	return 0;
}
