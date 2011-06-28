#include <iostream>


unsigned long gcf(unsigned long a, unsigned long b)
{
	while (a && b) {
		if (a > b)
			a %= b;
		else
			b %= a;
	}
	return (a) ? a : b;
}

unsigned long lcm(unsigned long a, unsigned long b)
{
	return a * (b / gcf(a, b));
}

int main(void)
{
	unsigned long i, l = 1;

	for (i = 2; i <= 20; i++)
		l = lcm(l, i);

	std::cout << l << std::endl;

	return 0;
}
