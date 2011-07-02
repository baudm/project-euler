#include <iostream>
#include <cstdint>


int main(void)
{
	uint64_t last_ten_digits = 28433;
	const uint32_t exp = 7830457;
	uint32_t i;

	for (i = 0; i < exp; i++) {
		last_ten_digits *= 2;
		// clear digits beyond the 10th one
		last_ten_digits %= 10000000000LL;
	}
	last_ten_digits++;

	std::cout << last_ten_digits << std::endl;

	return 0;
}
