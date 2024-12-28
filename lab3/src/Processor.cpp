#include "Processor.h"
#include "MuteConverter.h"
#include "MixConverter.h"
#include "ReverseConverter.h"

Processor::Processor::Processor() = default;


//инициализация процессора, добавление конвертеров в контейнер
Processor::Processor(View view) {
	_factory.add<MuteConverter>(ToolType::MUTE);
	_factory.add<MixConverter>(ToolType::MIX);
	_factory.add<ReverseConverter>(ToolType::REVERSE);
	//добавляем обьект конвентера в контейнер
	_converters.push_back(_factory.get(ToolType::MUTE)());
	_converters.push_back(_factory.get(ToolType::MIX)());
	_converters.push_back(_factory.get(ToolType::REVERSE)());
	//получаем параметры из view
	_outputFile = view.getOutputFile();
	_inputFile = view.getInputFile();
	_inputFiles = view.getInputFiles();
}

string Processor::getOutputFile() {
	return _outputFile;
}

string Processor::Processor::getInputFile() {
	return _inputFile;
}

vector<string> Processor::getInputFiles(){
	return _inputFiles;
}

//проверяем соответствует ли wav файл заданым нашим параметрам 
bool Processor::wavCheck(const string& filename) const {
	ifstream file(filename, ios::binary);
	WAV_HEADER data;
	file.read(reinterpret_cast<char*>(&data), sizeof(WAV_HEADER));
	if ((data.audioFormat != _audioFormat) || (data.numOfChannels != _numOfChannels) || (data.samplesPedSec != _samplesPedSec) || (data.bitsPerSample != _bitsPerSample)) {
		return false;
	}
	return true;
}


// void Processor::wavWriter(const string& InputFile, const string& OutputFile) {
// 	ifstream inputFile(InputFile, ios::binary);
// 	ofstream outputFile(OutputFile, ios::binary);
// 	WAV_HEADER header;
// 	inputFile.read(reinterpret_cast<char*>(&header), sizeof(header));
// 	outputFile.write(reinterpret_cast<const char*>(&header), sizeof(header));
// }

// size_t getOffset(const std::string& inputFile) {
//     std::ifstream file(inputFile, std::ios::binary);
//     if (!file.is_open()) {
//         throw std::runtime_error("Не удалось открыть файл.");
//     }
//     // Считать заголовок WAV
//     WAV_HEADER header;
//     file.read(reinterpret_cast<char*>(&header), sizeof(WAV_HEADER));

//     // Проверить идентификатор RIFF
//     if (std::string(reinterpret_cast<char*>(header.chunkID), 4) != "RIFF" ||
//         std::string(reinterpret_cast<char*>(header.format), 4) != "WAVE") {
//         throw std::runtime_error("Файл не является WAV.");
//     }
//     // Определить смещение аудиоданных
//     size_t offset = sizeof(WAV_HEADER);
//     // Если есть дополнительные данные, учесть их
//     size_t actualChunkSize = header.chunkSize + 8; // chunkSize включает всё после поля "chunkID" (всего 8 байт на chunkID и chunkSize)
//     if (actualChunkSize > offset) {
//         offset += (actualChunkSize - offset);
//     }
//     return offset;
// }

//проверка поддерживается ли переданный type обработки для каждого конвентера 
void Processor::handle(ToolType type, ifstream& input, ofstream& output, Processor::ListOfData context, Processor::ListOfData inputFiles) { 
	for (auto & converter : _converters) {
		if (converter->support(type)) {
			converter->convert(context,input, output, inputFiles);
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
//для присваивания оного обьекта класса Processor другому 
Processor& Processor::operator=(const Processor& other) {
	if (this != &other) {
		_inputFile = other._inputFile;
		_outputFile = other._outputFile;
		_inputFiles = other._inputFiles;
	}
	return *this;
}
