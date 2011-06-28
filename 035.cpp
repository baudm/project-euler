#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>



bool is_prime(unsigned long num)
{
	unsigned p, s = sqrt(num);

	if (2 <= s && num % 2 == 0)
		return false;

	if (3 <= s && num % 3 == 0)
		return false;

	for (p = 5; p <= s; p += (p % 6 == 5) ? 2 : 4) {
		if (num % p == 0)
			return false;
	}

	return true;
}


void get_base_and_digits(unsigned long num, unsigned* base, unsigned short* digits)
{
	*base = 1;
	*digits = 0;
	while (num > 9) {
		(*base) *= 10;
		(*digits)++;
		num /= 10;
	}
	(*digits)++;
}


unsigned next_rotation(unsigned num, unsigned base)
{
	unsigned short digit;

	digit = num % 10;
	num /= 10;
	num += digit * base;

	return num;
}

/**
 * basically, a circular prime cannot contain even digits and 5
 */
bool can_be_circ_prime(unsigned num)
{
	unsigned short digit;

	while (num) {
		digit = num % 10;
		if (digit % 2 == 0 || digit == 5)
			return false;
		num /= 10;
	}

	return true;
}


int main(void)
{
	unsigned num, rotation, base;
	unsigned short digits, i;
	std::vector<unsigned> circular_primes, buffer;
	bool circ_prime;

	for (num = 101; num < 1000000; num += (num % 6 == 5) ? 2 : 4) {
		if (!can_be_circ_prime(num))
			continue;
		if (!is_prime(num))
			continue;
		if (find(circular_primes.begin(), circular_primes.end(), num) != circular_primes.end())
			continue;
		get_base_and_digits(num, &base, &digits);
		rotation = num;
		circ_prime = true;
		buffer.clear();
		for (i = 1; i < digits; i++) {
			rotation = next_rotation(rotation, base);
			if (!is_prime(rotation)) {
				circ_prime = false;
				break;
			}
			buffer.push_back(rotation);
		}
		if (!circ_prime)
			continue;
		circular_primes.push_back(num);
		for (i = 0; i < buffer.size(); i++)
			circular_primes.push_back(buffer[i]);
	}

	std::cout << circular_primes.size() + 13 << std::endl;

	return 0;
}
