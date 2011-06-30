#include <iostream>
#include "euler.hpp"


int main(void)
{
	int i = 0, p = 1;

	while (i < 10001) {
		if (euler::is_prime(++p))
			i++;
	}

	std::cout << p << std::endl;

	return 0;
}
