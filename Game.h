/* Game Mechanics
1. Deal Cards
2. Turn Progression
3. Game Over(Finished Cards) */
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Deck.h"

using namespace std;


class Game {
public:
	Game();

	Player player1, player2;
	Deck deck;

	void setupGame();
	void playGame();


private:
	void setupPlayers();
	void setupDeck();
	void dealCards();

	int currentDrawIndex;
	Card topCardOnTable;
	int playersTurn;
};
