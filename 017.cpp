#include <iostream>



unsigned short get_base(unsigned n)
{
	unsigned short base = 1;

	while (n > 9) {
		n /= 10;
		base *= 10;
	}

	return base;
}


unsigned short get_letter_count(unsigned n, unsigned short base)
{
	unsigned short count = 0;

	switch (base) {
	case 100:
		count += 7; // 'hundred'
	case 1:
		switch (n) {
		case 1:
		case 2:
		case 6:
			count += 3;
			break;
		case 4:
		case 5:
		case 9:
			count += 4;
			break;
		case 3:
		case 7:
		case 8:
			count += 5;
		}
		break;
	case 10:
		switch (n) {
		case 10:
			count += 3; // ten
			break;
		case 4:
		case 5:
		case 6:
			count += 5;
			break;
		case 11:
		case 12:
		case 2:
		case 3:
		case 8:
		case 9:
			count += 6;
			break;
		case 15:
		case 16:
		case 7:
			count += 7;
			break;
		case 13:
		case 14:
		case 18:
		case 19:
			count += 8;
			break;
		case 17:
			count += 9;
		}
		break;
	case 1000:
		count += 11; // 'one thousand'
	}

	return count;
}


int main(void)
{
	unsigned num, i, count = 0;
	unsigned short digit, base;

	for (i = 1; i <= 1000; i++) {
		base = get_base(i);
		num = i;
		//count = 0; // debug
		while (num) {
			if (num < 10 || num > 19) {
				digit = num / base;
				//std::cout << "Digit: " << digit << ", num = " << num << ", base = " << base << std::endl;
				count += get_letter_count(digit, base);
				num %= base;
			} else { // special case
				count += get_letter_count(num, 10);
				break;
			}
			base /= 10;
		}
		if (i > 100 && i < 1000 && i % 100)
			count += 3; // 'and'
	}

	std::cout << count << std::endl;

	return 0;
}
