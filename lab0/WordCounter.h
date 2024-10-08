#pragma once

#include <list>
#include <string>
#include <map>

using namespace std;

class WordCounter {
public:

	bool isAlphanumeric(wchar_t c); // проверяем что строка из цифл или букв
	void processText(list < wstring >& words, list< pair < wstring, pair < int, double> > >& data); //обработка списка слов и запись в data

};