#pragma once
#include <iostream>
#include <vector>
#include "BSCS23196_MyStack.h"
#include "BSCS23196_Foundation.h"
#include <stack>
#include <deque>
#include "BSCS23196_Card.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "BSCS23196_Firework.h"
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
	bool userwon;
	int score;
	sf::Text scoreText;
	sf::Text TimeText;

	void shuffle(vector<Card>& Array);

public:
	Board();
	void initliazeWindow(sf::RenderWindow* window);
	void intiliazeDeck();
	void initliazePiles();
	void initializeFoundations();
	bool canPlaceCard(Card* currentCard, Card* targetCard);
	void Play(string gameMode);
	void addToPile(Card* currentCard, Card* tempCard, vector<Card*>& selectedCards, int sourcePileIndex,int index, bool& isPositionChanged, bool &changeHappen);
	void saveBoardState();
	void undoMove();
	void redoMove();
};