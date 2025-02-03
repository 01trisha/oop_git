#pragma once
#include "Processor.h"
#include "View.h"
#include "Context.h"

using namespace std;

enum QueueType {
	Even = 1,
	Odd,
};


class Config
{
public:
	Config(const View& view);
	void start(bool help);
	Processor getProcessor();
	View getView();

private:

	void rotateFiles(ifstream& inputFile, ofstream& outputFile);
	void saveFiles();
	typedef vector<pair<string, vector<string>>> ConventerContext;
	ConventerContext _contextData;
	typedef vector<string> ListOfFiles;
	ListOfFiles _inputFiles;
	
	Processor _processor;
	View _view;
	Context _context;
	const char* _evenFilename = "__even_temp_buffer.wav";
	const char* _oddFilename = "__odd_temp_buffer.wav";
	int _queue = 0;
};
