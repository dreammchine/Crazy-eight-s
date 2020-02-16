#include <iostream>
#include <iomanip>
#include <cstdlib> // prototype for rand and srand
#include <ctime>  // prototype for time
#include "Deck.h" // Deck of cards class

using namespace std;

//Deck of cards constructor initializes deck
Deck::Deck()
{
	//initialize suit array
	static string suit[]{ "Hearts", "Clubs","Diamonds", "Spades" };

	//initializa face array
	static string face[]{ "Ace", "Two", "Three", "Four", "Five",
		"Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

	//sets values for deck of 52 cards
	for (size_t i{ 0 }; i < deck.size(); ++i)
	{
		deck[i].face = face[i % faces];
		deck[i].suit = suit[i % suits];
	}

	srand(static_cast<size_t>(time(nullptr))); //seed
}

//shuffles deck
void Deck::shuffle()
{
	//shuffkes cards randomly
	for (size_t i{ 0 }; i < deck.size(); ++i)
	{
		int j{ rand() % numberOfCards };
		Card temp = deck[i];
		deck[i] = deck[j];
		deck[j] = temp;
	}
}

Card Deck::getCard(int index)
{
	return deck[index];
}
//
//// deal cards in deck
//void Deck::deal() const
//{
//	//displays each card's face and suit
//	for (size_t i = 0; i < deck.size(); ++i) {
//		cout << right << setw(5) << deck[i].face << " of " << left << setw(8) << deck[i].suit << ((i + 1) % 2 ? '\t' : '\n');
//	}
//}

void Card::printCard(int numberInHand)
{
	if(numberInHand > 0)
		cout << "\t" << numberInHand << ". " + face << " of " << left << setw(8) << suit << "\n";
	else
		cout << "\t" << face << " of " << left << setw(8) << suit << "\n";
}
