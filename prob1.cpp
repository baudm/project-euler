#include <iostream>

using namespace std;

int main(void)
{
	int i, sum = 0;

	for (i = 3; i < 1000; i++) {
		if (i % 3 == 0 || i % 5 == 0)
			sum += i;
	}

	cout << "Sum = " << sum << endl;

	return 0;
}
