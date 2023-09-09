#include"Gallows.h"

void main() {
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Gallows game{};
	game.Print();//игра
}