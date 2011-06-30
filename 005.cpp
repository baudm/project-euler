#include <iostream>
#include "euler.hpp"


int main(void)
{
	unsigned long i, l = 1;

	for (i = 2; i <= 20; i++)
		l = euler::lcm(l, i);

	std::cout << l << std::endl;

	return 0;
}
