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
		~deck();
		friend std::ostream& operator<<(std::ostream& ostr, deck& d);
		void shuffle();
	private:
		node<card> *front;
};


#endif
