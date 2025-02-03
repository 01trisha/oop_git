#include <iostream>
#include "game.h"

int main(int argc, char** argv) {
	try {
		GameOfLife game(argv, argc);
		View view(&game); // для управления состоянием игры
		game.setView(&view); // устанавливаем как интерфейс игры
		game.start();
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	return 0;
}
