#include <iostream>

using namespace std;


unsigned get_base(unsigned num)
{
	unsigned base = 1;

	while (num > 9) {
		base *= 10;
		num /= 10;
	}

	return base;
}


int main(void)
{
	unsigned num, tmp, n = 0, prod = 1, base;
	unsigned short dn;

	for (num = 1; ; num++) {
		base = get_base(num);
		tmp = num;

		while (base) {
			// update dn and n
			dn = tmp / base;
			tmp %= base;
			base /= 10;
			n++;

			if (n == 1 || n == 10 || n == 100 || n == 1000 || n == 10000 || n == 100000 || n == 1000000)
				prod *= dn;
		}

		if (n >= 1000000)
			break;
	}

	cout << prod << endl;

	return 0;
}
