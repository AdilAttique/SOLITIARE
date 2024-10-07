#pragma once
#include <iostream>
#include <vector>
#include "MyStack.h"
#include "Foundation.h"
#include <stack>
#include <deque>
#include "Card.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace std;

class Board
{
	sf::Texture background;
	vector<MyStack> piles;
	Foundation Home;
	stack<Card> Deck;
	deque<Card> withdrawnDeck;
	sf::RenderWindow* window;
	sf::Sprite backgroundImage;
	string mode = "Easy";
	Board* boardState;

	void shuffle(vector<Card>& Array);

public:
	Board();
	void initliazeWindow(sf::RenderWindow* window);
	void intiliazeDeck();
	void initliazePiles();
	void initializeFoundations();
	bool canPlaceCard(Card* currentCard, Card* targetCard);
	void Play();
	void addToPile(Card* currentCard, Card* tempCard, vector<Card*>& selectedCards, int sourcePileIndex,int index, bool& isPositionChanged);
	void saveBoardState();
};