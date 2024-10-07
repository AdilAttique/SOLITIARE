#include "Foundation.h"



Foundation::Foundation()
{
	for (int i = 0; i < 4; i++)
	{
		stack<Card> temp;
		this->foundationPiles.push_back(temp);
	}
}

int Foundation::insertionIndex(Card* currentCard)
{
	if (currentCard->suit == 'H')
		return 0;
	else if (currentCard->suit == 'D')
		return 1;
	else if (currentCard->suit == 'C')
		return 2;
	else if (currentCard->suit == 'S')
		return 3;
}

bool Foundation::canInsert(Card* currentCard ,int index)
{
	if (this->foundationPiles[index].empty())
		if (currentCard->rank == 1)
			return true;
		else
			return false;

	if (this->foundationPiles[index].top().rank == currentCard->rank - 1)
		return true;
	else
		return false;
}

void Foundation::insert(Card* currentCard, int index)
{
	if (index == 0)
		currentCard->setPosition(48,1);
	else if(index == 1)
		currentCard->setPosition(205, 1);
	else if (index == 2)
		currentCard->setPosition(363, 1);
	else if (index == 3)
		currentCard->setPosition(522, 1);
	this->foundationPiles[index].push(*currentCard);
}


bool Foundation::checkIfComplete()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->foundationPiles[i].empty())
			return false;
		if (this->foundationPiles[i].top().rank != 13)
			return false;
	}
	return true;
}
