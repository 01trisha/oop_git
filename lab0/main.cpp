#include <iostream>
#include <locale>

#include "Handler.h"
#include "InputReader.h"
#include "OutputWriter.h"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define CORRECT_ARGUMENTS_COUNT 3

using namespace std;

int main(int argc, char **argv) {
  setlocale(LC_ALL, "Russian");

  if (argc != CORRECT_ARGUMENTS_COUNT) {
    cout << "Use in console: word_counter input.txt output.csv" << endl;
    return EXIT_FAILURE;
  }

  InputReader input(argv[1]);
  input.OpenInputFile();
  input.GetWordsFromFile();

  Handler wordCounter(input.words);
  wordCounter.GetWordFrequency();
  wordCounter.MakeSortedList();

  OutputWriter output(argv[2], wordCounter.words, wordCounter.sortedWords);
  output.CreateOutputFile();
  output.PrintAnswer();

  input.CloseInputFile();
  output.CloseOutputFile();

  return EXIT_SUCCESS;
}
