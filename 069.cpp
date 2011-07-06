#include <iostream>
#include <cstdint>
#include "euler.hpp"


/**
 * Analysis:
 *
 * Let R(n) = n/phi(n)
 *
 * (1) The R(n) of a number N is the same for any positive power of N.
 *     e.g. R(2) == R(2^2) == R(2^3) == 2
 * (2) The R(n) of a number N is equal to the product of the individual R(n)'s
 *     of its prime factors.
 *     e.g. R(6) = R(2) * R(3) = 2 * 1.5 = 3
 * (3) Because of (1) and (2), numbers with the same prime factors, regardless
 *     of the powers of these factors, will have the same value for R(n).
 *     e.g. n = 12 = 2^2 * 3
 *          R(12) = R(2^2) * R(3) = R(2) * R(3) = R(6)
 * (4) For prime numbers, R(n) decreases as n increases.
 *     i.e. R(2) = 2, R(3) = 1.5, R(5) = 1.25, R(7) = 1.1666...
 *
 * Solution:
 *
 * Therefore, the maximum value of R(n) for n <= 1,000,000 can be achieved
 * by getting the product of the individual R(n) of all prime numbers like so:
 *
 * max R(n) = R(2) * R(3) * R(5) * R(7) * ... * R(x)
 *
 * Because of (2), n can be computed as follows:
 *
 * n = 2 * 3 * 5 * 7 * ... * x
 *
 * In summary, the value of n that will yield max R(n) can be computed by
 * getting the product of the prime numbers just before the product
 * breaches the 1,000,000 limit.
 */
int main(void)
{
	const uint32_t limit = 1000000;
	uint32_t max_n;
	uint16_t n;

	/**
	 * Product of the first two prime numbers
	 */
	max_n = 2 * 3;

	/**
	 * Get the product of the prime numbers just before the product
	 * gets larger than the limit, which is 1,000,000.
	 */
	for (n = 5; ; n += (n % 6 == 5) ? 2 : 4) {
		if (euler::is_prime(n)) {
			if (max_n * n > limit)
				break;
			max_n *= n;
		}
	}

	std::cout << max_n << std::endl;

	return 0;
}
