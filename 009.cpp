#include <iostream>


bool is_triplet(unsigned short a, unsigned short b, unsigned short c)
{
	return (a*a + b*b == c*c);
}

int main(void)
{
	unsigned short a = 0, b, c;
	bool done = false;

	while (!done) {
		a++;
		b = a + 1;
		c = 1000 - (a + b);
		while (b < c + 1) {
			if (is_triplet(a, b, c)) {
				done = true;
				break;
			}
			b++;
			c--;
		}
	}

	//std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
	std::cout << a * b * c << std::endl;

	return 0;
}
