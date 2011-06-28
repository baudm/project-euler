#include <iostream>


bool check(unsigned long num, unsigned short* digits)
{
	unsigned short digit;
	unsigned long sum = 0, tmp = num;
	static unsigned factorials[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

	*digits = 0;
	while (tmp) {
		digit = tmp % 10;
		sum += factorials[digit];
		tmp /= 10;
		(*digits)++;
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
	const unsigned digit_max = 362880; // 9!

	num = 10;
	do {
		if (check(num, &digits))
			sum += num;

		num++;
	/**
	 * Repeat until the number of digits overtakes the number of digits of the
	 * maximum possible digit sum
	 */
	} while (num_digits(digits * digit_max) >= digits);

	std::cout << sum << std::endl;

	return 0;
}
