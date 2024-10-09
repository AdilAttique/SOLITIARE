#pragma once
#include <iostream>
#include <stack>
#include "BSCS23196_Card.h">
#include<vector>

class Foundation
{
public:
	vector <stack<Card>> foundationPiles;
	

	Foundation();
	int insertionIndex(Card* currentCard);
	bool canInsert(Card* currentCard, int index);
	void insert(Card* currentCard, int index);
	bool checkIfComplete();
};

