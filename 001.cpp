#include <iostream>


int main(void)
{
	int i, sum = 0;

	for (i = 3; i < 1000; i++) {
		if (i % 3 == 0 || i % 5 == 0)
			sum += i;
	}

	std::cout << sum << std::endl;

	return 0;
}
