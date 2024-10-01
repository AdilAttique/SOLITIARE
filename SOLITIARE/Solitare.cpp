#include "Solitare.h"

//if (evnt.mouseButton.button == sf::Mouse::Right)
//{
//	float xpos = sf::Mouse::getPosition(window).x;
//	float ypos = sf::Mouse::getPosition(window).y;
//	cout << "X: " << xpos << "  Y: " << ypos << endl;
//}

Solitare::Solitare() : window(sf::VideoMode(1366, 760), "Solitaire by Adil", sf::Style::Close | sf::Style::Resize)
{

}

void Solitare::Initialize()
{
	this->board.initliazeWindow(&window);
	this->board.intiliazeDeck();
	this->board.initliazePiles();
}

void Solitare::startGame()
{
	this->Initialize();
	this->board.Play();
}