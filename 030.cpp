#include <iostream>


bool check(unsigned long num)
{
	unsigned short digit;
	unsigned long sum = 0, tmp = num;

	while (tmp) {
		digit = tmp % 10;
		sum += digit * digit * digit * digit * digit;
		tmp /= 10;
	}

	return (sum == num);
}


unsigned short num_digits(unsigned long num)
{
	unsigned short digits = 0;

	while (num) {
		digits++;
		num /= 10;
	}

	return digits;
}


int main(void)
{
	unsigned long long num, sum = 0;
	unsigned short digits;
	const unsigned digit_max = 9 * 9 * 9 * 9 * 9;

	num = 10;
	do {
		if (check(num))
			sum += num;

		digits = num_digits(num);
		num++;

	/**
	 * Repeat until the number of digits overtakes the number of digits of the
	 * maximum possible digit sum
	 */
	} while (num_digits(digits * digit_max) >= digits);

	std::cout << sum << std::endl;

	return 0;
}
