#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include "euler.hpp"


uint32_t get_base10_value(std::vector<uint8_t>& digits)
{
	uint32_t value = 0, base = 1;
	std::vector<uint8_t>::reverse_iterator it;

	for (it = digits.rbegin(); it != digits.rend(); ++it) {
		value += (*it) * base;
		base *= 10;
	}

	return value;
}


int main(void)
{
	uint32_t largest = 2143, num;
	uint8_t n, d;
	std::vector<uint8_t> digits;

	for (n = 4; n <= 9; n++) {
		digits.clear();
		// create the first permutation of the n-digit number
		for (d = 1; d <= n; d++)
			digits.push_back(d);

		do {
			num = get_base10_value(digits);
			if (euler::is_prime(num) && num > largest)
				largest = num;
		} while (next_permutation(digits.begin(), digits.end()));
	}

	std::cout << largest << std::endl;

	return 0;
}
