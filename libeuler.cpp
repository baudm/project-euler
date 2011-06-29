#include <set>
#include <cmath>
#include <cstdint>

namespace euler
{
	bool is_prime(uint64_t num)
	{
		// initially contains the first two prime numbers, 2 and 3
		static uint32_t init[] = {2, 3};
		static std::set<uint32_t> primes(init, init + 2);
		std::set<uint32_t>::iterator it;
		uint32_t p, s = sqrt(num);

		for (it = primes.begin(); it != primes.end(); ++it) {
			if (*it > s)
				break;
			if (num % *it == 0)
				return false;
		}

		// continue were we left off
		--it;
		for (p = *it; p <= s; p += (p % 6 == 5) ? 2 : 4) {
			if (num % p == 0)
				return false;
		}

		// save num
		primes.insert(num);

		return true;
	}
}
