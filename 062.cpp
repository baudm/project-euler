#include <iostream>
#include <algorithm>
#include <deque>
#include <cstdint>
#include "euler.hpp"


void get_digits(uint64_t num, std::deque<uint8_t>& digits)
{
	digits.clear();
	while (num) {
		digits.push_front(num % 10);
		num /= 10;
	}
}

bool is_cube(uint64_t num)
{
	uint64_t root = std::round(std::cbrt(num));
	return root*root*root == num;
}


int main(void)
{
	uint64_t i;
	uint64_t cube, perm;
	std::deque<uint8_t> digits;
	std::deque<uint64_t> cubes;

	for (i = 5026; ; i++) {
		cube = i*i*i;
		get_digits(cube, digits);
		cubes.clear();
		// start from lowest permutation
		std::sort(digits.begin(), digits.end());

		do {
			// skip permutations with leading zeroes
			if (digits.front() == 0)
				continue;

			perm = euler::digits_to_int<uint64_t>(10, digits.begin(), digits.end());

			if (is_cube(perm))
				cubes.push_back(perm);

		} while (std::next_permutation(digits.begin(), digits.end()));

		if (cubes.size() == 5)
			break;
	}

	std::sort(cubes.begin(), cubes.end());
	std::cout << cubes.front() << std::endl;

	return 0;
}
