#include "TextFile.h"
#include "CSV.h"
#include "WordCounter.h"

#include <iostream>
#include <string>
#include <list>
#include <locale>

using namespace std;


int main(int argc, char* argv[]) { // argc - колво агруметов, argv - массив строк с аргументами
	setlocale(LC_ALL, "Russian");

	if (argc < 2) {
		cout << "Usage: ./lab0b Text.txt" << endl;
		return 1;
	}

	string Text = argv[1];

	CSV csv;
	TextFile textFile(Text);

	list<wstring> words = textFile.readText();

	list<pair<wstring, pair<int, double>>> data;
	
	WordCounter counter;
	counter.processText(words, data);

	csv.writeToFile("output.csv", data);

	return 0;
}