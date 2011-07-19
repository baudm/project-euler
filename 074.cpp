#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
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
	std::vector<uint32_t> chain;
	std::map<uint32_t,uint8_t> cache;
	uint8_t size;

	for (num = 1; num < 1000000; num++) {
		chain.clear();
		chain.push_back(num);
		sum = digit_factorial_sum(num);
		while (find(chain.begin(), chain.end(), sum) == chain.end()) {
			if (cache[sum])
				break;
			chain.push_back(sum);
			sum = digit_factorial_sum(sum);
		}
		size = chain.size() + cache[sum];
		cache[num] = size;
		if (size == 60)
			count++;
	}

	std::cout << count << std::endl;

	return 0;
}
