#include <iostream>
#include <cmath>


int main(void)
{
	uint32_t a, b, p, max_p;
	uint16_t solutions, max_sols = 0;

	for (p = 12; p <= 1000; p++) {
		solutions = 0;
		for (a = 3; a <= p / 4; a++) {
			for (b = a + 1; b <= (p - a) / 2; b++) {
				if (a + b + sqrt(a*a + b*b) == p)
					solutions++;
			}
		}
		if (solutions > max_sols) {
			max_sols = solutions;
			max_p = p;
		}
	}

	std::cout << max_p << std::endl;

	return 0;
}
