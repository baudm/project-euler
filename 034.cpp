#include <iostream>
#include "euler.hpp"


bool check(unsigned long num, unsigned short* digits)
{
	unsigned short digit;
	unsigned long sum = 0, tmp = num;
	static unsigned factorials[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

	*digits = 0;
	while (tmp) {
		digit = tmp % 10;
		sum += factorials[digit];
		tmp /= 10;
		(*digits)++;
	}

	return (sum == num);
}


int main(void)
{
	unsigned long long num, sum = 0;
	unsigned short digits;
	const unsigned digit_max = 362880; // 9!

	num = 10;
	do {
		if (check(num, &digits))
			sum += num;

		num++;
	/**
	 * Repeat until the number of digits overtakes the number of digits of the
	 * maximum possible digit sum
	 */
	} while (euler::digit_count(digits * digit_max) >= digits);

	std::cout << sum << std::endl;

	return 0;
}
