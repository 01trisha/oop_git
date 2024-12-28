#pragma once
#include "Converter.h"

class MuteConverter : public Converter {
private:
	int start;
	int end;
	ofstream output;
	ifstream input;

public:
	typedef vector<string> ConventerContext;
	virtual ~MuteConverter() = default;
	bool support(ToolType) override;
	void convert(ConventerContext _context, ifstream& input, ofstream& output, ConventerContext inputFiles) override;
	void getInfo() override;
};
