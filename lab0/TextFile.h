#pragma once

#include <string>
#include <list>
#include <fstream>
#include <locale>

class TextFile { // для чтения текстового файла
private:
	std::string Text;

public:

	TextFile(std::string file);
	std::list<std::wstring> readText(); // берем имя файла и возвращаем список строк из него

};