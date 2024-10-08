#pragma once
#include "Board.h"
#include <iostream>
#include <SFML/Audio.hpp>
using namespace std;


class Solitare
{
	Board board;
	sf::RenderWindow window;
	sf::Texture startBackgroundTexture;
	sf::Sprite startBackgroundImage;
	string gameMode;

public:
	Solitare();
	void modeSelection();
	void Initialize();
	void startGame();
};

