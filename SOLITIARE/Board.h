#pragma once
#include <iostream>
#include <vector>
#include "MyStack.h"
#include <stack>
#include "Card.h"
#include "Club.h"
#include "Spade.h"
#include "Heart.h"
#include "Diamond.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace std;

class Board
{
	sf::Texture background;
	vector<MyStack> piles;
	vector<stack<Card*>> foundation;
	stack<Card*> Deck;
	sf::RenderWindow* window;
	sf::Sprite backgroundImage;

	void shuffle(Card* Array[]);

public:
	Board();
	void initliazeWindow(sf::RenderWindow* window);
	void intiliazeDeck();
	void initliazePiles();
	void initializeFoundations();
	void Play();

};