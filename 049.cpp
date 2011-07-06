#include <iostream>
#include <algorithm>
#include <cstdint>
#include "euler.hpp"


void get_digits(uint8_t digits[], uint16_t num)
{
	uint8_t i = 3;

	while (num) {
		digits[i--] = num % 10;
		num /= 10;
	}
}


uint16_t get_value(uint8_t digits[])
{
	return 1000 * digits[0] + 100 * digits[1] + 10 * digits[2] + digits[3];
}


bool is_permutation(uint16_t a, uint16_t b)
{
	uint8_t count[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	uint16_t nums[] = {a, b};
	uint8_t digit, i;

	for (i = 0; i < 2; i++) {
		while (nums[i]) {
			digit = nums[i] % 10;
			count[digit]++;
			nums[i] /= 10;
		}
	}

	/**
	 * If a and b are permutations of each other, the count for each digit
	 * should be even.
	 */
	for (i = 0; i < 10; i++) {
		if (count[i] % 2 != 0)
			return false;
	}

	return true;
}


int main(void)
{
	uint16_t p, diff, next;
	uint8_t digits[4];
	bool finished = false;

	for (p = 1009; p <= 9999; p += (p % 6 == 5) ? 2 : 4) {
		// skip non-primes and the given
		if (!euler::is_prime(p) || p == 1487)
			continue;
		get_digits(digits, p);
		while (std::next_permutation(digits, digits + 4)) {
			next = get_value(digits);
			if (euler::is_prime(next)) {
				diff = next - p;
				next += diff;
				/**
				 * The third term of the sequence should also be
				 * a permutation of p and should also be prime.
				 */
				if (is_permutation(p, next) && euler::is_prime(next)) {
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
