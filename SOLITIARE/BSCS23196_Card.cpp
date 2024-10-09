#include "BSCS23196_Card.h"

sf::Texture Card::backImageTexture;

Card::Card(string filepath, string backFilePath, int Rank, char Suit)
{
	this->position.x = 1238, this->position.y = 1;
	frontImageTexture.loadFromFile(filepath);
	this->frontImage.setTexture(frontImageTexture);
	this->frontImage.setScale(0.11, 0.11);
	this->backImage.setTexture(backImageTexture);
	this->backImage.setScale(0.11, 0.11);
	this->backImage.setPosition(this->position);
	this->rank = Rank;
	this->suit = Suit;
}

void Card::setPosition(sf::Vector2f pos)
{
	this->position = pos;
	this->frontImage.setPosition(this->position);
	this->backImage.setPosition(this->position);
}

void Card::setPosition(float x, float y)
{
	sf::Vector2f pos;
	pos.x = x;
	pos.y = y;
	this->position = pos;
	this->frontImage.setPosition(this->position);
	this->backImage.setPosition(this->position);
}