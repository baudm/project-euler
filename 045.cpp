#include <iostream>
#include <cstdint>
#include <cmath>


uint64_t triangular(uint32_t n)
{
	return (n * (n + 1)) / 2;
}

bool is_pentagonal(uint64_t num)
{
	double s = sqrt(1 + 24 * num);

	// if root is not an integer, then num is not pentagonal
	if (floor(s) != s)
		return false;

	return (1 + uint32_t(s)) % 6 == 0;
}

bool is_hexagonal(uint64_t num)
{
	double s = sqrt(1 + 8 * num);

	// if root is not an integer, then num is not pentagonal
	if (floor(s) != s)
		return false;

	return (1 + uint32_t(s)) % 4 == 0;
}


int main(void)
{
	uint32_t n;
	uint64_t T;

	for (n = 286; ; n++) {
		T = triangular(n);
		if (is_pentagonal(T) && is_hexagonal(T))
			break;
	}

	std::cout << T << std::endl;

	return 0;
}
