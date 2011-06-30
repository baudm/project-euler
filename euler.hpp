#include <cmath>
#include <cstdint>

namespace euler
{
	// Reference: http://oeis.org/A000045
	template<typename T, typename U>
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

	template<typename T>
	bool is_prime(T const& num)
	{
		T s = sqrt(num);

		if (num == 1 || (num % 2 == 0 && 2 <= s) || (num % 3 == 0 && 3 <= s))
			return false;

		/**
		 * All primes are of the form 6k +/- 1
		 * Thus, only integers of this form, up to sqrt(num),
		 * are needed for the primality test.
		 */
		T p;
		for (p = 5; p <= s; p += 6) {
			if (num % p == 0 || num % (p + 2) == 0)
				return false;
		}

		return true;
	}

	template<typename T=uint8_t, typename U>
	T digit_count(U num)
	{
		T digits = 0;

		while (num) {
			digits++;
			num /= 10;
		}

		return digits;
	}

	template<typename T>
	T reverse_int(T num, uint8_t base)
	{
		T rev = 0;
		uint8_t digit;

		while (num) {
			digit = num % base;
			num /= base;
			rev = rev * base + digit;
		}

		return rev;
	}

	template<typename T>
	bool is_palindrome_int(T num, uint8_t base)
	{
		return num == reverse_int(num, base);
	}

	template<typename Iterator>
	bool is_palindrome_seq(Iterator start, Iterator end)
	{
		--end;
		while (start < end) {
			if (*start != *end)
				return false;
			++start;
			--end;
		}

		return true;
	}

	template<typename T, typename U>
	T factorial(U n)
	{
		T fac = n;

		while (n > 1) {
			n--;
			fac *= n;
		}

		return fac;
	}

	template<typename T, typename U>
	inline T combination(U n, U r)
	{
		return factorial<T>(n) / (factorial<T>(r) * factorial<T>(n - r));
	}
}
