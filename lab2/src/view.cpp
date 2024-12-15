#include <iostream>
#include "view.h"
//принимает указатель на GoL чтобы была возможность вызывать функции GoL
View::View(GameOfLife* game) : _game(game) {
}
//запуск основного цикла игры с ожиданием команд
void View::start() {
	printField();

	while (true) {
		std::string command;
		std::getline(std::cin, command);

		if (command.starts_with("dump")) {
			dump(command.substr(4));
		} else if (command.starts_with("tick")) {
			tick(command.substr(4));
		} else if (command.starts_with("t")) {
			tick(command.substr(1));
		} else if (command == "help") {
			printHelp();
		} else if (command == "exit") {
			break;
		} else {
			std::cout << "Error: Unknown command. To see list of commands use \"help\".\n";
		}
	}
}

void View::tick(const std::string& arg) {
	unsigned int t = 1;
	if (!arg.empty() && !arg.starts_with(" ")) {
		std::cout << "Error: Specify valid number! Usage: \"tick <number of iterations>\"\n";
		return;
	}
	if (!arg.empty()) {
		t = std::strtol(arg.substr(1).c_str(), nullptr, 10);
	}
	if (_game->tick(t)) {
		printField();
	}
}

void View::dump(const std::string& arg) {
	if (!arg.empty() && !arg.starts_with(" ")) {
		std::cout << "Error: Specify valid path! Usage: \"dump <filename>\"\n";
		return;
	}
	std::string p = arg.substr(1);
	if (_game->dump(p)) {
		std::cout << "Field successfully dumped as " << p << "\n";
	}
}

void View::printHelp() {
	std::cout
	<< "List of commands:\n"
	<< "\"dump <filename>\" - Save the game to specified file\n"
	<< "\"tick <n>\" - Calculate N iterations and print the result\n"
	<< "\"exit\" - Finish the game\n"
	<< "\"help\" - To see list of this commands\n";
}

void View::printField() {
	std::cout << "name: " << _game->getName() << "\nrule: " << _game->getRule() << "\nages: " << _game->getAge() << "\n";
	for (int y = 0; y < _game->getField().getHeight(); y++) {
		for (int x = 0; x < _game->getField().getWidth(); x++) {
			std::cout << (_game->getField().at(x, y) == CellState::Alive ? "O" : ".");
		}
		std::cout << "\n";
	}
}
