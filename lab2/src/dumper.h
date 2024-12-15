#pragma once
#include <filesystem>
#include <fstream>
#include <optional>

class Rule;
class Field;
//экспорт ну или сохранение игры в файл
class Dumper {
public:
	explicit Dumper(std::filesystem::path&);
	~Dumper() = default;

	void dump(const std::optional<std::string>& name, const Rule& rule, const Field&);
private:
	std::ofstream _output;
};
