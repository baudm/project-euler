#include <iostream>
#include "euler.hpp"

int main(void)
{
	unsigned a, b, p = 0;

	for (a = 999; a >= 100; a--) {
		for (b = a; b >= 100; b--) {
			if (euler::is_palindrome_int(a * b, 10) && a * b > p)
				p = a * b;
		}
	}

	std::cout << p << std::endl;

	return 0;
}
