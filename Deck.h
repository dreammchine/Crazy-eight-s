/*Deck Mechanics
o Deck Building
o Shuffle */


//DeckOfCards.h
//Definition of class DeckOfCards
#pragma once
#include <iostream>
#include <string>
#include <array>

using namespace std;

//card structure definition
struct Card {
	string face;
	string suit;
	void printCard(int numberInHand);
};

//class structure definition
class Deck {
public:
	const int numberOfCards{ 52 };
	const int faces{ 13 };
	const int suits{ 4 };


	Deck(); //initializes deck 
	void shuffle(); //shuffles deck

	Card getCard(int index);

private:
	array<Card, 52> deck; //represents deck of cards 
};