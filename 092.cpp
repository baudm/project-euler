#include <iostream>
#include <cstdint>

uint16_t get_digit_sum(uint32_t num)
{
	uint8_t digit;
	uint16_t sum = 0;

	while (num) {
		digit = num % 10;
		sum += digit * digit;
		num /= 10;
	}

	return sum;
}


int main(void)
{
	uint32_t num, count = 0;
	uint16_t digit_sum; // max digit sum is 7 * 9^2 = 567

	for (num = 2; num < 10000000; num++) {
		if (num != 1 && num != 89) {
			digit_sum = get_digit_sum(num);
			while (digit_sum != 1 && digit_sum != 89)
				digit_sum = get_digit_sum(digit_sum);
		} else {
			digit_sum = num;
		}

		if (digit_sum == 89)
			count++;
	}

	std::cout << count << std::endl;

	return 0;
}
