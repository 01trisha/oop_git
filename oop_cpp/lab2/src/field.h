#pragma once
#include <vector>
#include <cstddef>
#include "cell.h"

//описание игрового поля
class Field {
public:
    Field() = default;
    Field(size_t width, size_t height);
    ~Field() = default;

    const CellState& at(size_t x, size_t y) const;
    void set(CellState state, size_t x, size_t y);
    size_t getHeight() const;
    size_t getWidth() const;
private:
    size_t _height = 10;
    size_t _width = 30;
    std::vector<CellState> _cells = std::vector<CellState>(_height * _width);
    size_t seek(size_t x, size_t y) const;
};
