#pragma once
#include <iostream>
#include <fstream>
#include "Processor.h"
#include "Const.h"

using namespace std;

class Converter {
public:
	typedef vector<string> ConventerContext;
	virtual ~Converter() = default;
	virtual bool support(ToolType) = 0;
	virtual void convert(ConventerContext _context, ifstream& input, ofstream& output, ConventerContext inputFiles) = 0;
	virtual void getInfo() = 0;

protected:
	const int _sampleRate = 44100;
};
