#include "MixConverter.h"

void MixConverter::convert(ifstream& inputFile1, ifstream& inputFile2, ofstream& outputFile, int start, int end) {
	WAV_HEADER header;
	inputFile1.read(reinterpret_cast<char*>(&header), sizeof(header));
	outputFile.write(reinterpret_cast<const char*>(&header), sizeof(header));
	int second = 0, sample = 0;
	int16_t data1, data2, data;

	while (second < start && inputFile1.read(reinterpret_cast<char*>(&data1), sizeof(data1))) {
		outputFile.write(reinterpret_cast<const char*>(&data1), sizeof(data1));
		sample++;
		if (sample == _sampleRate) {
			sample = 0;
			second++;
		}
	}
	while ((end == 0 || second < end) && inputFile1.read(reinterpret_cast<char*>(&data1), sizeof(data1)) && inputFile2.read(reinterpret_cast<char*>(&data2), sizeof(data2))) {
		data = (data1 + data2) / 2;
		outputFile.write(reinterpret_cast<const char*>(&data), sizeof(data));
		sample++;
		if (sample == _sampleRate) {
			sample = 0;
			second++;
		}
	}
	while (inputFile1.read(reinterpret_cast<char*>(&data1), sizeof(data1))) {
		outputFile.write(reinterpret_cast<const char *>(&data1), sizeof(data1));
	}
	cout << "Done: mix" << endl;
}

bool MixConverter::support(ToolType type) {
	return type == Mix;
}

void MixConverter::getInfo() {
	cout
		<< "[MixConverter]" << endl
		<< "- Instruction usage: mix $N <start>[ <end>]" << endl
		<< "- where <start> and <end> in seconds, N is a number of input file, [] - optional" << endl;
}
