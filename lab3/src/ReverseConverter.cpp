#include "ReverseConverter.h"

void ReverseConverter::convert(ifstream& inputFile1, ifstream& inputFile2, ofstream& outputFile, int start, int end) {
	WAV_HEADER header;
	inputFile1.read(reinterpret_cast<char*>(&header), sizeof(header));
	outputFile.write(reinterpret_cast<const char*>(&header), sizeof(header));
	int second = 0, sample = 0;
	int16_t data;
	vector<int16_t> buffer;

	while (second < start && inputFile1.read(reinterpret_cast<char*>(&data), sizeof(data))) {
		outputFile.write(reinterpret_cast<const char*>(&data), sizeof(data));
		sample++;
		if (sample == _sampleRate) {
			sample = 0;
			second++;
		}
	}
	while ((end == 0 || second < end) && inputFile1.read(reinterpret_cast<char*>(&data), sizeof(data))) {
		buffer.emplace_back(data);
		sample++;
		if (sample == _sampleRate) {
			sample = 0;
			second++;
		}
	}
	while (!buffer.empty()) {
		data = buffer.back();
		outputFile.write(reinterpret_cast<const char*>(&data), sizeof(data));
		buffer.pop_back();
	}
	while (inputFile1.read(reinterpret_cast<char*>(&data), sizeof(data))) {
		outputFile.write(reinterpret_cast<const char*>(&data), sizeof(data));
	}
	cout << "Done: reverse" << endl;
}

bool ReverseConverter::support(ToolType type) {
	return type == Reverse;
}

void ReverseConverter::getInfo() {
	cout
		<< "[ReverseConverter]" << endl
		<< "- Instruction usage: reverse <start>[ <end>]" << endl
		<< "- where <start> and <end> in seconds, [] - optional" << endl;
}

