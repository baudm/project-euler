#include <iostream>
#include <cstdint>
#include "euler.hpp"

int main(void)
{
	const uint16_t n = 100;

	std::cout << euler::p<uint32_t>(n) - 1 << std::endl;

	return 0;
}
