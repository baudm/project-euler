#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	unsigned short digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	unsigned long i;

	for (i = 1; i < 1000000; i++)
		next_permutation(digits, digits + 10);

	for (i = 0; i < 10; i++)
		cout << digits[i];
	cout << endl;

	return 0;
}
