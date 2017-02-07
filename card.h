#ifndef CARD_H
#define CARD_H
#include <ostream>
#include <string>

class card
{
	public:
		card(int value, int suit);
		void setValue(int value);
		void setSuit(int suit);
		int getValue();
		int getSuit();
		friend std::ostream& operator<< (std::ostream& ostr, card& c);
	private:
		int value, suit;
};


#endif

