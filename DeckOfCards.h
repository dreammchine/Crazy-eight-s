//DeckOfCards.h
//Definition of class DeckOfCards
#include <iostream>
#include <string>
#include <array>

using namespace std;

//card structure definition
struct Card{
    string face;
    string suit;
};

//class structure definition
class DeckOfCards{
public:
    const int numberOfCards {52};
    const int faces {13};
    const int suits {4};

    
DeckOfCards(); //initializes deck 
    void shuffle(); //shuffles deck
    void deal() const;

private:
    array<Card, 52> deck; //represents deck of cards 
};
