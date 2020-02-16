
#include "Game.h" // Deck of cards class


//Deck of cards constructor initializes deck
Game::Game() {
	Player player1("PC");
	Player player2("PC");
	Deck deck();
	playersTurn = 1;
	currentDrawIndex = 0;
}

void Game::setupGame()
{
	playersTurn = 1;
	currentDrawIndex = 0;
	setupPlayers();
	setupDeck();
	dealCards();
}

void Game::playGame()
{
	int player1CardsLeft = player1.getHandSize();
	int player2CardsLeft = player2.getHandSize();

	while (player1CardsLeft > 0 && player2CardsLeft > 0) {
		cout << "Players turn: " << playersTurn << "\n\n";
		cout << "Card on table: \n";
		topCardOnTable.printCard(0);
		cout << "\n";

		if (playersTurn == 1) {
			cout << player1.getName() + " Enter the number for the option you'd like to chose:\n";
			cout << "\t1. Play Card  \n";
			cout << "\t2. Draw Card  \n";
			cout << "\t3. Show Cards \n";
			int option = 0;
			cin >> option;

			if (option == 1) {
				int cardPicked = player1.dropCard(topCardOnTable);
				if (cardPicked > 0) {
					topCardOnTable = player1.getCards()[cardPicked];
					cout << "\tTop card on table is now: " << topCardOnTable.face << " of " << topCardOnTable.suit << ". \n";
					player1.removeCardFromHand(cardPicked);
					playersTurn = playersTurn == 1 ? 2 : 1;
				}
			}
			else if (option == 2) {
				player1.drawCard(deck.getCard(currentDrawIndex));
				currentDrawIndex++;
				cout << "\n";
				player1.showHand();
				cout << "\n";
				playersTurn = playersTurn == 1 ? 2 : 1;
			}
			else if (option == 3) {
				cout << "\n";
				player1.showHand();
				cout << "\n";
			}
		}
		else if (playersTurn == 2) {
			cout << player2.getName() + " Enter the number for the option you'd like to chose:\n";
			cout << "\t1. Play Card  \n";
			cout << "\t2. Draw Card  \n";
			cout << "\t3. Show Cards \n";
			int option = 0;
			cin >> option;

			if (option == 1) {
				int cardPicked = player2.dropCard(topCardOnTable);
				if (cardPicked > 0) {
					topCardOnTable = player2.getCards()[cardPicked];
					cout << "\tTop card on table is now: " << topCardOnTable.face << " of " << topCardOnTable.suit << ". \n";
					player2.removeCardFromHand(cardPicked);
					playersTurn = playersTurn == 1 ? 2 : 1;
				}
			}
			else if (option == 2) {
				player2.drawCard(deck.getCard(currentDrawIndex));
				currentDrawIndex++;
				cout << "\n";
				player2.showHand();
				cout << "\n";
				playersTurn = playersTurn == 1 ? 2 : 1;
			}
			else if (option == 3) {
				cout << "\n";
				player2.showHand();
				cout << "\n";
			}
		}

	}
}

void Game::setupPlayers() {
	cout << "Player 1, Enter name :\n";
	player1.setName();
	cout << "Player 2, Enter name :\n";
	player2.setName();
	cout << "Welcome players " + player1.getName() + " and " + player2.getName() + ".\n";
	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "\n\n";
}

void Game::setupDeck()
{
	deck.shuffle();
}

void Game::dealCards()
{
	topCardOnTable = deck.getCard(currentDrawIndex);
	currentDrawIndex++;

	for (int i = 0; i < player1.handStartSize; ++i) {
		player1.drawCard(deck.getCard(currentDrawIndex));
		currentDrawIndex++;
	}
	for (int i = 0; i < player2.handStartSize; ++i) {
		player2.drawCard(deck.getCard(currentDrawIndex));
		currentDrawIndex++;
	}

/*

	cout << "Card on table: \n";
	topCardOnTable.printCard(0);
	cout << "\n";

	cout << player1.getName() + "'s cards: \n";
	player1.viewCards();

	cout << "\n";
	cout << player2.getName() + "'s cards: \n";
	player2.viewCards();
*/
}
