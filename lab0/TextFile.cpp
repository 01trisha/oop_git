#include "TextFile.h"

//чтение
TextFile::TextFile(std::string file) {
	Text = file; //сохраняем имя файла
}

std::list<std::wstring> TextFile::readText() { // берем имя файла и возвращаем список строк из него

	std::wifstream file(Text);
	file.imbue(std::locale("")); // чтоб с русским работало

	std::list<std::wstring> words; // создаем массив для слов
	std::wstring line;
	while (std::getline(file, line)) {
		words.push_back(line); //записываем слова в массив (список)
	}
	file.close();
	return words;
} 