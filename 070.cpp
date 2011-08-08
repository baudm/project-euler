#include <iostream>
#include <vector>
#include <cstdint>
#include "euler.hpp"

void gen_primes(std::vector<uint32_t>& primes, uint32_t limit)
{
	uint32_t p;

	primes.push_back(2);
	primes.push_back(3);
	for (p = 5; p <= limit; p += 6) {
		if (euler::is_prime(p))
			primes.push_back(p);
		if (euler::is_prime(p + 2))
			primes.push_back(p + 2);
	}
}

uint32_t phi(uint32_t n, std::vector<uint32_t>& primes)
{
	std::vector<uint32_t>::size_type i;

	/**
	 * Discard all numbers which are multiples of primes < 1000
	 * because these numbers will surely have n/phi(n) > 1.001
	 */
	for (i = 0; i < 168; i++) {
		if (n % primes[i] == 0)
			return 1;
	}

	/**
	 * Discard primes because their phi(n) will never be
	 * a permutation of n. For primes, phi(n) = n - 1
	 */
	if (euler::is_prime(n))
		return 1;

	uint32_t p, ret = n;

	for (; i < primes.size(); i++) {
		p = primes[i];
		if (p > n)
			break;
		if (n % p != 0)
			continue;
		n /= p;
		/**
		 * Discard all numbers which have repeated prime factors
		 * because these are just "mirrors," e.g.:
		 * 6/phi(6) = 3 = 12/phi(12)
		 */
		if (n % p == 0)
			return 1;
		ret = (ret / p) * (p - 1);
	}

	return ret;
}

int main(void)
{
	const uint32_t limit = 10000000;
	std::vector<uint32_t> primes;
	uint32_t n, target_n, p;
	double ratio, min_ratio = 2.0;

	// generate primes from 2 up to limit/2
	gen_primes(primes, limit/2);

	/**
	 * Iterate from the highest to the lowest n because
	 * lower n values generally have higher values for n/phi(n)
	 */
	for (n = 9999999; n > 1; n--) {
		p = phi(n, primes);
		ratio = double(n)/p;
		if (ratio < min_ratio && euler::is_permutation(p, n)) {
			min_ratio = ratio;
			target_n = n;
		}
	}

	std::cout << target_n << std::endl;

	return 0;
}
