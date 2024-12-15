#include "Config.h"

using namespace std;

int main(int argc, char** argv) {
	View view(argc, argv);
	if (!view.start()) {
		return 1;
	}
	Config config(view);
	config.start(view.help());
}

