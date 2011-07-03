#include <iostream>
#include <cstdint>
#include <cmath>
#include "euler.hpp"


const int max_count = 4;


bool has_four_distinct_prime_factors(uint64_t num)
{
	uint16_t prime_factors = 0;
	uint32_t p;

	for (p = 2; p <= 3; p++) {
		if (num % p != 0)
			continue;
		prime_factors++;
		while (num % p == 0)
			num /= p;
	}

	for (p = 5; p <= num; p += (p % 6 == 5) ? 2 : 4) {
		// filter non-factors
		if (num % p != 0)
			continue;
		// filter non-primes
		if (!euler::is_prime(p))
			continue;
		prime_factors++;
		if (prime_factors > max_count)
			return false;
		while (num % p == 0)
			num /= p;
	}

	return prime_factors == max_count;
}


int main(void)
{
	uint32_t num;
	uint8_t count = 0;

	for (num = 210; count < max_count; num++) {
		if (has_four_distinct_prime_factors(num))
			count++;
		else
			count = 0;
	}

	std::cout << num - max_count << std::endl;

	return 0;
}
