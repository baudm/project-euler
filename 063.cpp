#include <iostream>
#include <cstdint>
#include <cmath>


int main(void)
{
	const uint8_t max_base = 9;
	uint8_t n, min_base, count = 0;
	double exp;

	/**
	 * For all n, we know that the maximum base that will satisfy the problem is 9.
	 * This is because for any base >= 10, raising it to any n will yield a number
	 * with more than n digits.
	 *
	 * Now, to solve the problem, the lower limit of the base should be computed
	 * for each n. This can be done by getting the nth root of the smallest n-digit number.
	 * For instance, for n = 3, the smallest 3-digit number is 100, which is equal to 10^2.
	 * Its cube root is then 10^(2/3).
	 *
	 * In general, the nth root of the smallest n-digit number is equal to 10^((n - 1) / n)
	 * We can observe that (n - 1)/n approaches 1 as n increases. Thus, as n increases,
	 * the nth root will approach 10, which is greater than 9, the maximum base allowed.
	 */
	for (n = 1; ; n++) {
		exp = (n - 1) / double(n);
		min_base = std::ceil(std::pow(10, exp));
		if (min_base > max_base)
			break;
		count += max_base - min_base + 1;
	}

	std::cout << (unsigned short)count << std::endl;

	return 0;
}
