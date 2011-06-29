#include <iostream>
#include <cstdint>

/**
 * A fast and simple way of calculating a "digit signature"
 * 
 * Returns the sum of the product and the sum of the digits 
 *
 * There _might_ be collisions between two or more numbers
 * but this function works well in this case.
 */
uint16_t digit_sig(uint32_t num)
{
	uint16_t prod = 1;
	uint8_t sum = 0, digit;

	while (num) {
		digit = num % 10;
		if (digit) {
			prod *= digit;
			sum += digit;
		}
		num /= 10;
	}

	return sum + prod;
}


int main(void)
{
	uint32_t start = 10, end = 16;
	uint32_t num;
	uint16_t sig;
	bool go = true;

	while (start <= 1000000 && go) {
		for (num = start; num <= end; num++) {
			sig = digit_sig(num);
			if (digit_sig(2 * num) == sig && digit_sig(3 * num) == sig &&
			    digit_sig(4 * num) == sig && digit_sig(5 * num) == sig &&
			    digit_sig(6 * num) == sig) {
				go = false;
				break;
			}
		}
		start *= 10;
		end = end * 10 + 6;
	}

	std::cout << num << std::endl;

	return 0;
}
