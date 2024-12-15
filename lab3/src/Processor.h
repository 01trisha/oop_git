#pragma once
#include <vector>
#include "View.h"
#include "Const.h"
#include "Factory.h"
#include "Converter.h"

class Converter;

class Processor
{
public:
	Processor();
	Processor(View);
	void handle(ToolType, ifstream& input1, ifstream& input2, ofstream& output, int start, int end);
	void getHelp();
	string getOutputFile();
	string getInputFile();
	string getMixFile(int num);
	bool wavCheck(const string& filename) const;
	Processor& operator=(const Processor& other);

private:
	string _outputFile;
	string _inputFile;
	vector<string> _mixFiles;
	Factory<ToolType, Converter> _factory;
	vector<Converter*> _converters;

	const int _audioFormat = 1;
	const int _numOfChannels = 1;
	const int _samplesPedSec = 44100;
	const int _bitsPerSample = 16;
};
