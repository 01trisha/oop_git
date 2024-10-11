#include "WordCounter.h"
#include <iostream>
#include <string>
#include <list>
#include <locale>

//счет слов

bool WordCounter::isAlphanumeric(wchar_t c) { // проверяем что текст или цифры или буквы
	return	(c >= L'a' && c <= L'z') || (c >= L'A' && c <= L'Z') ||
		(c >= L'А' && c <= L'Я') || (c >= L'а' && c <= L'я') ||
		(c >= L'0' && c <= L'9');
}

void WordCounter::processText(list <wstring>& words, list<pair<wstring, pair<int, double>>>& data) {
	map <wstring, int> wordCount; 
	int totalWords = 0; // общее колво слов
	for (auto& line : words) {
		wstring word;
		for (wchar_t c : line) {
			if (isAlphanumeric(c)) {
				word += towlower(c);
			}
			else if (!word.empty()) {
				wordCount[word]++;
				totalWords++;
				word = L"";
			}
		}
		if (!word.empty()) { // обработка последнего  слова
			wordCount[word]++;
			totalWords++;
		}
	}
	for (auto& item : wordCount) { // проценты
		double freq = static_cast <double> (item.second) / totalWords * 100;
		data.push_back(make_pair(item.first, make_pair(item.second, freq)));
	}
	data.sort([](auto& a, auto& b) { // сортировка по убыванию
		return a.second.first > b.second.first;
		});
}