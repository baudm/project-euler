#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

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


unsigned short get_word_value(string& name)
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
	ifstream file;
	vector<string> words;

	file.open("words.txt");
	if (!file.is_open()) {
		cout << "Error opening file" << endl;
		return -1;
	}

	parse(words, file);
	file.close();

	for (i = 0; i < words.size(); i++) {
		if (is_triangle(get_word_value(words[i])))
			triangles++;
	}

	cout << triangles << endl;

	return 0;
}
