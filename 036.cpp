#include <iostream>
#include <string>



void get_digits(unsigned long num, unsigned short base, std::string& digits)
{
	char digit;

	digits.clear();
	while (num) {
		digit = (num % base) + '0';
		digits.push_back(digit);
		num /= base;
	}
}


bool is_palindrome(std::string const& str)
{
	unsigned short i, s = str.size();

	for (i = 0; i < s / 2; i++) {
		if (str[i] != str[s - i - 1])
			return false;
	}

	return true;
}


int main(void)
{
	unsigned long num, sum = 0;
	std::string digits;

	for (num = 1; num < 1000000; num++) {
		get_digits(num, 10, digits);
		if (!is_palindrome(digits))
			continue;

		get_digits(num, 2, digits);
		if (is_palindrome(digits))
			sum += num;
	}

	std::cout << sum << std::endl;

	return 0;
}
