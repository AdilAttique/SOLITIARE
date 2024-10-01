#pragma once
#include "Card.h"


class MyStack
{
public:
	vector<Card*> cards;
	int visible;
	int notVisible;
	int size;

	MyStack(vector<Card*> Cards, int vis, int notVis, int size);
};

