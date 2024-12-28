#pragma once
#include "Const.h"
#include "Converter.h"
#include "Factory.h"
#include "View.h"
#include <vector>

class Converter;

class Processor {
public:
  Processor();
  Processor(View);
  typedef vector<pair<string, vector<string>>> ConventerContext;
  typedef vector<string> ListOfData;
  void handle(ToolType, ifstream &input1, ofstream &output, ListOfData _context, ListOfData _inputFiles);
  void getHelp();
  string getOutputFile();
  string getInputFile();
  ListOfData getInputFiles();
  bool wavCheck(const string &filename) const;
  Processor &operator=(const Processor &other);

private:
  string _outputFile;
  string _inputFile;
  vector<string> _inputFiles;
  Factory<ToolType, Converter> _factory;
  vector<Converter *> _converters;
  const int _audioFormat = 1;
  const int _numOfChannels = 1;
  const int _samplesPedSec = 44100;
  const int _bitsPerSample = 16;
};
