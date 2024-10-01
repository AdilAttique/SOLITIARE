#include "Card.h"


void Card::setPosition(sf::Vector2f pos)
{
	this->position = pos;
	this->frontImage.setPosition(this->position);
	this->backImage.setPosition(this->position);
}