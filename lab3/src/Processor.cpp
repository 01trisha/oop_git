#include "Processor.h"
#include "MuteConverter.h"
#include "MixConverter.h"
#include "ReverseConverter.h"

Processor::Processor::Processor() = default;

Processor::Processor(View view) {
	_factory.add<MuteConverter>(Mute);
	_factory.add<MixConverter>(Mix);
	_factory.add<ReverseConverter>(Reverse);
	_converters.push_back(_factory.get(Mute)());
	_converters.push_back(_factory.get(Mix)());
	_converters.push_back(_factory.get(Reverse)());

	_outputFile = view.getOutputFile();
	_inputFile = view.getInputFile();
	_mixFiles = view.getMixFiles();
}

string Processor::getOutputFile() {
	return _outputFile;
}

string Processor::Processor::getInputFile() {
	return _inputFile;
}

string Processor::getMixFile(int num) {
	if (num - 1 <= _mixFiles.size()) {
		return _mixFiles[num - 2];
	}
	return "";
}

bool Processor::wavCheck(const string& filename) const {
	ifstream file(filename, ios::binary);
	WAV_HEADER data;
	file.read(reinterpret_cast<char*>(&data), sizeof(WAV_HEADER));
	if ((data.audioFormat != _audioFormat)
	|| (data.numOfChannels != _numOfChannels)
	|| (data.samplesPedSec != _samplesPedSec)
	|| (data.bitsPerSample != _bitsPerSample)) {
		return false;
	}
	return true;
}

void Processor::handle(ToolType type, ifstream& input1, ifstream& input2, ofstream& output, int start, int end) {
	for (auto & converter : _converters) {
		if (converter->support(type)) {
			converter->convert(input1, input2, output, start, end);
			break;
		}
	}
}

void Processor::getHelp() {
	cout
		<< "Usage of program arguments:" << endl
		<< "- '-c <config.txt> <output.wav> <input1.wav>[ <input2.wav> ...]'" << endl
		<< "- where <config.txt> contain the list of converter instructions, [] - optional" << endl;
	for (auto & converter : _converters) {
		converter->getInfo();
	}
	cout << "To see this help use '-h'" << endl;
}

Processor& Processor::operator=(const Processor& other) {
	if (this != &other) {
		_inputFile = other._inputFile;
		_outputFile = other._outputFile;
		_mixFiles = other._mixFiles;
	}
	return *this;
}
