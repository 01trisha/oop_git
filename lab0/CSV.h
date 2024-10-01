#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <locale>

using namespace std;

class CSV { // записываем data в csv файл
public:

	void writeToFile(string Text1, list<pair<wstring, pair<int, double>>>& data); // берем имя файла и список пар и записываем в в формате csv

};