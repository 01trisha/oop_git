#include "dumper.h"
#include "rule.h"
#include "field.h"
//конструктор с путем файла
Dumper::Dumper(std::filesystem::path &path) : _output(path) {
}

void Dumper::dump(const std::optional<std::string> &name, const Rule &rule, const Field &field) {
	_output << "#Life 1.06\n";
	if (name.has_value()) {
		_output << "#N " << name.value() << "\n";
	}
	//записываем правила записывая rule в текстовом представлении
	_output << "#R " << rule.to_string() << "\n";
	size_t width = field.getWidth();
	size_t height = field.getHeight();
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			//если клетка живая то записываем как x y
			if (field.at(x, y) == CellState::Alive) {
				_output << x << " " << y << "\n";
			}
		}
	}
	//принудительная запись
	_output.flush();
}
