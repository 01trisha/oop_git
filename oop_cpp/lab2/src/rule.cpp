#include "rule.h"
//конструктор с правилами
Rule::Rule(const std::array<bool, 9> &born, const std::array<bool, 9> &survive) : _born(born), _survive(survive) {}

CellState Rule::survives(CellState state, int neighboursCount) {
	if (state == CellState::Alive) {
		//если true по индексу то будет alive иначе дед
		return _survive.at(neighboursCount) ? CellState::Alive : CellState::Dead;
	}
	return _born.at(neighboursCount) ? CellState::Alive : CellState::Dead;
}
//строковое представление правил игры по булевому массиву
std::string Rule::to_string() const {
	std::string result("B");
	for (int i = 0; i < 9; i++) {
		if (_born[i]) {
			result += std::to_string(i);
		}
	}
	result += "/S";
	for (int i = 0; i < 9; i++) {
		if (_survive[i]) {
			result += std::to_string(i);
		}
	}
	return result;
}
