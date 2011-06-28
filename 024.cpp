#include <iostream>
#include <algorithm>


int main(void)
{
	unsigned short digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	unsigned long i;

	for (i = 1; i < 1000000; i++)
		std::next_permutation(digits, digits + 10);

	for (i = 0; i < 10; i++)
		std::cout << digits[i];
	std::cout << std::endl;

	return 0;
}
