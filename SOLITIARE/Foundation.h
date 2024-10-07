#pragma once
#include <iostream>
#include <stack>
#include "Card.h">
#include<vector>

class Foundation
{
	vector <stack<Card>> foundationPiles;
	
public:
	Foundation();
	int insertionIndex(Card* currentCard);
	bool canInsert(Card* currentCard, int index);
	void insert(Card* currentCard, int index);
	bool checkIfComplete();
};

