#include <iostream>
#include <string>
#include<fstream>

using namespace std;

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "fi_FI.UTF-8"); // ääkköset käyttöön
	
	string text; // isompi string josta etsitään
	string search; // pienempi string jota etsitään
	string row;
	fstream file;

	if (argc == 1) {

		// inkrementti 1

		cout << "Give a string from which to search for: " << endl;
		getline(cin, text);

		cout << "Give a search string: " << endl;
		getline(cin, search);

		size_t found = text.find(search);

		if (found != string::npos) {
			cout << "\"" << search << "\"" << " found in " << "\"" << text << "\"" << " in position " << found << endl;
		}
		else {
			cout << "\"" << search << "\"" << " NOT found in " << "\"" << text << "\"" << endl;
		}

	} 
	
	//inkrementti 2

	else if (argc == 3) {
		search = argv[1];
		text = argv[2];
		file.open(text);

		if (!file.is_open()) {
			cerr << "Error: Failure opening the file" << endl;
			return 1;
		}

		while (getline(file, row)) {
			if (row.find(search) != string::npos) {
				cout << row << endl;

			}
		}
	} file.close();

	return 0;
}