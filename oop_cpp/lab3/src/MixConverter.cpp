#include "MixConverter.h"
#include <stdexcept>
void MixConverter::convert(MixConverter::ConventerContext _context, ifstream& input, ofstream& output, MixConverter::ConventerContext inputFiles) {
	WAV_HEADER header;
	input.read(reinterpret_cast<char*>(&header), sizeof(header));
	output.write(reinterpret_cast<const char*>(&header), sizeof(header));
	int second = 0, sample = 0;
	int16_t data1, data2, data;
	//цикд до нашего start
	//ищем в _context ключ mute
	int num = 0, start = 0, end = 0;
	if (_context.size() < 3) {
		throw std::invalid_argument("Error: invalid arguments format: '" + _context[0] + " " + _context[1] + " " + _context[2] + "' . To see help use '-h'");
	}
	if (_context.size() > 3){
		throw std::invalid_argument("Error: too many arguments: 'mix " + _context[0] + _context[1] + _context[2] + _context[3] + "' . To see help use '-h'");
	}

	// Check and convert num
	if (_context[0].size() < 2 || _context[0][0] != '$' || !isdigit(static_cast<unsigned char>(_context[0][1]))) {
		throw std::invalid_argument("Error: invalid num format: '" + _context[0] + "' . To see help use '-h'");
	}
	num = stoi(_context[0].substr(1));

	// Check and convert start
	if (!isdigit(static_cast<unsigned char>(_context[1][0]))) {
		throw std::invalid_argument("Error: invalid start format: '" + _context[1] + "' . To see help use '-h'");
	}
	start = stoi(_context[1]);

	// Check and convert end
	if (!isdigit(static_cast<unsigned char>(_context[2][0]))) {
		throw std::invalid_argument("Error: invalid end format: '" + _context[2] + "' . To see help use '-h'");
	}
	end = stoi(_context[2]);

	string filename = inputFiles[num-2];
	
	ifstream input2;
	//открываем файл с которым будем делать mix
	input2.open(filename, ios::binary);
	if (!input2.is_open()) {
		throw std::ios_base::failure("Error: cannot open the file " + filename);
	}
	while (second < start && input.read(reinterpret_cast<char*>(&data1), sizeof(data1))) {
		output.write(reinterpret_cast<const char*>(&data1), sizeof(data1));
		sample++;
		//обработана вся секунда
		if (sample == _sampleRate) {
			sample = 0;
			second++;
		}
	}
	//цикл пока не достигнут end или конец файла 
	while ((end == 0 || second < end) && input.read(reinterpret_cast<char*>(&data1), sizeof(data1)) && input2.read(reinterpret_cast<char*>(&data2), sizeof(data2))) {
		//наш семпл = среднеарифметическому между двумя семплами
		data = (data1 + data2) / 2;
		//записываем его
		output.write(reinterpret_cast<const char*>(&data), sizeof(data));
		sample++;
		//обработана вся секунда
		if (sample == _sampleRate) {
			sample = 0;
			second++;
		}
	}
	//дозаписываем файл
	while (input.read(reinterpret_cast<char*>(&data1), sizeof(data1))) {
		output.write(reinterpret_cast<const char *>(&data1), sizeof(data1));
	}
	cout << "Done: mix" << endl;
	input2.close();
}


bool MixConverter::support(ToolType type) {
	return type == ToolType::MIX;
}

void MixConverter::getInfo() {
	cout
		<< "[MixConverter]" << endl
		<< "- Instruction usage: mix $N <start>[ <end>]" << endl
		<< "- where <start> and <end> in seconds, N is a number of input file, [] - optional" << endl;
}
