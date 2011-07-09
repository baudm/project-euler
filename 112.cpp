#include <iostream>
#include <cstdint>


bool is_bouncy(uint32_t num)
{
	uint8_t digit, prev_digit = num % 10;
	int8_t diff, prev_diff = 0;

	num /= 10;
	while (num) {
		digit = num % 10;
		diff = prev_digit - digit;
		/*
		 * The product of diff and prev_diff will be negative only if their
		 * signs are different, i.e. their directions are different.
		 */
		if (diff * prev_diff < 0)
			return true;
		prev_digit = digit;
		if (diff != 0)
			prev_diff = diff;
		num /= 10;
	}

	return false;
}


int main(void)
{
	const uint8_t target_percent = 99;
	uint32_t num;
	uint32_t bouncy = 0;

	for (num = 100; ; num++) {
		if (is_bouncy(num))
			bouncy++;
		if (100*bouncy == target_percent*num)
			break;
	}

	std::cout << num << std::endl;

	return 0;
}
