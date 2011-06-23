#include <iostream>
#include <cmath>

using namespace std;

unsigned long tri(unsigned n)
{
	unsigned long sum = 0;

	while (n > 0) {
		sum += n;
		n--;
	}

	return sum;
}

unsigned short get_div_num(unsigned long tri)
{
	unsigned short divs = 2;
	unsigned i, s = sqrt(tri);

	for (i = 2; i <= s; i++) {
		if (tri % i == 0)
			divs += 2;
	}

	return divs;
}

unsigned short get_div_num_opt(unsigned long tri)
{
	unsigned short divs = 1, exp;
	unsigned i;

	for (i = 2; tri > 1; i++) {
		exp = 1;
		while (tri % i == 0) {
			tri /= i;
			exp++;
		}
		divs *= exp;
	}

	return divs;
}

int main(void)
{
	unsigned long num;
	unsigned i;

	for (i = 100; ; i++) {
		num = tri(i);
		if (get_div_num_opt(num) > 500)
			break;
	}

	cout << num << endl;

	return 0;
}
