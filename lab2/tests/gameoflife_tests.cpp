#include <gtest/gtest.h>
#include "../src/calc.h"
#include "../src/dumper.h"
#include "../src/field.h"
#include "../src/importer.h"

TEST(GameOfLifeTest, CalculatorTest) {
	Calculator calculator;
	Field field;

	/*
	   ..O....
	   OO..OO.
	   .....O.
	   ..OO...
	*/
	field.set(CellState::Alive, 2, 0);
	field.set(CellState::Alive, 0, 1);
	field.set(CellState::Alive, 1, 1);
	field.set(CellState::Alive, 4, 1);
	field.set(CellState::Alive, 5, 1);
	field.set(CellState::Alive, 5, 2);
	field.set(CellState::Alive, 2, 3);
	field.set(CellState::Alive, 3, 3);

	EXPECT_EQ(field.at(0, 0), CellState::Dead);
	EXPECT_EQ(field.at(1, 0), CellState::Dead);
	EXPECT_EQ(field.at(2, 0), CellState::Alive);
	EXPECT_EQ(field.at(0, 1), CellState::Alive);
	EXPECT_EQ(field.at(1, 1), CellState::Alive);
	EXPECT_EQ(field.at(4, 1), CellState::Alive);
	EXPECT_EQ(field.at(5, 1), CellState::Alive);
	EXPECT_EQ(field.at(5, 2), CellState::Alive);
	EXPECT_EQ(field.at(2, 3), CellState::Alive);
	EXPECT_EQ(field.at(3, 3), CellState::Alive);
	EXPECT_EQ(field.at(5, 3), CellState::Dead);
	EXPECT_EQ(field.at(6, 3), CellState::Dead);

	Field nextField = calculator.next(field);

	/*
	   .O.....
	   .O..OO.
	   .OOO.O.
	   .......
	*/
	EXPECT_EQ(nextField.at(0, 0), CellState::Dead);
	EXPECT_EQ(nextField.at(2, 0), CellState::Dead);
	EXPECT_EQ(nextField.at(1, 0), CellState::Alive);
	EXPECT_EQ(nextField.at(1, 1), CellState::Alive);
	EXPECT_EQ(nextField.at(4, 1), CellState::Alive);
	EXPECT_EQ(nextField.at(5, 1), CellState::Alive);
	EXPECT_EQ(nextField.at(1, 2), CellState::Alive);
	EXPECT_EQ(nextField.at(2, 2), CellState::Alive);
	EXPECT_EQ(nextField.at(3, 2), CellState::Alive);
	EXPECT_EQ(nextField.at(5, 2), CellState::Alive);
	EXPECT_EQ(nextField.at(5, 3), CellState::Dead);
	EXPECT_EQ(nextField.at(6, 3), CellState::Dead);
}

TEST(GameOfLifeTest, ImporterTest) {
	//создаем тестовый файл и записываем инфу
	std::ofstream output("ImporterTestPath");

	/*
	   ..O....
	   OO..OO.
	   .....O.
	   ..OO...
	*/
	output
	<< "#Life 1.06\n"
	<< "#N ImporterTestName\n"
	<< "#R B35/S138\n"
	<< "2 0\n"
	<< "0 1\n"
	<< "1 1\n"
	<< "4 1\n"
	<< "5 1\n"
	<< "5 2\n"
	<< "2 3\n"
	<< "3 3\n";
	output.close();

	std::string name("ImporterTestName");
	Rule rule(
			{false, false, false, true, false, true, false, false, false},
			{false, true, false, true, false, false, false, false, true});

	Importer importer(std::filesystem::path("ImporterTestPath"));
	importer.import();
	//сравниваем имя
	EXPECT_EQ(name, importer.getName());
	//проверяем правила
	for (int i = 0; i <= 8; i++) {
		EXPECT_TRUE(rule.survives(CellState::Alive, i) == importer.getRule().survives(CellState::Alive, i));
		EXPECT_TRUE(rule.survives(CellState::Dead, i) == importer.getRule().survives(CellState::Dead, i));
	}
	//проверяем состояние клеток
	Field field = importer.getField();
	EXPECT_EQ(field.at(0, 0), CellState::Dead);
	EXPECT_EQ(field.at(1, 0), CellState::Dead);
	EXPECT_EQ(field.at(2, 0), CellState::Alive);
	EXPECT_EQ(field.at(0, 1), CellState::Alive);
	EXPECT_EQ(field.at(1, 1), CellState::Alive);
	EXPECT_EQ(field.at(4, 1), CellState::Alive);
	EXPECT_EQ(field.at(5, 1), CellState::Alive);
	EXPECT_EQ(field.at(5, 2), CellState::Alive);
	EXPECT_EQ(field.at(2, 3), CellState::Alive);
	EXPECT_EQ(field.at(3, 3), CellState::Alive);
	EXPECT_EQ(field.at(5, 3), CellState::Dead);
	EXPECT_EQ(field.at(6, 3), CellState::Dead);
}

TEST(GameOfLifeTest, DumperTest) {
	Field field;

	/*
	   ..O....
	   OO..OO.
	   .....O.
	   ..OO...
	*/
	field.set(CellState::Alive, 2, 0);
	field.set(CellState::Alive, 0, 1);
	field.set(CellState::Alive, 1, 1);
	field.set(CellState::Alive, 4, 1);
	field.set(CellState::Alive, 5, 1);
	field.set(CellState::Alive, 5, 2);
	field.set(CellState::Alive, 2, 3);
	field.set(CellState::Alive, 3, 3);

	std::filesystem::path path("DumperTestPath");
	Dumper dumper(path);

	std::string name("DumperTestName");
	Rule rule;
	//сохраняем поле в файл
	dumper.dump(name, rule, field);

	Importer importer(path);
	importer.import();

	Field importedField = importer.getField();
	//имортируем этот же файл и проверяем
	EXPECT_EQ(importer.getRule().to_string(), rule.to_string());
	EXPECT_EQ(importer.getName(), name);
	EXPECT_EQ(importedField.at(0, 0), CellState::Dead);
	EXPECT_EQ(importedField.at(1, 0), CellState::Dead);
	EXPECT_EQ(importedField.at(2, 0), CellState::Alive);
	EXPECT_EQ(importedField.at(0, 1), CellState::Alive);
	EXPECT_EQ(importedField.at(1, 1), CellState::Alive);
	EXPECT_EQ(importedField.at(4, 1), CellState::Alive);
	EXPECT_EQ(importedField.at(5, 1), CellState::Alive);
	EXPECT_EQ(importedField.at(5, 2), CellState::Alive);
	EXPECT_EQ(importedField.at(2, 3), CellState::Alive);
	EXPECT_EQ(importedField.at(3, 3), CellState::Alive);
	EXPECT_EQ(importedField.at(5, 3), CellState::Dead);
	EXPECT_EQ(importedField.at(6, 3), CellState::Dead);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
