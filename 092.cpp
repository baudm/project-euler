#include <iostream>
#include <cstdint>
#include <vector>

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
	uint8_t sums[568] = {0}; // init all items to zero
	std::vector<uint16_t> steps;
	std::vector<uint16_t>::size_type i;

	sums[1] = 1;
	sums[89] = 89;

	for (num = 2; num < 10000000; num++) {
		digit_sum = get_digit_sum(num);
		steps.clear();
		/**
		 * Loop until we arrive at 1 or 89, or the current digit_sum
		 * already has an entry in the sums array.
		 */
		while (digit_sum != 1 && digit_sum != 89 && sums[digit_sum] == 0) {
			steps.push_back(digit_sum);
			digit_sum = get_digit_sum(digit_sum);
		}
		/**
		 * After the while loop finishes, digit_sum would be 1, 89, or another
		 * number which already has an entry in the sums array.
		 */
		digit_sum = sums[digit_sum];

		if (digit_sum == 89)
			count++;

		/**
		 * Store the end digit sum for all intermediate steps
		 */
		for (i = 0; i < steps.size(); i++)
			sums[steps[i]] = digit_sum;
	}

	std::cout << count << std::endl;

	return 0;
}
