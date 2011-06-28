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

	for (i = 0; i < primes.size() && primes[i] <= s; i++) {
		if (num % primes[i] == 0)
			return false;
	}

	// continue were we left off
	for (j = primes[i - 1] + 1; j <= s; j++) {
		if (num % j == 0)
			return false;
	}

	// we don't need primes beyond 1414 (sqrt of 2M)
	if (num <= 1414)
		primes.push_back(num);

	return true;
}


int main(void)
{
	unsigned i;
	long long sum = 5; // 2 + 3

	for (i = 5; i < 2000000; i += (i % 6 == 5) ? 2 : 4) {
		if (is_prime(i))
			sum += i;
	}

	cout << "Sum = " << sum << endl;

	return 0;
}
