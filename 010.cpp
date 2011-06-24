#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool is_prime(unsigned long num)
{
	// initially contains the first prime number, 2
	static vector<unsigned> primes(1, 2);
	unsigned s = sqrt(num);
	unsigned short i, j;

	for (i = 0; primes[i] <= s; i++) {
		if (num % primes[i] == 0)
			return false;
	}

	// continue were we left off
	for (j = primes[i - 1] + 1; j <= s; j++) {
		if (num % j == 0)
			return false;
	}

	// we don't need primes beyond 1423
	if (num <= 1423)
		primes.push_back(num);

	return true;
}


int main(void)
{
	unsigned i;
	long long sum = 0;

	for (i = 2; i < 2000000; i++) {
		if (is_prime(i))
			sum += i;
	}

	cout << "Sum = " << sum << endl;

	return 0;
}
