#include <iostream>
#include <string>
#include "card.h"

const std::string values[] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };
const std::string suits[] = { "Clubs", "Diamonds", "Hearts", "Spades" };

card::card(int value, int suit)
{
	this->value = value;
	this->suit = suit;
}

card::card(const card& c)
{
	this->value = c.value;
	this->suit = c.suit;
}

int card::getValue()
{
	return value;
}

int card::getSuit()
{
	return suit;
}

void card::setValue(int value)
{
	this->value = value;
}

void card::setSuit(int suit)
{
	this->suit = suit;
}

std::ostream& operator<< (std::ostream& ostr, card& c)
{
	ostr << values[c.getValue()] << " of " << suits[c.getSuit()] << std::endl;
	return ostr;
}

void card::operator= (const card& c)
{
	this->value = c.value;
	this->suit = c.suit;
}