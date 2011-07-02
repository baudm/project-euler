#include <iostream>
#include <cstdint>
#include "euler.hpp"


/**
 * Checks if a number is Lychrel or not based on the
 * definition and limits stated in Problem 55
 */
bool is_lychrel(uint64_t num)
{
	uint8_t i;

	for (i = 0; i < 50; i++) {
		num += euler::reverse_int(num, 10);
		if (euler::is_palindrome_int(num, 10))
			return false;
	}

	return true;
}


int main(void)
{
	uint16_t num, count = 0;

	for (num = 1; num < 10000; num++) {
		if (is_lychrel(num))
			count++;
	}

	std::cout << count << std::endl;

	return 0;
}
