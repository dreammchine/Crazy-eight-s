
#include "Player.h" // Deck of cards class


//Deck of cards constructor initializes deck
Player::Player(string n) {
	name = n;
}

Player::Player()
{
	name = "PC";
}


void Player::setName()
{
	string n = "";
	cin >> n;
	if(n.length() > 0)
		name = n;
}

void Player::drawCard(Card c)
{
	cards.push_back(c);
}


void Player::showHand()
{
	int numberInHand = 1;
	for (vector<Card>::size_type i = 0; i != cards.size(); i++) {
		cards[i].printCard(numberInHand);
		numberInHand++;
	}
}

int Player::dropCard(Card topCard)
{
	cout << getName() + " Enter the number for the card you'd like to drop:\n";
	cout << "\n";
	showHand();
	cout << "\n";
	int option = 0;
	cin >> option;
	Card chosenCard = cards[option - 1];
	if (chosenCard.face.compare(topCard.face) == 0 || chosenCard.suit.compare(topCard.suit) == 0) {
		cout << "You played the " << chosenCard.face << " of " << chosenCard.suit << ". \n";
		return option - 1;
	}
	else {
		cout << "You cannot play card " << option << " as it does not match suit or rank(number).\n";
		cout << "\n";
	}
	return -1;
}

vector<Card> Player::getCards()
{
	return cards;
}

int Player::getHandSize() const
{
	return cards.size();
}

bool Player::removeCardFromHand(int removeIndex)
{
	int currentIndex = 0;
	for (auto it = cards.begin(); it != cards.end(); ++it)
	{
		if (currentIndex == removeIndex) {
			it = cards.erase(it);
			return true;
		}
		++currentIndex;
	}

	return false;
}
