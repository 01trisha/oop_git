#include "InputReader.h"

InputReader::InputReader(string fileName) { inputFileName = fileName; }

void InputReader::OpenInputFile() {
  inputFile.open(inputFileName);

  if (!inputFile.is_open()) {
    cout << "Failed to open file: " << inputFileName << endl;
    exit(EXIT_FAILURE);
  }
}

void InputReader::GetWordsFromFile() {
  // Setting the locale to handle Unicode correctly (UTF-8)
  inputFile.imbue(locale(""));

  // Split a string into words, eliminating special characters
  // (case insensitive)
  wstring str, curWord;
  while (getline(inputFile, str)) {
    for (int i = 0; i < str.length(); i++) {
      if (iswalnum(str[i]))
        curWord += towlower(str[i]);
      else if (!curWord.empty()) {
        words.push_back(curWord);
        curWord.clear();
      }
    }
    if (!curWord.empty())
      words.push_back(curWord);
  }
}

void InputReader::CloseInputFile() { inputFile.close(); }
