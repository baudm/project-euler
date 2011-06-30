#include <iostream>
#include <cstdint>
#include "euler.hpp"


int main(void)
{
	uint32_t fn = 0, sum = 0;
	uint8_t n = 3;

	while (fn < 4000000) {
		sum += fn;
		fn = euler::fib<uint32_t>(n);
		n += 3;
	}

	std::cout << sum << std::endl;

	return 0;
}
