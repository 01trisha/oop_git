#pragma once
#include <iostream>
#include <fstream>
#include "Processor.h"
#include "Const.h"

using namespace std;

class Converter {
public:
	virtual ~Converter() = default;
	virtual bool support(ToolType) = 0;
	virtual void convert(ifstream& input1, ifstream& input2, ofstream& output, int start, int end) = 0;
	virtual void getInfo() = 0;

protected:
	const int _sampleRate = 44100;
};
