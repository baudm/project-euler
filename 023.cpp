#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


bool is_abundant(unsigned num)
{
	unsigned i, sum = 1, s = sqrt(num);

	for (i = 2; i <= s; i++) {
		if (num % i == 0) {
			sum += i;
			if (num != i * i)
				sum += num / i;
		}
	}

	return sum > num;
}


bool is_sum_of_2_abundant(unsigned num)
{
	// initial element is the smallest abundant number
	static vector<unsigned> abundant(1, 12);
	unsigned last;
	unsigned short i;

	// generate abundant numbers up to num - 12
	for (last = abundant[abundant.size() - 1] + 1; last + 12 < num; last++) {
		if (is_abundant(last))
			abundant.push_back(last);
	}

	// check if num can be expressed as a sum of two abundant numbers
	for (i = 0; i < abundant.size(); i++) {
		if (abundant[i] + 12 > num)
			break;
		if (is_abundant(num - abundant[i]))
			return true;
	}

	return false;
}


int main(void)
{
	int i, sum = 0;

	for (i = 1; i <= 20161; i++) {
		if (!is_sum_of_2_abundant(i))
			sum += i;
	}

	cout << sum << endl;

	return 0;
}
