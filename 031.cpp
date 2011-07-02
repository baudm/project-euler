#include <iostream>
#include <cstdint>


int main(void)
{
	// Coefficients of 1p, 2p, 5p, 10p, 20p, 50p, 100p
	uint8_t a, b, c, d, e, f, g;
	const uint8_t sum = 200;
	// 200p is a solution itself already, so we start the count at 1
	uint32_t solutions = 1;

	for (a = 0; a <= sum; a++) {
		for (b = 0; b <= sum / 2; b++) {
			for (c = 0; c <= sum / 5; c++) {
				for (d = 0; d <= sum / 10; d++) {
					for (e = 0; e <= sum / 20; e++) {
						for (f = 0; f <= sum / 50; f++) {
							for (g = 0; g <= sum / 100; g++) {
								if (a + 2*b + 5*c + 10*d + 20*e + 50*f + 100*g == sum)
									solutions++;
							}
						}
					}
				}
			}
		}
	}

	std::cout << solutions << std::endl;

	return 0;
}
