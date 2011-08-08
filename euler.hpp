#include <string>
#include <vector>
#include <map>
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
		if (num == 1)
			return false;

		T s = sqrt(num);
		if ((num % 2 == 0 && 2 <= s) || (num % 3 == 0 && 3 <= s))
			return false;

		/**
		 * All primes, except 2 and 3, are of the form 6k +/- 1
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

	template<typename T, typename U>
	T reverse_int(T num, U base)
	{
		T rev = 0;
		U digit;

		while (num) {
			digit = num % base;
			num /= base;
			rev = rev * base + digit;
		}

		return rev;
	}

	template<typename T, typename U>
	inline bool is_palindrome_int(T num, U base)
	{
		return num == reverse_int(num, base);
	}

	template<typename Iterator>
	bool is_palindrome_seq(Iterator start, Iterator end)
	{
		--end;
		while (start != end) {
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
		if (n == 0)
			return 1;

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

	template<typename T>
	T gcf(T a, T b)
	{
		while (a && b) {
			if (a > b)
				a %= b;
			else
				b %= a;
		}
		return (a) ? a : b;
	}

	template<typename T>
	inline T lcm(T a, T b)
	{
		return a * (b / gcf<T>(a, b));
	}

	/**
	 * order of a mod n
	 */
	template<typename T, typename U>
	U order(T a, U n)
	{
		U k = 1;
		U rem = a % n;

		while (rem != 1) {
			rem = (a * rem) % n;
			k++;
		}

		return k;
	}

	template<typename T, typename U, typename Iterator>
	T digits_to_int(U base, Iterator start, Iterator end)
	{
		T value = *start++;

		while (start != end)
			value = base * value + *start++;

		return value;
	}

	template<typename T, typename U, typename Iterator>
	void int_to_digits(T num, U base, Iterator start, Iterator end)
	{
		/**
		 * Shift the start and end iterators to the left so that
		 * the value of the start iterator becomes invalid while
		 * the value of the end iterator becomes valid.
		 */
		--start;
		--end;
		while (end != start && num) {
			*end = num % base;
			num /= base;
			--end;
		}
	}

	template<typename T, typename U>
	inline T triangular(U n)
	{
		return n*(n + 1)/2;
	}

	template<typename T, typename U>
	inline T pentagonal(U n)
	{
		return n*(3*n - 1)/2;
	}

	/**
	 * This is the actual implementation of the partition function
	 * based on the recurrence relation of p(n)
	 */
	template<typename T, typename U>
	T p(U n)
	{
		if (n == 0)
			return 1;

		static std::map<U,T> cache; // cache for memoization
		T c, count = 0;
		U k, x, num;
		uint8_t i;

		// generate generalized pentagonal numbers up to n
		for (k = 1; ; k++) {
			// for positive and negative k
			for (i = 0; i < 2; i++) {
				num = (i == 0) ? euler::pentagonal<U>(k) : euler::pentagonal<U>(-k);
				if (num > n)
					break;
				x = n - num;
				// cache hit is more likely
				if (cache[x]) {
					c = cache[x];
				} else {
					c = p<T>(x);
					cache[x] = c;
				}
				// even: negative, odd: positive
				if (k % 2 == 0)
					count -= c;
				else
					count += c;
			}
			if (num > n)
				break;
		}

		return count;
	}

	template<typename T, typename Iterator>
	T roman_to_int(Iterator start, Iterator end)
	{
		static std::map<char,T> numerals = {
			{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
			{'C', 100}, {'D', 500}, {'M', 1000}
		};
		T value = 0;
		T curr, prev = 0;

		do {
			curr = numerals[*start++];
			value += curr;
			if (curr > prev)
				value -= 2*prev;
			prev = curr;
		} while (start != end);

		return value;
	}

	template<typename T>
	std::string int_to_roman(T value)
	{
		static std::map<T,std::string> numerals = {
			{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"},
			{10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"},
			{100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"},
			{1000, "M"}
		};
		typename std::map<T,std::string>::reverse_iterator rit;
		std::string out;

		while (value) {
			for (rit = numerals.rbegin(); rit != numerals.rend(); ++rit) {
				if (value >= rit->first) {
					value -= rit->first;
					out += rit->second;
					break;
				}
			}
		}

		return out;
	}

	template<typename T>
	bool is_permutation(T a, T b)
	{
		uint8_t count[2][10] = {}; // initialize all to zero
		T *nums[] = {&a, &b};
		uint8_t digit, i;

		/**
		 * For both numbers, count how many times each digit is used.
		 */
		for (i = 0; i < 2; i++) {
			while (*nums[i]) {
				digit = *nums[i] % 10;
				count[i][digit]++;
				*nums[i] /= 10;
			}
		}

		/**
		 * If a and b are permutations of each other, the count for each digit
		 * should be the same.
		 */
		for (i = 0; i < 10; i++) {
			if (count[0][i] != count[1][i])
				return false;
		}

		return true;
	}
}
