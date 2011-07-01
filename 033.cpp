#include <iostream>
#include <cstdint>
#include "euler.hpp"


bool cancel_common(uint8_t a, uint8_t b)
{
	uint8_t counts[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	uint8_t i, numbers[] = {a, b};
	uint8_t digit, common = 10, num;

	// count the digits
	for (i = 0; i < 2; i++) {
		num = numbers[i];
		while (num) {
			digit = num % 10;
			counts[digit]++;
			num /= 10;
		}
	}

	// check which digit is the common digit, i.e. digit count == 2
	for (digit = 0; digit <= 9; digit++) {
		if (counts[digit] == 2) {
			common = digit;
			break;
		}
	}

	// no common digit
	if (common == 10)
		return false;

	for (i = 0; i < 2; i++) {
		num = numbers[i];
		while (num) {
			digit = num % 10;
			if (digit == common)
				break;
			num /= 10;
		}

		if (digit != common)
			continue;

		// remove common digit
		if (num > 10)
			numbers[i] /= 10;
		else
			numbers[i] -= 10 * digit;
	}

	// check if reduced form is equal to original form
	return a * numbers[1] == b * numbers[0];
}


int main(void)
{
	uint8_t a, b;
	uint32_t numerator = 1, denominator = 1, gcf;

	for (a = 11; a <= 99; a++) {
		for (b = a + 1; b <= 99; b++) {
			// filter out trivial fractions
			if (a % 10 == 0 && b % 10 == 0)
				continue;
			if (cancel_common(a, b)) {
				numerator *= a;
				denominator *= b;
			}
		}
	}

	gcf = euler::gcf(numerator, denominator);
	std::cout<< denominator / gcf << std::endl;

	return 0;
}
