#include "DeckOfCards.h"
#include <iostream>
#include "PlayerHand.h"

void main()
{
	cout << "Welcome to Crazy 8's" << "\n" << "Here's your deck" << "\n";
	DeckOfCards deckOfCards;
	deckOfCards.shuffle();
	deckOfCards.deal();

	cout << "\n";
	cout << "Player Hand" << '\n';
}
