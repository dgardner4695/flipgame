#include <iostream>
#include <random>
#include <time.h>
#include "d_node.h"
#include "card.h"
#include "deck.h"

deck::deck()
{
	for (int i = 3; i >= 0; i--)
	{
		for (int j = 12; j >= 0; j--)
		{
			card c(j, i);
			node<card> *newCard = new node<card>(c, front);
			front = newCard;
		}
	}
}

std::ostream& operator<< (std::ostream& ostr, deck& d)
{
	deck tempNode = d;
	while (tempNode.front != NULL)
	{
		ostr << tempNode.front->nodeValue << std::endl;
		tempNode.front = tempNode.front->next;
	}
	return ostr;
}

void deck::shuffle()
{
	int i=0, j = 0;
	srand(time(0));
	node<card> *prev, *curr;
	while (j < 1000000)
	{
		prev = NULL;
		curr = front;
		int rand_index = rand() % 51 + 1;
		i = 0;
		while (i != rand_index)
		{
			prev = curr;
			curr = curr->next;
			i++;
		}
		prev->next = curr->next;
		curr->next = front;
		front = curr;
		j++;
	}
}

int main()
{
	deck d;
	std::cout << "Before Shuffling:" << std::endl;
	std::cout << d;
	d.shuffle();
	std::cout << std::endl << "After Shuffling: " << std::endl;
	std::cout << d;
	system("pause");
}