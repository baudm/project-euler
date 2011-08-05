#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include "euler.hpp"

struct pair {
	uint32_t n;
	uint32_t rad;
};


bool compare(struct pair a, struct pair b)
{
	if (a.rad != b.rad)
		return a.rad < b.rad;
	else
		return a.n < b.n;
}


uint32_t rad(uint32_t n)
{
	uint32_t p;
	uint32_t prod = 1;

	for (p = 2; p <= 3 && p <= n; p++) {
		if (!euler::is_prime(p))
			continue;
		if (n % p != 0)
			continue;
		prod *= p;
		while (n % p == 0)
			n /= p;
	}

	for (p = 5; p <= n; p += (p % 6 == 5) ? 2 : 4) {
		if (!euler::is_prime(p))
			continue;
		if (n % p != 0)
			continue;
		prod *= p;
		while (n % p == 0)
			n /= p;
	}

	return prod;
}


int main(void)
{
	std::vector<struct pair> data;
	struct pair d;
	uint32_t n;

	for (n = 1; n <= 100000; n++) {
		d.n = n;
		d.rad = rad(n);
		data.push_back(d);
	}

	std::sort(data.begin(), data.end(), compare);
	// E(10000)
	std::cout << data[9999].n << std::endl;

	return 0;
}
