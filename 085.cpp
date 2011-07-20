#include <iostream>
#include <cstdint>
#include <cmath>
#include "euler.hpp"

int main(void)
{
	const uint32_t target = 2000000;
	uint32_t count, diff, min_diff = 100000;
	uint32_t best_area;
	uint16_t width, height;

	for (width = 20; width <= 85; width++) {
		for (height = 20; height <= 85; height++) {
			count = euler::triangular<uint32_t>(width) * euler::triangular<uint32_t>(height);
			diff = (target > count) ? target - count : count - target;
			if (diff < min_diff) {
				min_diff = diff;
				best_area = width*height;
			}
		}
	}

	std::cout << best_area << std::endl;

	return 0;
}
