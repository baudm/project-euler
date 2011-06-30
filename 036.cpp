#include <iostream>
#include "euler.hpp"


int main(void)
{
	unsigned long num, sum = 0;

	for (num = 1; num < 1000000; num++) {
		if (!euler::is_palindrome_int(num, 10))
			continue;
		if (euler::is_palindrome_int(num, 2))
			sum += num;
	}

	std::cout << sum << std::endl;

	return 0;
}
