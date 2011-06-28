#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>


void parse(std::vector<std::string>& names, std::ifstream& file)
{
	std::string name;
	char c;
	bool save = false;

	while (file.good()) {

		c = file.get();
		if (!file.good())
			break;

		if (c == '"') {
			if (save) {
				names.push_back(name);
				save = false;
			} else {
				name = "";
				save = true;
			}
		} else if (save) {
			name.push_back(c);
		}
	}
}


unsigned short get_word_value(std::string& name)
{
	unsigned short value = 0;
	unsigned short i, size = name.size();

	for (i = 0; i < size; i++)
		// A = 1, B = 2, C = 3, ...
		value += (name[i] - 'A') + 1;

	return value;
}


bool is_triangle(unsigned num)
{
	// good approximation
	unsigned n = sqrt(2 * num);

	return num == (n * (n + 1)) / 2;
}


int main(void)
{
	unsigned i, triangles = 0;
	std::ifstream file;
	std::vector<std::string> words;

	file.open("words.txt");
	if (!file.is_open()) {
		std::cout << "Error opening file" << std::endl;
		return -1;
	}

	parse(words, file);
	file.close();

	for (i = 0; i < words.size(); i++) {
		if (is_triangle(get_word_value(words[i])))
			triangles++;
	}

	std::cout << triangles << std::endl;

	return 0;
}
