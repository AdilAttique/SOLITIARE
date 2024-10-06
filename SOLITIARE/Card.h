#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;

class Card
{
public:
	int rank;
	char suit;
	sf::Texture frontImageTexture;
	static sf::Texture backImageTexture;
	sf::Sprite frontImage;
	sf::Sprite backImage;
	sf::Vector2f position;
	bool isFlipped = false;
	
	
	Card(string filepath, string backFilePath, int rank, char suit);
	void setPosition(sf::Vector2f pos);
	void setPosition(float x, float y);
	static void loadBackTexture()
	{
		if (!backImageTexture.loadFromFile("back.png"))
		{
			
		}
	}
	//static void setBackImage()
	//{
	//	backImage.setTexture(backImageTexture);
	//}
};
