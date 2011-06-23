#include <iostream>

using namespace std;


enum days_t {
	SUNDAY,
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY
};

enum months_t {
	JAN,
	FEB,
	MAR,
	APR,
	MAY,
	JUN,
	JUL,
	AUG,
	SEP,
	OCT,
	NOV,
	DEC
};


int main(void)
{
	const unsigned short YEAR = 365, WEEK = 7;
	const days_t jan_1_1900 = MONDAY;
	unsigned day, year;
	unsigned short sundays = 0;
	unsigned short month;

	// set reference day number: Jan 1, 1901
	day = jan_1_1900 + YEAR;
	for (year = 1901; year <= 2000; year++) {
		for (month = JAN; month <= DEC; month++) {

			if (day % WEEK == SUNDAY)
				sundays++;

			switch (month) {
			case FEB:
				day += 28;
				break;
			case APR:
			case JUN:
			case SEP:
			case NOV:
				day += 30;
				break;
			default:
				day += 31;
			}
			// for leap years, add one more day
			if (month == FEB && year % 4 == 0 && year != 2000)
				day++;
		}
	}

	cout << sundays << endl;

	return 0;
}
