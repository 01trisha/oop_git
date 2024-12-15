#pragma once
#include "Processor.h"
#include "View.h"

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
	void muteRead(string line);
	void muteHandle(int start, int end);
	void mixRead(string line);
	void mixHandle(int num, int start, int end);
	void reverseRead(string line);
	void reverseHandle(int start, int end);
	void rotateFiles(ifstream& inputFile, ofstream& outputFile);
	void saveFiles();

	Processor _processor;
	View _view;
	const char* _evenFilename = "__even_temp_buffer.wav";
	const char* _oddFilename = "__odd_temp_buffer.wav";
	int _queue = 0;
};
