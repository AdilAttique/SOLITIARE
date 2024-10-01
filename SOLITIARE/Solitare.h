#pragma once
#include "Board.h"
#include <iostream>
using namespace std;


class Solitare
{
	Board board;
	sf::RenderWindow window;

public:
	Solitare();
	void Initialize();
	void startGame();
};

