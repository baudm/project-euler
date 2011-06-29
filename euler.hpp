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

	extern bool is_prime(uint64_t num);
}
