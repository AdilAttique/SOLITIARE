#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Card
{
public:
	int rank;
	char suit;
	sf::Texture frontImageTexture;
	sf::Texture backImageTexture;
	sf::Sprite frontImage;
	sf::Sprite backImage;
	sf::Vector2f position;
	bool isFlipped = false;

	void setPosition(sf::Vector2f pos);
	
};
