#include <iostream>
#include <cstdint>
#include <cmath>


int main(void)
{
	const uint32_t target = 2000000;
	uint32_t count, diff, min_diff = 100000;
	uint32_t best_area;
	uint16_t width, height;
	uint16_t w, h;

	for (width = 1; width <= 5; width++) {
		for (height = 1; height <= 5; height++) {
			count = 0;
			for (w = width; w > 0; w--) {
				for (h = height; h > 0; h--)
					count += (width - w + 1) * (height - h + 1s);
			}
			diff = (target > count) ? target - count : count - target;
			if (diff < min_diff) {
				min_diff = diff;
				best_area = width*height;
			}
			std::cout << width << "x" << height << " = " << count << std::endl;
		}
	}

	std::cout << min_diff << " " << best_area << std::endl;

	return 0;
}
