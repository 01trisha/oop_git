#include "Context.h"
#include <sstream>
#include <algorithm>
#include <iterator>

bool Context::ParseConfig(const string &filename) {
    ifstream config(filename);
    if (!config.is_open()) {
        return false; // Ошибка открытия файла
    }

    string line;
    while (getline(config, line)) {
        // Удаляем начальные и конечные пробелы
        line.erase(line.begin(), find_if(line.begin(), line.end(), [](unsigned char ch) { return !isspace(ch); }));
        line.erase(find_if(line.rbegin(), line.rend(), [](unsigned char ch) { return !isspace(ch); }).base(), line.end());

        // Пропускаем пустые строки и комментарии
        if (line.empty() || line[0] == '#') continue;

        // Разделяем строку на команду и аргументы
        stringstream ss(line);
        string command;
        ss >> command; // Первая часть — это команда

        // Считываем оставшиеся аргументы
        vector<string> arguments;
        string argument;
        while (ss >> argument) {
            arguments.push_back(argument);
        }

        // Добавляем новую запись в _context
        _context.emplace_back(command, arguments);
    }

    config.close();
    return true;
}

Context::ConverterContext Context::getContext() {
    return _context;
}