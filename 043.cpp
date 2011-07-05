#include <iostream>
#include <cstdint>
#include <algorithm>


uint32_t get_value(uint8_t* start, uint8_t* end)
{
	uint32_t value = 0;

	while (start != end) {
		value = 10 * value + *start;
		start++;
	}

	return value;
}


int main(void)
{
	uint8_t number[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	uint8_t primes[] = {2, 3, 5, 7, 11, 13, 17};
	uint8_t i;
	uint64_t sum = 0;
	bool interesting;

	do {
		interesting = true;

		for (i = 0; i < 7; i++) {
			if (get_value(number + i + 1, number + i + 4) % primes[i] != 0) {
				interesting = false;
				break;
			}
		}

		if (interesting)
			sum += get_value(number, number + 10);

	} while (std::next_permutation(number, number + 10));

	std::cout << sum << std::endl;

	return 0;
}
