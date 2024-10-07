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
		if (currentCard->rank = 1)
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
	this->foundationPiles[index].push(*currentCard);
}


bool Foundation::checkIfComplete()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->foundationPiles[i].top().rank != 13)
			return false;
	}
	return true;
}
