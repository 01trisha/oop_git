#include "MuteConverter.h"

void MuteConverter::convert(ifstream& inputFile1, ifstream& inputFile2, ofstream& outputFile, int start, int end) {
	WAV_HEADER header;
	inputFile1.read(reinterpret_cast<char*>(&header), sizeof(header));
	outputFile.write(reinterpret_cast<const char*>(&header), sizeof(header));
	int second = 0, sample = 0;
	const int16_t muted = 0;
	int16_t data;

	while (second < start && inputFile1.read(reinterpret_cast<char*>(&data), sizeof(data))) {
		outputFile.write(reinterpret_cast<const char*>(&data), sizeof(data));
		sample++;
		if (sample == _sampleRate) {
			sample = 0;
			second++;
		}
	}
	while (second < end && inputFile1.read(reinterpret_cast<char*>(&data), sizeof(data))) {
		outputFile.write(reinterpret_cast<const char*>(&muted), sizeof(muted));
		sample++;
		if (sample == _sampleRate) {
			sample = 0;
			second++;
		}
	}
	while (inputFile1.read(reinterpret_cast<char*>(&data), sizeof(data))) {
		outputFile.write(reinterpret_cast<const char*>(&data), sizeof(data));
	}
	cout << "Done: mute" << endl;
}

bool MuteConverter::support(ToolType type) {
	return type == Mute;
}

void MuteConverter::getInfo() {
	cout
		<< "[MuteConverter]" << endl
		<< "- Instruction usage: mute <start> <end>" << endl
		<< "- where <start> and <end> in seconds" << endl;
}
