#include "BSCS23196_MyStack.h"



MyStack::MyStack(vector<Card>& Cards, int MyPile, sf::Vector2f Position)
{
	for (int i = 0; i < Cards.size(); i++)
	{
		this->cards.push_back(Cards[i]);
	}

	this->position = Position;
	this->myPile = MyPile;
}