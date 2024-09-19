#ifndef _OUTPUTWRITER_H_

#define _OUTPUTWRITER_H_

#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <locale>

using namespace std;


class OutputWriter
{
private:

	string outputFileName;
	wofstream outputFile;
	list<wstring> words;
	list<pair<wstring, int>> sortedWords;

public:

	OutputWriter(string fileName, list<wstring> wordList, list<pair<wstring, int>> sortedList);

	void CreateOutputFile();
	void PrintAnswer();
	void CloseOutputFile();
};

#endif // _OUTPUTWRITER_H_