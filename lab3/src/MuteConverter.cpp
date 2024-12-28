#include "MuteConverter.h"
#include<stdexcept>
void MuteConverter::convert(ConventerContext _context, ifstream& input, ofstream& output, MuteConverter::ConventerContext inputFiles) {
	WAV_HEADER header;
	input.read(reinterpret_cast<char*>(&header), sizeof(header));
	output.write(reinterpret_cast<const char*>(&header), sizeof(header));
	int second = 0, sample = 0;
	const int16_t muted = 0;
	int16_t data;
	int start = 0; end = 0;
	
	if (_context.size() < 2){
		throw std::invalid_argument("Error: invalid arguments format: '" + _context[0] + " " + _context[1] + "' . To see help use '-h'");
	}
	if (_context.size() > 2){
		throw	std::invalid_argument("Error: too many arguments: 'mute " + _context[0] + " " + _context[1] + " " + _context[2] + "'. To see help use '-h'");
	}
	if (!isdigit(static_cast<unsigned char>(_context[0][0]))) {
		throw std::invalid_argument("Error: invalid start format: '" + _context[0] + "' . To see help use '-h'");
	}
	start = stoi(_context[0]);

	if (!isdigit(static_cast<unsigned char>(_context[1][0]))) {
		throw std::invalid_argument("Error: invalid start format: '" + _context[1] + "' . To see help use '-h'");
	}
	end = stoi(_context[1]);

	//цикл до нашего start
	while (second < start && input.read(reinterpret_cast<char*>(&data), sizeof(data))) {
		output.write(reinterpret_cast<const char*>(&data), sizeof(data));
		sample++;
		//обработана вся секунда
		if (sample == _sampleRate) {
			sample = 0;
			second++;
		}
	}
	//цикл до нашего end
	while (second < end && input.read(reinterpret_cast<char*>(&data), sizeof(data))) {
		//переписываем с data на muted
		output.write(reinterpret_cast<const char*>(&muted), sizeof(muted));
		sample++;
		//обработана вся секунда
		if (sample == _sampleRate) {
			sample = 0;
			second++;
		}
	}
	//дописываем оставшееся в файле 
	while (input.read(reinterpret_cast<char*>(&data), sizeof(data))) {
		output.write(reinterpret_cast<const char*>(&data), sizeof(data));
	}
	cout << "Done: mute" << endl;
}

bool MuteConverter::support(ToolType type) {
	return type == ToolType::MUTE;
}

void MuteConverter::getInfo() {
	cout
		<< "[MuteConverter]" << endl
		<< "- Instruction usage: mute <start> <end>" << endl
		<< "- where <start> and <end> in seconds" << endl;
}
