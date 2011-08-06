#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdint>
#include "euler.hpp"

int main(void)
{
	std::string line;
	std::ifstream file;
	uint16_t saved_chars = 0;
	uint16_t value;

	file.open("roman.txt");
	if (!file.is_open()) {
		std::cout << "Error opening file" << std::endl;
		return -1;
	}

	while (file.good()) {
		std::getline(file, line);
		// there is a trailing space in most lines; remove it
		if (std::isspace(*(line.end() - 1)))
			line.erase(line.end() - 1);

		value = euler::roman_to_int<uint16_t>(line.begin(), line.end());
		saved_chars += line.size() - euler::int_to_roman(value).size();
	}
	file.close();

	std::cout << saved_chars << std::endl;

	return 0;
}
