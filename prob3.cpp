#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(unsigned n)
{
	unsigned i, s = sqrt(n);

	for (i = 2; i <= s; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}


int main(void)
{
	unsigned long n = 600851475143;
	unsigned i, j, gpf = 1;

	for (i = sqrt(n); i > 0; i--) {
		if (n % i == 0) {
			j = n / i;
			if (!is_prime(j)) {
				if (is_prime(i) && i > gpf)
					gpf = i;
			} else if (j > gpf) {
				gpf = j;
				break;
			}
		}
	}

	cout << gpf << endl;

	return 0;
}
