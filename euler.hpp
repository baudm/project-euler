#include <cmath>

namespace euler
{
	// Reference: http://oeis.org/A000045
	template <typename T, typename U>
	T fib(U n)
	{
		if (n == 0)
			return 0;

		T tmp, prev = 0, curr = 1;

		while (n > 1) {
			tmp = curr;
			curr += prev;
			prev = tmp;
			n--;
		}

		return curr;
	}

	template <typename T>
	bool is_prime(T const& num)
	{
		T s = sqrt(num);

		if (num % 2 == 0 && 2 <= s)
			return false;

		if (num % 3 == 0 && 3 <= s)
			return false;

		T k, p = 5;

		for (k = 1; p <= s; k++) {
			p = 6 * k - 1;
			if (num % p == 0 || num % (p + 2) == 0)
				return false;
		}

		return true;
	}
}
