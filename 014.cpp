#include <iostream>

using namespace std;


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
			//cout << np << endl;
			np = f(np);
			ctr++;
		} while (np != 1);
		//cout << ctr << endl;
		if (ctr > max_ctr) {
			max = n;
			max_ctr = ctr;
		}
	}

	cout << max << endl;

	return 0;
}
