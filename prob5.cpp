#include <iostream>

using namespace std;

int gcf(int a, int b)
{
	while (a && b) {
		if (a > b)
			a %= b;
		else
			b %= a;
	}
	return (a) ? a : b;
}

unsigned long int lcm(int a, int b)
{
	return long(a) * b / gcf(a, b);
}

int main(void)
{
	unsigned long int i, l = 1;

	for (i = 2; i <= 20; i++) {
		l = lcm(l, i);
		cout << "i = " << i << ", l = " << l << endl;
	}



	return 0;
}
