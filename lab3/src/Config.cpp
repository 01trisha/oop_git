#include "Config.h"

Config::Config(const View& view) : _view(view), _processor(Processor(view)) {
}

void Config::start(bool help) {
	if (help){
		_processor.getHelp();
		return;
	}
	ifstream config(_view.getConfig());
	if (!config.is_open()) {
		cout << "Error: cannot open the file " << _view.getConfig() << endl;
		return;
	}
	if (!_processor.wavCheck(_processor.getInputFile())) {
		return;
	}
	string line;
	while (getline(config, line)) {
		if (line.starts_with("mute ")) {
			muteRead(line);
		} else if (line.starts_with("mix ")) {
			mixRead(line);
		} else if (line.starts_with("reverse ")) {
			reverseRead(line);
		} else if (!line.starts_with("#")) {
			cout << "Error: unknown instruction specified '" << line << "'. To see help use '-h'" << endl;
		}
	}
	saveFiles();
}

Processor Config::getProcessor() {
	return _processor;
}

View Config::getView() {
	return _view;
}

void Config::muteRead(string line) {
	int start = 0, end = 0, i = 5;
	if (!isdigit(static_cast<unsigned char>(line[i]))) {
		cout << "Error: wrong instruction specified '" << line << "'. To see help use '-h'" << endl;
		return;
	}
	while (isdigit(static_cast<unsigned char>(line[i]))) {
		start = start * 10 + line[i] - '0';
		i++;
	}
	if (line[i] != ' ') {
		cout << "Error: wrong instruction specified '" << line << "'. To see help use '-h'" << endl;
		return;
	}
	i++;
	if (!isdigit(static_cast<unsigned char>(line[i]))) {
		cout << "Error: wrong instruction specified '" << line << "'. To see help use '-h'" << endl;
		return;
	}
	while (isdigit(static_cast<unsigned char>(line[i]))) {
		end = end * 10 + line[i] - '0';
		i++;
	}
	muteHandle(start, end);
}

void Config::muteHandle(int start, int end) {
	ifstream InputFile;
	ofstream OutputFile;
	rotateFiles(InputFile, OutputFile);
	ifstream EmptyFile;
	_processor.handle(Mute, InputFile, EmptyFile, OutputFile, start, end);
}

void Config::mixRead(string line) {
	int num = 0, start = 0, end = 0, i = 5;
	if (line[4] == '$' && !isdigit(static_cast<unsigned char>(line[5]))) {
		cout << "Error: wrong instruction specified '" << line << "'. To see help use '-h'" << endl;
		return;
	}
	while (isdigit(static_cast<unsigned char>(line[i]))) {
		num = num * 10 + line[i] - '0';
		i++;
	}
	if (line[i] != ' ') {
		cout << "Error: wrong instruction specified '" << line << "'. To see help use '-h'" << endl;
		return;
	}
	i++;
	if (!isdigit(static_cast<unsigned char>(line[i]))) {
		cout << "Error: wrong instruction specified '" << line << "'. To see help use '-h'" << endl;
		return;
	}
	while (isdigit(static_cast<unsigned char>(line[i]))) {
		start = start * 10 + line[i] - '0';
		i++;
	}
	i++;
	while (isdigit(static_cast<unsigned char>(line[i]))) {
		end = end * 10 + line[i] - '0';
		i++;
	}
	mixHandle(num, start, end);
}

void Config::mixHandle(int num, int start, int end) {
	if ((num == 1) && (_queue == 0)) {
		return;
	}
	ifstream InputFile1, InputFile2;
	ofstream OutputFile;
	rotateFiles(InputFile1, OutputFile);
	string filename;
	if (num == 1) {
		filename = _processor.getInputFile();
	} else {
		filename = _processor.getMixFile(num);
		if (filename.empty()) {
			cout << "Error: no file <input" << num << ".wav>" << endl;
			return;
		}
	}
	if (!_processor.wavCheck(filename)) {
		cout << "Error: wrong wav format of file '" << filename << "'" << endl;
		return;
	}
	InputFile2.open(filename, ios::binary);
	if (!InputFile2.is_open()) {
		cout << "Error: cannot open the file " << filename << endl;
		return;
	}
	_processor.handle(Mix, InputFile1, InputFile2, OutputFile, start, end);
}

void Config::reverseRead(string line) {
	int start = 0, end = 0, i = 8;
	if (!isdigit(static_cast<unsigned char>(line[i]))) {
		cout << "Error: wrong instruction specified '" << line << "'. To see help use '-h'" << endl;
		return;
	}
	while (isdigit(static_cast<unsigned char>(line[i]))) {
		start = start * 10 + line[i] - '0';
		i++;
	}
	i++;
	while (isdigit(static_cast<unsigned char>(line[i]))) {
		end = end * 10 + line[i] - '0';
		i++;
	}
	reverse 	Handle(start, end);
}

void Config::reverseHandle(int start, int end) {
	ifstream inputFile;
	ofstream outputFile;
	rotateFiles(inputFile, outputFile);
	ifstream emptyFile;
	_processor.handle(Reverse, inputFile, emptyFile, outputFile, start, end);
}

void Config::rotateFiles(ifstream& inputFile, ofstream& outputFile) {
	if (_queue == Even) {
		inputFile.open(_evenFilename, ios::binary);
		outputFile.open(_oddFilename, ios::binary);
		_queue = Odd;
	} else {
		inputFile.open(_queue == Odd
			? _oddFilename
			: _processor.getInputFile(), ios::binary);
		outputFile.open(_evenFilename, ios::binary);
		_queue = Even;
	}
}

void Config::saveFiles() {
	remove(_processor.getOutputFile().c_str());
	if (_queue == Odd) {
		rename(_oddFilename, _processor.getOutputFile().c_str());
	} else if (_queue == Even) {
		rename(_evenFilename, _processor.getOutputFile().c_str());
	} else {
		ifstream InputFile(_processor.getInputFile(), ios::binary);
		ofstream OutputFile(_processor.getOutputFile());
		OutputFile << InputFile.rdbuf();
	}
	remove(_oddFilename);
	remove(_evenFilename);
}
