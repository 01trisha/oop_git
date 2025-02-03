#pragma once
#include <array>
#include <string>
#include "cell.h"

//описание правил
class Rule {
public:
	Rule() = default;
	~Rule() = default;

	Rule(const std::array<bool, 9> &born, const std::array<bool, 9> &survive);
	CellState survives(CellState alive, int neighboursCount);
	std::string to_string() const;
private:
	std::array<bool, 9> _born{false, false, false, true, false, false, false, false, false};
	std::array<bool, 9> _survive{false, false, true, true, false, false, false, false, false};
};
