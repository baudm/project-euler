#include <iostream>
#include <set>
#include <cstdint>
#include "euler.hpp"


uint32_t digit_factorial_sum(uint32_t num)
{
	uint32_t sum = 0;

	while (num) {
		sum += euler::factorial<uint32_t>(num % 10);
		num /= 10;
	}

	return sum;
}


int main(void)
{
	uint32_t num, sum;
	uint32_t count = 0;
	std::set<uint32_t> chain;

	for (num = 1; num < 1000000; num++) {
		chain.clear();
		chain.insert(num);
		sum = digit_factorial_sum(num);
		while (chain.find(sum) == chain.end()) {
			chain.insert(sum);
			sum = digit_factorial_sum(sum);
		}
		if (chain.size() == 60)
			count++;
	}

	std::cout << count << std::endl;

	return 0;
}
