#include <iostream>



unsigned long f(unsigned long n)
{
	return (n % 2 == 0) ? n / 2 : 3*n + 1;
}


int main(void)
{
	long n, np, max = 0;
	unsigned ctr, max_ctr = 0;

	for (n = 999999; n > 0; n--) {
		np = n;
		ctr = 0;
		do {
			//std::cout << np << std::endl;
			np = f(np);
			ctr++;
		} while (np != 1);
		//std::cout << ctr << std::endl;
		if (ctr > max_ctr) {
			max = n;
			max_ctr = ctr;
		}
	}

	std::cout << max << std::endl;

	return 0;
}
