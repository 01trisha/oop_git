#include "Config.h"

using namespace std;

int main(int argc, char** argv) {
	//парсим аргументы переданные
	View view(argc, argv);
	if (!view.start()) {
		return 1;
	}
	//если все нормально, то создаем config и запускаем
	Config config(view);
	config.start(view.help());
}

