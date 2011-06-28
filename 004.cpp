#include <iostream>



unsigned reverse_int(unsigned n)
{
	unsigned r = 0, u;

	while (n) {
		u = n % 10;
		n /= 10;
		r = r * 10 + u;
	}

	return r;
}


bool is_palindrome(unsigned n)
{
	return (n == reverse_int(n));
}

int main(void)
{
	unsigned a, b, p = 0;

	for (a = 999; a >= 100; a--) {
		for (b = a; b >= 100; b--) {
			if (is_palindrome(a * b) && a * b > p)
				p = a * b;
		}
	}

	std::cout << p << std::endl;

	return 0;
}
