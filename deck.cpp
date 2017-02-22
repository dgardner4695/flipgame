#include <iostream>
#include <random>
#include <time.h>
#include "d_node.h"
#include "card.h"
#include "deck.h"

deck::deck()
{
    node<card> *curr;
	for (int i = 3; i >= 0; i--)
	{
		for (int j = 12; j >= 0; j--)
		{
			card c(j, i);
			node<card> *newCard = new node<card>(c, NULL);
            if(i == 3 && j == 12){
                front = newCard;
                curr = newCard;
            }
            else{
                curr->next = newCard;
                curr = newCard;
            }

		}
	}
}

std::ostream& operator<< (std::ostream& ostr, deck& d)
{
    //std::cout << d.front->next->next->nodeValue.getValue();
	deck tempNode = d;
    //Included the counter to avoid segmentation fault.  My partner, Daniel Gardener, does not have this issue
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
	while (j < 104) //go through the deck twice
	{
		prev = NULL;
		curr = front;
		int rand_index = rand() % 51 + 1; //new position for card
		i = 0;
		while (i != rand_index)
		{
			prev = curr;
			curr = curr->next;
			i++;
		}
		prev->next = curr->next; //move card
		curr->next = front;
		front = curr;
		j++;
	}
}

card deck::deal(){
    if(front != NULL){
        node *n = front;
        front = n->next; //reset the front of the deck
        return n->nodeValue; //return the card that used to be 'front'
    }
}

void deck::replace(card c){
    if(front != NULL){
        node *temp = front;
        node *newNode = new node(c, NULL);

        while(temp->next != NULL){
            temp = temp->next; //iterate through the deck
        }

        temp->next = newNode;  //add card to end of the deck
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
    return 0;
}
