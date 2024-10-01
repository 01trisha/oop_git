#include "CSV.h"


void CSV::writeToFile(std::string Text1, list<pair<wstring, pair<int, double> > >& data) { // берем имя файла и список пар и записываем в в формате csv
	std::wofstream file(Text1);
	file.imbue(std::locale(""));

	file << L"Word; Freq; Freq_perc\n";
	for (auto& item : data) {
		file << L"" << item.first << L";" << item.second.first << L";" << item.second.second << L"\n";
	}
	file.close();
}