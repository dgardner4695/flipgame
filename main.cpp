#include <iostream>
#include <algorithm>
#include <vector>
#include "card.h"
#include "d_node.h"
#include "deck.h"
using namespace std;
void playFlip()
{
	int choice, score = 0;
	//node<card> *tempNode;
	card current_card(0, 0);
	vector<int> chosen_cards = {};
	deck main_deck; //Default constructor, full deck
	deck hand(true); //Sets "empty_deck" to true to create a deck with no cards
	bool keep_playing = true;

	//Print Rules
	cout << "Flip Card Game Rules:\n"
		"~~~~~~~~~~~~~~~~~~~~\n"
		"You will draw 24 cards from the top of the deck, and choose\n"
		"one at a time. Based on the suit/value, you will accumulate points.\n"
		"Ace: +10 pts\n"
		"K, Q, J: +5 pts\n"
		"8, 9, 10: 0 pts\n"
		"7: Lose half of your total points (rounded up)\n"
		"2, 3, 4, 5, or 6: Lose ALL of your points\n"
		"Hearts: Gain 1 additional point\n"
		"24 cards will be chosen from a shuffled deck. You will select one\n"
		"from these 24 cards\n";
	cout << endl << endl << "Main deck:" << endl;
	cout << main_deck << endl;
	main_deck.shuffle();
	main_deck.shuffle();
	main_deck.shuffle();
	cout << endl << "Shuffled deck:" << endl;
	cout << main_deck << endl;

	for (int i = 0; i < 24; i++)
	{
		hand.replace(main_deck.deal());
	}

	cout << "Hand:" << endl;
	cout << hand << endl;

	while (keep_playing)
	{
		cout << "Select a card (1-24)" << endl;
		cin >> choice;
		while(find(chosen_cards.begin(), chosen_cards.end(), choice) != chosen_cards.end()) 
		{
			cout << "Card already chosen, try again" << endl;
			cin >> choice;
		}
		while (choice > 24 || choice < 1)
		{
			cout << "Invalid, try again" << endl;
			cin >> choice;
		}
		chosen_cards.push_back(choice);
		current_card = hand.getCard(choice);
		cout << "You selected: " << current_card << endl;

		if (current_card.getValue() == 0)
		{
			cout << "+10 pts for an Ace" << endl;
			score += 10;
		}
		else if (current_card.getValue() > 9)
		{
			cout << "+5 pts for a K, J or Q" << endl;
			score += 5;
			cout << "Current score: " << score << endl;
		}
		else if (current_card.getValue() == 6)
		{
			cout << "Card was a 7, score will be halved" << endl;
			score = score / 2;
			cout << "Current score: " << score << endl;
		}
		else if (current_card.getValue() >= 1 && current_card.getValue() <= 5)
		{
			cout << "Card was 2, 3, 4, 5 or 6. Score set to zero" << endl;
			score = 0;
			cout << "Current score: " << score << endl;
		}
		else
		{
			cout << "Card was 8, 9 or 10. No changes made to score" << endl;
			cout << "Current score: " << score << endl;
		}

		if (current_card.getSuit() == 2)
		{
			cout << "BONUS: Card suit was hearts, 1 point added" << endl;
			score++;
			cout << "Current score: " << score << endl;
		}
		char response;
		cout << "Would you like to continue picking cards? (y/n)" << endl;
		cin >> response;
		if (tolower(response) == 'n')
		{
			keep_playing = false;
			cout << "Final score: " << score << endl;
		}
	}
}

int main()
{
	playFlip();
	system("pause");
	return 0;
}