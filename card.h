#ifndef CARD_H
#define CARD_H
#include <ostream>
#include <string>

class card
{
	public:
		card(int value, int suit);
		card(const card& c);
		void setValue(int value);
		void setSuit(int suit);
		int getValue();
		int getSuit();
		friend std::ostream& operator<< (std::ostream& ostr, card& c);
		card& operator= (const card& c);
	private:
		int value, suit;
};


#endif

