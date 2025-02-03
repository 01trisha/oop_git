#include "calc.h"
#include "field.h"
//конструктор с обьектом правила 
Calculator::Calculator(const Rule &rule) : _rule(rule) {}
//следующее состояние игрового поля
Field Calculator::next(const Field &field) {
	size_t width = field.getWidth();
	size_t height = field.getHeight();
	//создаем новое поле с такими же размерами
	Field nextField(width, height);

	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			//для каждой клетки вычисляем состояние и сохраняем в новое поле 
			nextField.set(nextCellAt(x, y, field), x, y);
		}
	}

	return nextField;
}
//вычисление состояния клетки в следующем поколении
CellState Calculator::nextCellAt(size_t x, size_t y, const Field& field) {
	//текущее состояние
	CellState state = field.at(x, y);

	int neighboursCount = 0;
	if (field.at(x - 1, y - 1) == CellState::Alive) neighboursCount++;//слева сверху
	if (field.at(x, y - 1) == CellState::Alive) neighboursCount++;//сверху
	if (field.at(x + 1, y - 1) == CellState::Alive) neighboursCount++;//справа сверху

	if (field.at(x - 1, y) == CellState::Alive) neighboursCount++;//слева
	if (field.at(x + 1, y) == CellState::Alive) neighboursCount++;//справа

	if (field.at(x - 1, y + 1) == CellState::Alive) neighboursCount++;//слева снизу
	if (field.at(x, y + 1) == CellState::Alive) neighboursCount++;//снизу
	if (field.at(x + 1, y + 1) == CellState::Alive) neighboursCount++;//справа снизу

	return _rule.survives(state, neighboursCount);
}
