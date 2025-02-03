#pragma once
#include "Converter.h"

class MixConverter : public Converter {
private:
	int start;
	int end;
	int num;
	ofstream output;
	ifstream input;

public:
	typedef vector<string> ConventerContext;
	~MixConverter() = default;
	bool support(ToolType) override;
	void convert(ConventerContext _context, ifstream& input, ofstream& output, ConventerContext inputFiles) override;
	void getInfo() override;
};
