#include <iostream>
#include <vector>
#include <set>
#include <cstdint>
#include "euler.hpp"


int main(void)
{
	std::vector<uint16_t> primes;
	uint16_t p;

	// generate primes up to sqrt(50M)
	primes.push_back(2);
	primes.push_back(3);
	for (p = 5; p <= 7071; p += 6) {
		if (euler::is_prime(p))
			primes.push_back(p);
		if (euler::is_prime(p + 2))
			primes.push_back(p + 2);
	}

	const uint32_t limit = 50000000;
	uint32_t fourth_pow, partial_sum, sum;
	// use a set to store the sums so that duplicates won't be stored
	std::set<uint32_t> sums;
	std::vector<uint16_t>::size_type i, j, k;

	// fourth power
	for (i = 0; primes[i] < 84; i++) {
		fourth_pow = primes[i]*primes[i]*primes[i]*primes[i];
		// cube
		for (j = 0; primes[j] < 368; j++) {
			partial_sum = primes[j]*primes[j]*primes[j] + fourth_pow;
			// square
			for (k = 0; k < primes.size(); k++) {
				sum = primes[k]*primes[k] + partial_sum;
				if (sum >= limit)
					break;
				sums.insert(sum);
			}
		}
	}

	std::cout << sums.size() << std::endl;

	return 0;
}
