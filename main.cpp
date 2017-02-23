#include <iostream>
#include "card.h"
#include "d_node.h"
#include "deck.h"
using namespace std;
void playFlip()
{
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
		"Hearts: Gain 1 additional point\n";

}

int main()
{
	playFlip();
	system("pause");
	return 0;
}