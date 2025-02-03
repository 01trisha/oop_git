#include "TextFile.h"
#include "CSV.h"
#include "WordCounter.h"

#include <iostream>
#include <string>
#include <list>
#include <locale>

using namespace std;


int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Russian");

	if (argc < 2) {
		cout << "Usage: ./lab0b Text.txt" << endl;
		return 1;
	}

	string Text = argv[1];

	CSV csv; //создаем экземпляр класса который будет использоваться для записи значений

	TextFile textFile(Text);

	list<wstring> words = textFile.readText();

	list<pair<wstring, pair<int, double>>> data;
	
	WordCounter counter;
	counter.processText(words, data);

	csv.writeToFile("output.csv", data);

	return 0;
}