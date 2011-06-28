#include <iostream>



unsigned f(unsigned n)
{
	return (n > 1) ? f(n - 1) + f(n - 2) : 1;
}


int main(void)
{
	unsigned n = 2, fn = 0, sum = 0;

	while (fn < 4000000) {
		sum += fn;
		fn = f(n);
		n += 3;
	}

	std::cout << sum << std::endl;

	return 0;
}
