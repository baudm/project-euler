#include <iostream>

using namespace std;

int main(void)
{
	unsigned long sum = 0;
	unsigned num = 1;
	unsigned short i, diff = 2;
	const unsigned limit = 1001 * 1001;

	sum += num;
	while (num < limit) {
		// four corners of each 'layer' of the spiral
		for (i = 0; i < 4; i++) {
			num += diff;
			sum += num;
		}
		diff += 2;
	}

	cout << sum << endl;

	return 0;
}
