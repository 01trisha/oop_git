#include "Config.h"
#include <stdexcept>

Config::Config(const View& view) : _view(view), _processor(Processor(view)) {}

//
void Config::start(bool help) {
	if (help){
		//печатаем -h и завершаем
		_processor.getHelp();
		return;
	}
	//проверяем правильный ли wav file 
	if (!_processor.wavCheck(_processor.getInputFile())) {
		throw std::invalid_argument("Error: wrong wav format of file '" + _processor.getInputFile() + "'");
	}

    _inputFiles = _view.getInputFiles();

	if(!(_context.ParseConfig(_view.getConfig()))) {
		throw std::ios_base::failure("Error: cannot open the file " + _view.getConfig());
	};
	_contextData = _context.getContext();

	for (auto& it : _contextData) {
		ifstream InputFile;
		ofstream OutputFile;
		rotateFiles(InputFile, OutputFile);
		string& commandName = it.first;
		ToolType toolType = toolTypeMap.at(commandName);
		_processor.handle(toolType, InputFile, OutputFile, it.second, _inputFiles);
	}
	
	saveFiles();
}

Processor Config::getProcessor() {
	return _processor;
}

View Config::getView() {
	return _view;
}


void Config::rotateFiles(ifstream& inputFile, ofstream& outputFile) {
    if (_queue == Even) {
        inputFile.open(_evenFilename, ios::binary);
        outputFile.open(_oddFilename, ios::binary);
        _queue = Odd;
    } else {
        inputFile.open(_queue == Odd ? _oddFilename : _processor.getInputFile(), ios::binary);
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
        ifstream inputFile(_processor.getInputFile(), ios::binary);
        ofstream outputFile(_processor.getOutputFile(), ios::binary);
        outputFile << inputFile.rdbuf();
    }

    remove(_oddFilename);
    remove(_evenFilename);
}


