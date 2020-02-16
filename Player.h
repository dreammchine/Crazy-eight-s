/*
Player Mechanics
1. Drop Card with Suitand Rank Check
2. Draw Card 
3. Drop Pair of Cards //TODO
4. Dropping Crazy Eights regardless of suit //TODO
5. Changing Suits //Right now it's handled in Game:playGame() ==> Can be refactored in player
6. Skip Turn //TODO
7. Card Penalties(Draw Two) //TODO
*/

#pragma once

#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "Deck.h"


using namespace std;


class Player
{
public:
	Player();

	Player(string n);

	string getName() const {
		return name;
	}

	int getHandSize() const;

	void setName();
	void showHand();

	int dropCard(Card topCard);

	vector <Card> getCards();

	void drawCard(Card c);


	//Remove the card c from the hand and return true if successful
	bool removeCardFromHand(int removeIndex);

	const int handStartSize = 8; // Game starts with one card placed on the tableand eight cards dealt to players that are in the game

private:

	string name;
	vector <Card> cards;  // VECTOR


};

#endif