#pragma once
#include <filesystem>
#include <optional>
#include "calc.h"
#include "field.h"
#include "rule.h"
#include "view.h"

class View;
//основная логика управления процессом
class GameOfLife {
public:
	//конструктор с аргументами _importSource _exportDestination _startIteration и кол-во итераций через -i
	GameOfLife(char** argv, int argc);
	~GameOfLife() = default;

	void setView(View* view);
	void start();
	std::string getName() const;
	unsigned int getAge() const;
	std::string getRule() const;
	Field getField() const;
	bool tick(unsigned int t);
	bool dump(const std::string& p);
private:
	void import();
	void example1();

	View* _view{};
	std::optional<std::string> _name;
	Rule _rule;
	Field _field;
	Calculator _calculator;
	std::optional<std::filesystem::path> _importSource;
	std::optional<std::filesystem::path> _exportDestination;
	unsigned int _startIteration = 0;
	unsigned int _iterations = 0;
};
