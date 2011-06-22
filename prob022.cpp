#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


void parse(vector<string>& names, ifstream& file)
{
	string name;
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


unsigned short get_value(string& name)
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
	vector<string> names;
	ifstream file;
	unsigned i, size;
	unsigned long total = 0;

	file.open("names.txt");
	if (!file.is_open()) {
		cout << "Error opening file" << endl;
		return -1;
	}

	parse(names, file);
	file.close();

	sort(names.begin(), names.end());

	size = names.size();
	for (i = 0; i < size; i++)
		total += ((i + 1) * get_value(names[i]));

	cout << total << endl;

	return 0;
}
