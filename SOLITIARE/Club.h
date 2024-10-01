#pragma once
#include "Card.h"

class Club : public Card
{
	
public:
	Club(string filepath, string backFilePath, int rank, char suit);
};

