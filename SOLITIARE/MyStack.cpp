#include "MyStack.h"



MyStack::MyStack(vector<Card*> Cards, int vis, int notVis, int Size)
{
	for (int i = 0; i < Cards.size(); i++)
	{
		this->cards.push_back(Cards[i]);
	}

	this->visible = vis;
	this->notVisible = notVis;
	this->size = Size;
}