#include <iostream>
#include "euler.hpp"


bool is_pandigital(uint32_t num)
{
	bool used[] = {false, false, false, false, false, false, false, false, false, false};
	uint8_t digit;

	while (num) {
		digit = num % 10;
		if (digit == 0 || used[digit])
			return false;
		used[digit] = true;
		num /= 10;
	}

	return true;
}


void concat_int(uint32_t* a, uint16_t b)
{
	uint8_t count = euler::digit_count<uint8_t>(b);

	while (count) {
		*a *= 10;
		count--;
	}

	*a += b;
}


int main(void)
{
	uint16_t num, prod;
	uint32_t concat, largest_concat = 0;

	for (num = 1; num <= 9999; num++) {
		concat = num;
		prod = 2 * num;
		while (euler::digit_count(concat) + euler::digit_count(prod) <= 9) {
			concat_int(&concat, prod);
			prod += num;
		}
		if (euler::digit_count(concat) != 9)
			continue;
		if (is_pandigital(concat) && concat > largest_concat)
			largest_concat = concat;
	}

	std::cout << largest_concat << std::endl;

	return 0;
}
