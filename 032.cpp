#include <iostream>
#include <cstdint>
#include <cstdarg>
#include <cmath>
#include "euler.hpp"


bool has_repeated_digits(int count, ...)
{
	bool used[] = {false, false, false, false, false, false, false, false, false, false};
	uint8_t i, digit;
	uint16_t num;
	va_list vl;

	va_start(vl, count);
	for (i = 0; i < count; i++) {

		num = va_arg(vl, int);
		while (num) {
			digit = num % 10;
			if (used[digit])
				return true;
			used[digit] = true;
			num /= 10;
		}
	}

	return false;
}


bool has_digit_zero(uint16_t num)
{
	uint8_t digit;

	while (num) {
		digit = num % 10;
		if (digit == 0)
			return true;
		num /= 10;
	}

	return false;
}


int main(void)
{
	uint32_t sum = 0;
	uint16_t prod;
	uint8_t i, s;

	for (prod = 1234; prod <= 9876; prod++) {
		if (has_repeated_digits(1, prod) || has_digit_zero(prod))
			continue;
		s = sqrt(prod);
		for (i = 2; i <= s; i++) {
			// discard non-factors
			if (prod % i != 0)
				continue;
			// discard roots
			if (prod == i * i)
				continue;
			// discard factors which have the digit 0
			if (has_digit_zero(i) || has_digit_zero(prod / i))
				continue;
			if (has_repeated_digits(3, prod, i, prod / i))
				continue;
			if (euler::digit_count(prod) + euler::digit_count(i) + euler::digit_count(prod / i) != 9)
				continue;
			sum += prod;
			//std::cout << i << " x " << prod / i << " = " << prod << std::endl;
			break;
		}
	}

	std::cout << sum << std::endl;

	return 0;
}
