#include "Handler.h"

Handler::Handler(list<wstring> wordList) { words = wordList; }

// Word frequency counting
void Handler::GetWordFrequency() {
  for (const wstring &word : words)
    wordCount[word]++;
}

// Sort words by descending frequency
void Handler::MakeSortedList() {
  list<pair<wstring, int>> sortedList(wordCount.begin(), wordCount.end());
  sortedList.sort(
      [](const auto &a, const auto &b) { return a.second > b.second; });

  sortedWords = sortedList;
}
