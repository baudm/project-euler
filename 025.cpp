#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>


class BigInt {
public:
	BigInt(std::string);
	BigInt& operator+=(const BigInt&);
	void dump(void);
	unsigned length(void);
private:
	std::string data;
};

BigInt::BigInt(std::string s)
{
	data = s;
}

BigInt& BigInt::operator+=(const BigInt& other)
{
	std::stringstream ss;
	std::string data_copy, other_copy;
	unsigned length;

	ss << std::setfill('0');
	if (data.length() > other.data.length()) {
		length = data.length();
		ss << std::setw(length) << other.data;
		data_copy = data;
		other_copy = ss.str();
	} else {
		length = other.data.length();
		ss << std::setw(length) << data;
		data_copy = ss.str();
		other_copy = other.data;
	}


	short digit_i;
	char digit;
	unsigned short partial_sum = 0;

	for (digit_i = length - 1; digit_i >= 0; digit_i--) {
		//std::cout << digit_i << std::endl;
		partial_sum += (data_copy.at(digit_i) - '0');
		partial_sum += (other_copy.at(digit_i) - '0');
		digit = (partial_sum % 10) + '0';
		data_copy[digit_i] = digit;
		partial_sum /= 10;
	}

	while (partial_sum) {
		//std::cout << partial_sum << std::endl;
		digit = (partial_sum % 10) + '0';
		partial_sum /= 10;
		data_copy.insert(data_copy.begin(), digit);
	}
	data.swap(data_copy);

	return *this;
}

void BigInt::dump(void)
{
	std::cout << data << std::endl;
}

unsigned BigInt::length(void)
{
	return data.length();
}


int main(void)
{
	BigInt a("1"), b("1");
	BigInt* prev = &a;
	BigInt* curr = &b;
	unsigned ctr = 2;

	while (prev->length() < 1000) {
		(*curr) += (*prev);
		// swap pointers
		if (curr == &a) {
			curr = &b;
			prev = &a;
		} else {
			curr = &a;
			prev = &b;
		}
		ctr++;
	}

	std::cout << ctr << std::endl;

	return 0;
}
