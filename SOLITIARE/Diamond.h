#pragma once
#include "Card.h"

class Diamond : public Card
{

public:
	Diamond(string filepath, string backFilePath, int rank, char suit);
};

