#include <iostream>
#include <cstdint>
#include <cmath>
#include "euler.hpp"

#define DIGIT_MAX 19


int main(void)
{
	uint64_t root, square;
	uint8_t digits[DIGIT_MAX] = {1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 7, 0, 8, 0, 9, 0, 0};

	/**
	 * Main reference: http://en.wikipedia.org/wiki/Square_number#Properties
	 *
	 * In base 10, all squares end only with 00, 1, 4, 6, 9, or 25.
	 * For 1_2_3_4_5_6_7_8_9_0 to be a square, the last unknown digit should be 0
	 * making it 1_2_3_4_5_6_7_8_900.
	 *
	 * Moreover, since the square ends in 00, the preceding digits must also form a square.
	 * Since 1_2_3_4_5_6_7_8_9 is a square which ends in 9, the number formed
	 * by the preceding digits, 1_2_3_4_5_6_7_8_, should be divisible by 4.
	 *
	 * For 1_2_3_4_5_6_7_8_ to be divisible by 4, its last two digits, 8_, should
	 * also be divisible by 4. The only possible solutions for this requirement are
	 * 80, 84, and 88.
	 *
	 * Thus, we only check the numbers ending in 80900, 84900, or 88900.
	 */
	for (digits[1] = 0; digits[1] <= 9; digits[1]++) {
		for (digits[3] = 0; digits[3] <= 9; digits[3]++) {
			for (digits[5] = 0; digits[5] <= 9; digits[5]++) {
				for (digits[7] = 0; digits[7] <= 9; digits[7]++) {
					for (digits[9] = 0; digits[9] <= 9; digits[9]++) {
						for (digits[11] = 0; digits[11] <= 9; digits[11]++) {
							for (digits[13] = 0; digits[13] <= 9; digits[13]++) {
								for (digits[15] = 0; digits[15] <= 8; digits[15] += 4) {
									square = euler::digits_to_int<uint64_t>(10, digits, digits + DIGIT_MAX);
									root = std::round(std::sqrt(square));
									if (root*root == square)
										goto done; // I'm lazy
								}
							}
						}
					}
				}
			}
		}
	}
done:
	std::cout << root << std::endl;

	return 0;
}
