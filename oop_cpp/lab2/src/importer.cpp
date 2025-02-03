#include <regex>
#include <iterator>
#include <iostream>
#include <sstream>
#include <string>
#include "importer.h"
#include "field.h"

Importer::Importer(const std::filesystem::path& path) : _input(path) {
}

std::optional<std::string> Importer::getName() {
	return _name;
}

Field Importer::getField() {
	return _field;
}

Rule Importer::getRule() {
	return _rule;
}

void Importer::import() {
	std::string line;
	if (!std::getline(_input, line) || line != "#Life 1.06") {
		throw std::invalid_argument("Error: Unknown file format.\n");
	}

	std::getline(_input, line);
	if (line.starts_with("#N ") && line.size() > 3) {
		_name = line.substr(3);
		std::getline(_input, line);
	} else {
		std::cout << "Warning: Name not specified!\n";
	}

	if (line.starts_with("#R ") && line.size() > 3) {
		std::string left, right;
		std::istringstream iss(line.substr(3));
		std::getline(iss, left, '/');
		std::getline(iss, right);

		std::array<bool, 9> born{false};
		std::array<bool, 9> survive{false};
		int zeroCode = 48;
		for (char symbol : left.starts_with("B") ? left.substr(1) : left) {
			born[symbol - zeroCode] = true;
		}
		for (char symbol : right.starts_with("S") ? right.substr(1) : right) {
			survive[symbol - zeroCode] = true;
		}
		_rule = Rule(born, survive);
		std::getline(_input, line);
	} else {
		std::cout << "Warning: Rule not specified!\n";
		_rule = Rule();
	}

	std::vector<int> aliveX, aliveY;
	int width = 30, height = 10;
	while (!line.empty()) {
		std::istringstream iss(line);
		int x, y;
		if (!(iss >> x >> y)) {
			break;
		}
		aliveX.push_back(x); aliveY.push_back(y);
		std::getline(_input, line);
	}
	if (aliveX.empty()) {
		std::cout << "Warning: Cells not specified!\n";
		aliveX.push_back(0); aliveY.push_back(2);
		aliveX.push_back(1); aliveY.push_back(0);
		aliveX.push_back(1); aliveY.push_back(2);
		aliveX.push_back(2); aliveY.push_back(1);
		aliveX.push_back(2); aliveY.push_back(2);
	}
	int maxWidth = *std::max_element(aliveX.begin(), aliveX.end());
	int minWidth = *std::min_element(aliveX.begin(), aliveX.end());
	int maxHeight = *std::max_element(aliveY.begin(), aliveY.end());
	int minHeight = *std::min_element(aliveY.begin(), aliveY.end());
	width += maxWidth - minWidth;
	height += maxHeight - minHeight;

	_field = Field(width, height);
	for (int i = 0; i < aliveX.size(); i++) {
		_field.set(CellState::Alive, aliveX[i], aliveY[i]);
	}
}
