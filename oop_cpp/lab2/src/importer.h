#pragma once
#include <filesystem>
#include <fstream>
#include <optional>
#include "rule.h"
#include "importer.h"
#include "field.h"

class Field;

//импорт файла
class Importer {
public:
	explicit Importer(const std::filesystem::path&);
	void import();
	Rule getRule();
	Field getField();
	std::optional<std::string> getName();
private:
	Rule _rule;
	Field _field;
	std::optional<std::string> _name;
	std::ifstream _input;
};
