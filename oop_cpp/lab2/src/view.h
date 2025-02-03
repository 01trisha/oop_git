#pragma once
#include <filesystem>
#include <optional>
#include "game.h"

class GameOfLife;
//взаимодействие с пользователем
class View {
public:
	View(GameOfLife* game);
	~View() = default;

	void start();
private:
	GameOfLife* _game;

	void tick(const std::string& arg);
	void dump(const std::string& arg);
	static void printHelp();
	void printField();
};
