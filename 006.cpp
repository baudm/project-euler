#include <iostream>


int main(void)
{
	unsigned long sum_of_squares = 0, sum = 0;
	unsigned short i;

	for (i = 1; i <= 100; i++)
		sum_of_squares += i * i;

	for (i = 1; i <= 100; i++)
		sum += i;

	std::cout << (sum * sum) - sum_of_squares << std::endl;

	return 0;
}
