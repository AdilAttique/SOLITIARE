#pragma once
#include "BSCS23196_Card.h"


class MyStack
{
public:
	vector<Card> cards;
	int myPile;
	sf::Vector2f position;

	MyStack(vector<Card>& Cards, int MyPile ,sf::Vector2f position);
};

