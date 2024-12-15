#pragma once
#include "rule.h"
#include "cell.h"

class Field;

class Calculator {
public:
	Calculator() = default;
	Field next(const Field&);
private:
	CellState nextCellAt(size_t, size_t, const Field&);
	Rule _rule;
public:
	explicit Calculator(const Rule &rule);
};
