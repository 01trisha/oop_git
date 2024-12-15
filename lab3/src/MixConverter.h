#pragma once
#include "Converter.h"

class MixConverter : public Converter {
public:
	bool support(ToolType) override;
	void convert(ifstream& input1, ifstream& input2, ofstream& output, int start, int end) override;
	void getInfo() override;
};
