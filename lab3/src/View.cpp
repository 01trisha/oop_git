#include "View.h"

View::View(int argc, char** argv) {

	if (argc == 1) {
		_help = false;
		return;
	}
	if (strcmp(argv[1], "-h") == 0) {
		_help = true;
		return;
	}
	else{
		_help = false;
	}
	if (strcmp(argv[1], "-c") != 0) {
		cout << "Error: wrong program arguments. To see help use '-h'" << endl;
		return;
	}
	if (string(argv[2]).ends_with(".txt")) {
		_config = argv[2];
	} else {
		cout << "Error: config file is not .txt" << endl;
		return;
	}
	if (string(argv[3]).ends_with(".wav")) {
		_outputFile = argv[3];
	} else {
		cout << "Error: output file is not .wav" << endl;
		return;
	}
	if (string(argv[4]).ends_with(".wav")) {
		_inputFile = argv[4];
	} else {
		cout << "Error: input1 file is not .wav" << endl;
		return;
	}
	for (int i = 5; i < argc; i++) {
		string arg = argv[i];
		if (arg.ends_with(".wav")) {
			_mixFiles.emplace_back(arg);
		} else {
			cout << "Error: input" << (i - 3) << " file is not .wav" << endl;
			_config = nullptr;
			return;
		}
	}
	
}

bool View::start() {
	if (_help) {
		return true;
	}
	if (!_config.empty() && !_outputFile.empty() && !_inputFile.empty()) {
		return true;
	}
	cout << "Error: wrong program arguments. To see help use '-h'" << endl;
	return false;
}

bool View::help() const {
	return _help;
}

string View::getOutputFile() {
	return _outputFile;
}

string View::getInputFile() {
	return _inputFile;
}

vector<string> View::getMixFiles() {
	return _mixFiles;
}

string View::getConfig() {
	return _config;
}
