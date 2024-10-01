#include "TextFile.h"


TextFile::TextFile(std::string file) {
	Text = file;
}

std::list<std::wstring> TextFile::readText() { // берем имя файла и возвращаем список строк из него

	std::wifstream file(Text);
	file.imbue(std::locale(""));

	std::list<std::wstring> words;
	std::wstring line;
	while (std::getline(file, line)) {
		words.push_back(line);
	}
	file.close();
	return words;
} 