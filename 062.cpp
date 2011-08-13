#include <iostream>
#include <vector>
#include <cstdint>
#include "euler.hpp"

int main(void)
{
	uint64_t cube, target_cube = 0;
	std::vector<uint64_t> cubes;
	std::vector<uint64_t>::size_type j;

	uint64_t i = 5;
	uint64_t limit = 1000;

	while (true) {
		/**
		 * Generate cubes up to limit
		 */
		cubes.clear();
		for (; ; i++) {
			cube = i*i*i;
			if (cube >= limit)
				break;
			cubes.push_back(cube);
		}

		for (j = 0; j < cubes.size(); j++) {
			std::vector<uint64_t>::size_type k;
			uint8_t perms = 0;

			for (k = 0; k < cubes.size(); k++) {
				if (euler::is_permutation(cubes[j], cubes[k]))
					perms++;
			}
			if (perms == 5) {
				target_cube = cubes[j];
				break;
			}
		}

		if (target_cube)
			break;

		limit *= 10;
	}

	std::cout << target_cube << std::endl;

	return 0;
}
