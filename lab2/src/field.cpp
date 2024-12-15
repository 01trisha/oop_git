#include "field.h"
//конструктор с размером и массивом клеток
Field::Field(size_t width, size_t height) : _width(width), _height(height), _cells(std::vector<CellState>(height * width)) {
}

//состояние клетки на (x, y)
const CellState &Field::at(size_t x, size_t y) const {
	return _cells.at(seek(x, y));
}
//установка состояния клетки
void Field::set(CellState state, size_t x, size_t y) {
	_cells[seek(x, y)] = state;
}
//ширина поля
size_t Field::getWidth() const {
	return _width;
}
//высота поля
size_t Field::getHeight() const {
	return _height;
}
//вычисление индекса клетки относительно тороидального поля
size_t Field::seek(size_t x, size_t y) const {
	return ((y + _height) % _height) * _width + ((x + _width) % _width);
}
