#ifndef _HANDLER_H_

#define _HANDLER_H_

#include <map>
#include <list>
#include <string>

using namespace std;


class Handler
{
private:

	map<wstring, int> wordCount;

public:

	list<wstring> words;
	list<pair<wstring, int>> sortedWords;

	Handler(list<wstring> wordList);

	void GetWordFrequency();
	void MakeSortedList();
};

#endif // _HANDLER_H_