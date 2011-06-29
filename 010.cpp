#include <iostream>
#include "euler.hpp"


int main(void)
{
	unsigned i;
	unsigned long long sum = 5; // 2 + 3

	for (i = 5; i < 2000000; i += (i % 6 == 5) ? 2 : 4) {
		if (euler::is_prime(i))
			sum += i;
	}

	std::cout << sum << std::endl;

	return 0;
}
