#ifndef _INPUTREADER_H_

#define _INPUTREADER_H_

#include <fstream>
#include <iostream>
#include <list>
#include <string>

#define EXIT_FAILURE 1

using namespace std;

class InputReader {
private:
  string inputFileName;
  wifstream inputFile;

public:
  list<wstring> words;

  InputReader(string fileName);

  void OpenInputFile();
  void GetWordsFromFile();
  void CloseInputFile();
};

#endif // _INPUTREADER_H_
