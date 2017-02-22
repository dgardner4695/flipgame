#ifndef DECK_H
#define DECK_H

#include <ostream>
#include <string>
#include "card.h"
#include "d_node.h"

class deck
{
	public:
		deck();
		//My partner included a destructor, but it was causing segmentation faults on my computer
		friend std::ostream& operator<<(std::ostream& ostr, deck& d);
		void shuffle();
        card deal();
        void replace(card c);
	private:
		node<card> *front;
};


#endif
