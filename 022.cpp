#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>


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


unsigned short get_value(std::string& name)
{
	unsigned short value = 0;
	unsigned short i, size = name.size();

	for (i = 0; i < size; i++)
		// A = 1, B = 2, C = 3, ...
		value += (name[i] - 'A') + 1;

	return value;
}


int main(void)
{
	std::vector<std::string> names;
	std::ifstream file;
	unsigned i, size;
	unsigned long total = 0;

	file.open("names.txt");
	if (!file.is_open()) {
		std::cout << "Error opening file" << std::endl;
		return -1;
	}

	parse(names, file);
	file.close();

	sort(names.begin(), names.end());

	size = names.size();
	for (i = 0; i < size; i++)
		total += ((i + 1) * get_value(names[i]));

	std::cout << total << std::endl;

	return 0;
}
