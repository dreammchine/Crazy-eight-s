// crazy-eights.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Game.h"

#include <iostream>

int main()
{
	cout << "Welcome to Crazy 8's \n";
	Game game;
	game.setupGame();
	game.playGame();

	return 0;
}


