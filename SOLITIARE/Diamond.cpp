#include "Diamond.h"


Diamond::Diamond(string filepath, string backFilePath, int Rank, char Suit)
{
	this->position.x = 1238, this->position.y = 15;
	frontImageTexture.loadFromFile(filepath);
	this->frontImage.setTexture(frontImageTexture);
	this->frontImage.setScale(0.03, 0.03);
	backImageTexture.loadFromFile(backFilePath);
	this->backImage.setTexture(backImageTexture);
	this->backImage.setScale(0.03, 0.03);
	this->backImage.setPosition(this->position);
	this->rank = Rank;
	this->suit = Suit;
}