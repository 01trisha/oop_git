#include "ReverseConverter.h"
#include <stdexcept>
void ReverseConverter::convert(ConventerContext _context, ifstream& input, ofstream& output, ReverseConverter::ConventerContext inputFiles) {
	WAV_HEADER header;
	input.read(reinterpret_cast<char*>(&header), sizeof(header));
	output.write(reinterpret_cast<const char*>(&header), sizeof(header));
	int second = 0, sample = 0;
	int16_t data;
	//для хранения семплов
	vector<int16_t> buffer;

	int start = 0; end = 0;
	if (_context.size() < 2){
		throw std::invalid_argument("Error: invalid arguments format: '" + _context[0] + " " + _context[1] + "' . To see help use '-h'");
		return;
	}
	if (_context.size() > 2){
		throw	std::invalid_argument("Error: too many arguments: 'reverse " + _context[0] + " " +  _context[1] + " " + _context[2] + "' . To see help use '-h'");
	}
	if (!isdigit(static_cast<unsigned char>(_context[0][0]))) {
		throw std::invalid_argument("Error: invalid start format: '" + _context[0] + "' . To see help use '-h'");
	}
	start = stoi(_context[0]);

	if (!isdigit(static_cast<unsigned char>(_context[1][0]))) {
		throw std::invalid_argument("Error: invalid start format: '" + _context[1] + "' . To see help use '-h'");
		return;
	}
	end = stoi(_context[1]);

	//цикл до нашего start
	while (second < start && input.read(reinterpret_cast<char*>(&data), sizeof(data))) {
		output.write(reinterpret_cast<const char*>(&data), sizeof(data));
		sample++;
		//обработана вся секунда(_sampleRate = 1 секунде)
		if (sample == _sampleRate) {
			sample = 0;
			second++;
		}
	}
	//цикл пока не достигнут end или конец файла
	while ((end == 0 || second < end) && input.read(reinterpret_cast<char*>(&data), sizeof(data))) {
		buffer.emplace_back(data);
		sample++;
		//обработана вся секунда
		if (sample == _sampleRate) {
			sample = 0;
			second++;
		}
	}
	//записали тогда до нашего старт, щас записываем весь буфер в обратном порядке покане закончится
	while (!buffer.empty()) {
		data = buffer.back();
		output.write(reinterpret_cast<const char*>(&data), sizeof(data));
		buffer.pop_back();
	}
	//дочитываем файл до конца
	while (input.read(reinterpret_cast<char*>(&data), sizeof(data))) {
		output.write(reinterpret_cast<const char*>(&data), sizeof(data));
	}
	cout << "Done: reverse" << endl;
}

bool ReverseConverter::support(ToolType type) {
	return type == ToolType::REVERSE;
}

void ReverseConverter::getInfo() {
	cout
		<< "[ReverseConverter]" << endl
		<< "- Instruction usage: reverse <start>[ <end>]" << endl
		<< "- where <start> and <end> in seconds, [] - optional" << endl;
}

