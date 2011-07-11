#include <iostream>
#include <cstdint>

int main(void)
{
	uint16_t a;
	uint32_t r_max_sum = 0;

	for (a = 3; a <= 1000; a++) {
		if (a % 2 == 0)
			r_max_sum += a*(a - 2);
		else
			r_max_sum += a*(a - 1);
	}

	std::cout << r_max_sum << std::endl;

	return 0;
}
