#include <span>
#include <iostream>
#include "game.h"
#include "importer.h"
#include "dumper.h"

GameOfLife::GameOfLife(char** argv, int argc) {
	//установлена начальные итерации или нет
	bool iterationsSet = false;
	//следующее значение - путь к файлу вывода
	bool nextExportDestination = false;
	//следующее значение - начальное кол-во итераций
	bool nextStartIteration = false;
	for (std::string arg : std::span(argv+1, argc-1)) {
		//если -o то говорим что следующий арг это путь к output
		if (arg == "-o") {
			if (_exportDestination.has_value()) {
				throw std::invalid_argument("Error: Specify just one output file\n");
			}
			nextExportDestination = true;
		//если --output то с 9 элемента считываем путь
		} else if (arg.starts_with("--output=")) {
			if (_exportDestination.has_value()) {
				throw std::invalid_argument("Error: Specify just one output file\n");
			}
			_exportDestination = std::filesystem::path(arg.substr(9));
		//если -i ир говорим что некст арг - начальная итерация
		} else if (arg == "-i") {
			if (iterationsSet) {
				throw std::invalid_argument("Error: Specify _iterations once.\n");
			}
			nextStartIteration = true;
		//если --iterations то преобразовываем с 13 символа с число аргумент
		} else if (arg.starts_with("--iterations=")) {
			if (iterationsSet) {
				throw std::invalid_argument("Error: Specify _iterations once.\n");
			}
			//int(str)
			_startIteration = std::strtol(arg.substr(13).c_str(), nullptr, 10);
			iterationsSet = true;
		} else if (nextExportDestination) {
			nextExportDestination = false;
			_exportDestination = std::filesystem::path(arg);
		} else if (nextStartIteration) {
			nextStartIteration = false;
			iterationsSet = true;
			_startIteration = std::strtol(arg.c_str(), nullptr, 10);
		} else {
			if (_importSource.has_value()) {
				throw std::invalid_argument("Error: Specify just one input file.\n");
			}
			//записываем путь инпут файла(текущий аргумент)
			_importSource = std::filesystem::path(arg);
		}
	}
}

//ссылка на внешний обьект
void GameOfLife::setView(View* view) {
	_view = view;
}
//запуск игры
void GameOfLife::start() {
	//если есть входной файл то import() для загрузки данных
	if (_importSource.has_value()) {
		import();
	//иначе инициализируем поле и правило игры по умолчанию
	} else {
		example1();
	}
	//если заданная начальная итерация > 0 то вычисляем состояние поля после заданной итерации
	if (_startIteration > 0) {
		for (int i = 0; i < _startIteration; i++, _iterations++) {
			_field = _calculator.next(_field);
		}
	}
	//если есть выходной файл то
	if (_exportDestination.has_value()) {
		//создаем обьект с путем файла
		Dumper dumper(_exportDestination.value());
		//записываем состояние игры
		dumper.dump(_name, _rule, _field);
	} else {
		//иначе показываем поле игры 
		_view->start();
	}
}

//загрузка данных из входного файла
void GameOfLife::import() {
	std::filesystem::path path = _importSource.value();
	//проверка существует ли файл в указанном пути и проверка что это обычный файл а не директория
	if (!exists(path) || !is_regular_file(path)) {
		throw std::invalid_argument("Error: Specify correct input file.\n");
	}

	Importer importer(path);
	importer.import();

	_field = importer.getField();
	_rule = importer.getRule();
	_name = importer.getName();
}

//игры по умолчанию
void GameOfLife::example1() {
	_name = "Starship";
	_rule = Rule(
			std::array<bool, 9> {false, false, true},
			std::array<bool, 9> {false, false, true, true});
	   //.O...
	   //..O..
	   //OOO..
	   //.....
	_field.set(CellState::Alive, 1, 0);
	_field.set(CellState::Alive, 2, 1);
	_field.set(CellState::Alive, 0, 2);
	_field.set(CellState::Alive, 1, 2);
	_field.set(CellState::Alive, 2, 2);
}

bool GameOfLife::tick(unsigned int t) {
	for (unsigned int i = 0; i < t; i++, _iterations++) {
		_field = _calculator.next(_field);
	}
	return true;
}

bool GameOfLife::dump(const std::string& p) {
	auto path = std::filesystem::path(p);
	Dumper dumper(path);
	dumper.dump(_name, _rule, _field);
	return true;
}

std::string GameOfLife::getName() const {
	return _name.value_or("Untitled");
}

unsigned int GameOfLife::getAge() const {
	return _iterations;
}

std::string GameOfLife::getRule() const {
	return _rule.to_string();
}

Field GameOfLife::getField() const {
	return _field;
}
