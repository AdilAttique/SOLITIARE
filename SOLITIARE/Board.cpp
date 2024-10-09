#include "Board.h"


stack<Board> undoStack;
stack<Board> redoStack;
Board::Board()
{
	background.loadFromFile("Background.png");
	this->backgroundImage.setTexture(background);
	this->score = 0;
	this->scoreText.setCharacterSize(40);
	this->scoreText.setFillColor(sf::Color::White);
	this->scoreText.setPosition(1170, 515);
	this->TimeText.setCharacterSize(40);
	this->TimeText.setFillColor(sf::Color::White);
	this->TimeText.setPosition(1170, 615);
}

void Board::shuffle(vector<Card>& Array)
{
	srand(time(0));

	for (int i = 51; i > 0; i--)
	{
		int j = rand() % (i + 1);

		Card tempCard = Array[i];
		Array[i] = Array[j];
		Array[j] = tempCard;
	}

}


void Board::initliazeWindow(sf::RenderWindow* window)
{
	this->window = window;
}

void Board::intiliazeDeck()
{
	vector<Card> temp;
	string filepathFront;
	//int rank;
	Card::loadBackTexture();
	for (int i = 0, code = 1, rank = 1; i < 13; i++, code+=4, rank--)
	{	
		filepathFront = to_string(code) += ".png";
		cout << i << endl;
		Card* card = new Card(filepathFront, "back.png", rank, 'C');
		temp.push_back(*card);
		if (i == 0)
			rank = 14;
	}

	for (int i = 13, code = 2, rank = 1; i < 26; i++, code += 4, rank--)
	{
		filepathFront = to_string(code) += ".png";
		cout << i << endl;
		Card* card = new Card(filepathFront, "back.png", rank, 'S');
		temp.push_back(*card);
		if (i == 13)
			rank = 14;
	}

	for (int i = 26, code = 3, rank = 1; i < 39; i++, code += 4, rank--)
	{
		filepathFront = to_string(code) += ".png";
		cout << i << endl;
		Card* card = new Card(filepathFront, "back.png", rank, 'H');
		temp.push_back(*card);
		if (i == 26)
			rank = 14;
	}

	for (int i = 39, code = 4, rank = 1; i < 52; i++, code += 4, rank--)
	{
		filepathFront = to_string(code) += ".png";
		cout << i << endl;
		Card* card = new Card(filepathFront, "back.png", rank, 'D');
		temp.push_back(*card);
		if (i == 39)
			rank = 14;
	}

	this->shuffle(temp);
	this->shuffle(temp);
	this->shuffle(temp);
	this->shuffle(temp);


	for (int i = 0; i < 52; i++)
	{
		this->Deck.push(temp[i]);
	}
}


void Board::initliazePiles()
{
	sf::Vector2f tempPosition;
	for (int i = 0; i < 7; i++)
	{
		tempPosition.y = 142;

		if (i == 0)
			tempPosition.x = 47;
		else if (i == 1)
			tempPosition.x = 205;
		else if (i == 2)
			tempPosition.x = 363;
		else if (i == 3)
			tempPosition.x = 521;
		else if (i == 4)
			tempPosition.x = 679;
		else if (i == 5)
			tempPosition.x = 836;
		else if (i == 6)
			tempPosition.x = 995;


		vector<Card> tempVector;
		for (int j = 0; j <= i; j++)
		{
			if (j != 0)
				tempPosition.y += 42;
			tempVector.push_back(this->Deck.top());
			tempVector[j].setPosition(tempPosition);
			if (j == i)
			{
				tempVector[j].isFlipped = true;
				cout << i << " Row: " << tempVector[j].position.x << "  " << tempVector[j].position.y << endl;
 			}
			this->Deck.pop();
		}

		tempPosition.y = 145;
		MyStack tempMyStack(tempVector, i ,tempPosition);
		this->piles.push_back(tempMyStack);
	}
}


void Board::initializeFoundations()
{

}


bool Board::canPlaceCard(Card* currentCard, Card* targetCard)
{
	if (!targetCard) {
		return currentCard->rank == 13;
	}
	cout << "Current Card Details: " << currentCard->suit << "  " << currentCard->rank << endl;
	cout << "Target Card Details: " << targetCard->suit << "  " << targetCard->rank << endl;
	bool currentCardIsRed = (currentCard->suit == 'H' || currentCard->suit == 'D');
	bool targetCardIsRed = (targetCard->suit == 'H' || targetCard->suit == 'D');

	bool differentColors = (currentCardIsRed != targetCardIsRed);

	bool correctRank = (currentCard->rank == targetCard->rank - 1);

	return differentColors && correctRank;
}



void Board::addToPile(Card* currentCard, Card* tempCard, vector<Card*>& selectedCards, int sourcePileIndex, int index, bool & isPositionChanged,bool& changeHappen)
{
	if (this->piles[index].cards.empty())
		tempCard = nullptr;
	else
		tempCard = &this->piles[index].cards.back();
	if (canPlaceCard(currentCard, tempCard))
	{
		sf::Vector2f tempPosition = this->piles[index].position;
		for (int i = 0; i < this->piles[index].cards.size(); i++)
		{
			tempPosition.y += 42;
		}
		currentCard->setPosition(tempPosition);

		isPositionChanged = true;

		for (int i = 0; i < selectedCards.size(); i++)
		{
			selectedCards[i]->setPosition(tempPosition.x, tempPosition.y + (i * 42)); 
			this->piles[index].cards.push_back(*selectedCards[i]);
		}

		if (sourcePileIndex >= 0)
		{
			this->piles[sourcePileIndex].cards.erase(
				this->piles[sourcePileIndex].cards.end() - selectedCards.size(),
				this->piles[sourcePileIndex].cards.end()
			);
			this->score += 10;
		}
		else if (sourcePileIndex == -2)
		{
			withdrawnDeck.pop_back();
			this->score += 5;
		}
		else if (sourcePileIndex == -3)
		{
			for (int i = 0; i < 4; i++)
			{
				if (!this->Home.foundationPiles[i].empty())
					if (this->Home.foundationPiles[i].top().suit == selectedCards[0]->suit)
						this->Home.foundationPiles[i].pop();
			}
			this->score += 10;
		}
	}
}
#include <iomanip>
#include <sstream>
void Board::Play(string gameMode)
{
	sf::SoundBuffer cardPlacingBuffer;
	cardPlacingBuffer.loadFromFile("Card Plaicng Sound.mp3");
	sf::Sound cardPlacingSound;
	cardPlacingSound.setBuffer(cardPlacingBuffer);
	cardPlacingSound.setPlayingOffset(sf::seconds(1));
	bool isSpriteSelected = false;
	Card* currentCard = nullptr;
	vector<Card*> selectedCards;	
	sf::Vector2f originalPosition;
	vector<sf::Vector2f> originalPositions;
	int sourcePileIndex = -1;
	window->setFramerateLimit(60);
	vector<Firework> fireworks;
	sf::Clock clock;
	sf::Font font;
	font.loadFromFile("times.ttf");
	this->scoreText.setFont(font);
	this->TimeText.setFont(font);
	sf::Text winText;
	winText.setFont(font);
	winText.setString("You Win!");
	winText.setCharacterSize(60); 
	winText.setFillColor(sf::Color::White);
	sf::FloatRect textRect = winText.getLocalBounds();
	winText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	winText.setPosition(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f);
	int count = 0;
	sf::Clock endClock;
	float endTime = 0;
	bool changeHappen = false;
	string scoreString = "Score: 0";
	sf::Clock Time;
	Time.restart().asSeconds();
	sf::Time timeElapsed;
	while (window->isOpen())
	{
		sf::Event evnt;

		while (window->pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed)
			{
				window->close();
			}
			if (evnt.mouseButton.button == sf::Mouse::Right)
			{
				float xpos = sf::Mouse::getPosition(*window).x;
				float ypos = sf::Mouse::getPosition(*window).y;
				cout << "X: " << xpos << "  Y: " << ypos << endl;
			}
			
			if (evnt.type == sf::Event::MouseButtonPressed)
			{
				if (evnt.mouseButton.button == sf::Mouse::Left)
				{
					sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
					if ((static_cast<float>(mousePosition.x) > 1270 && static_cast<float>(mousePosition.x) < 1330) && (static_cast<float>(mousePosition.y) > 310 && static_cast<float>(mousePosition.y) < 365))
					{
						this->undoMove();
					}
					else if ((static_cast<float>(mousePosition.x) > 1270 && static_cast<float>(mousePosition.x) < 1330) && (static_cast<float>(mousePosition.y) > 405 && static_cast<float>(mousePosition.y) < 450))
					{
						this->redoMove();
					}
					
					for (int i = 0; i < 7; i++)
					{
						for (int j = 0; j < this->piles[i].cards.size(); j++)
						{
							
							if (this->piles[i].cards[j].frontImage.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
							{
								saveBoardState();
								if (this->piles[i].cards[j].isFlipped)
								{
									currentCard = &this->piles[i].cards[j];
									originalPosition = this->piles[i].cards[j].position;
									isSpriteSelected = true;
									sourcePileIndex = i;

									selectedCards.clear();
									originalPositions.clear();
									for (int k = j; k < this->piles[i].cards.size(); k++) 
									{
										selectedCards.push_back(&this->piles[i].cards[k]);
										originalPositions.push_back(this->piles[i].cards[k].position);
									}
								}
							}

						}
					}
					for (int i = 0; i < 4; i++)
					{
						if (!this->Home.foundationPiles[i].empty())
						{
							if (this->Home.foundationPiles[i].top().frontImage.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
							{
								saveBoardState();
								currentCard = &this->Home.foundationPiles[i].top();
								originalPosition = this->Home.foundationPiles[i].top().position;
								isSpriteSelected = true;
								sourcePileIndex = -3;

								selectedCards.clear();
								originalPositions.clear();
								originalPositions.push_back(this->Home.foundationPiles[i].top().position);
								selectedCards.push_back(currentCard);
							}
						}
					}
					if (!this->Deck.empty())
					{
						if (this->Deck.top().backImage.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
						{
							saveBoardState();
							if (gameMode == "Easy")
							{
								this->Deck.top().isFlipped = true;
								this->withdrawnDeck.push_back(this->Deck.top());
								for (int z = withdrawnDeck.size() - 1, count = 1; z >= 0; z--, count++)
								{
									if (count == 1)
										this->withdrawnDeck[z].setPosition(this->Deck.top().position.x - (count * 100), this->Deck.top().position.y);
									else if (count == 2)
										this->withdrawnDeck[z].setPosition(this->Deck.top().position.x - (count * 70), this->Deck.top().position.y);
									else if (count == 3)
										this->withdrawnDeck[z].setPosition(this->Deck.top().position.x - (count * 60), this->Deck.top().position.y);
									if (count == 3)
										break;
								}
								this->Deck.pop();

							}
							else if (gameMode == "Hard")
							{
								for (int i = 0; i < 3; i++)
								{
									if (!this->Deck.empty())
									{
										this->Deck.top().isFlipped = true;
										this->withdrawnDeck.push_back(this->Deck.top());
										this->Deck.pop();
			
									}
								}
									
								for (int z = withdrawnDeck.size() - 1, count = 1; z >= 0; z--, count++)
								{
									if (count == 1)
										this->withdrawnDeck[z].setPosition(1238 - (count * 100), 1);
									else if (count == 2)
										this->withdrawnDeck[z].setPosition(1238 - (count * 70), 1);
									else if (count == 3)
										this->withdrawnDeck[z].setPosition(1238 - (count * 60), 1);
									if (count == 3)
										break;
								}
								
							}
						}
					}
					else if ((static_cast<float>(mousePosition.x) > 1240 && static_cast<float>(mousePosition.x) < 1325) && (static_cast<float>(mousePosition.y) > 1 && static_cast<float>(mousePosition.y) < 740))
					{
						saveBoardState();
							while (!withdrawnDeck.empty())
							{
								this->Deck.push(withdrawnDeck.front());
								this->Deck.top().isFlipped = false;
								this->Deck.top().setPosition(1238, 1);
								withdrawnDeck.pop_front();
							}
							changeHappen = true;
					}
					

					if (!this->withdrawnDeck.empty())
					{
						if (withdrawnDeck.back().frontImage.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
						{
							saveBoardState();
							currentCard = &withdrawnDeck.back();
							originalPosition = withdrawnDeck.back().position;
							isSpriteSelected = true;
							sourcePileIndex = -2;

							selectedCards.clear();
							originalPositions.clear();
							originalPositions.push_back(withdrawnDeck.back().position);
							selectedCards.push_back(currentCard);
						}
						changeHappen = true;
					}
				}
			}
			if (evnt.type == sf::Event::MouseButtonReleased)
			{
				if (evnt.mouseButton.button == sf::Mouse::Left)
				{
					if (isSpriteSelected)
					{
						cardPlacingSound.play();
						isSpriteSelected = false;
						sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
						bool isPositionChanged = false;
						Card* tempCard = nullptr;
						
						if ((static_cast<float>(mousePosition.x) > 48 && static_cast<float>(mousePosition.x) < 134) && (static_cast<float>(mousePosition.y) > 142 && static_cast<float>(mousePosition.y) < 740))
						{	
							this->addToPile(currentCard, tempCard, selectedCards, sourcePileIndex, 0, isPositionChanged, changeHappen);
						}
						else if ((static_cast<float>(mousePosition.x) > 205 && static_cast<float>(mousePosition.x) < 295) && (static_cast<float>(mousePosition.y) > 142 && static_cast<float>(mousePosition.y) < 740))
						{
							this->addToPile(currentCard, tempCard, selectedCards, sourcePileIndex, 1, isPositionChanged, changeHappen);
						}
						else if ((static_cast<float>(mousePosition.x) > 360 && static_cast<float>(mousePosition.x) < 450) && (static_cast<float>(mousePosition.y) > 142 && static_cast<float>(mousePosition.y) < 740))
						{
							this->addToPile(currentCard, tempCard, selectedCards, sourcePileIndex, 2, isPositionChanged, changeHappen);
						}
						else if ((static_cast<float>(mousePosition.x) > 520 && static_cast<float>(mousePosition.x) < 605) && (static_cast<float>(mousePosition.y) > 142 && static_cast<float>(mousePosition.y) < 740))
						{
							this->addToPile(currentCard, tempCard, selectedCards, sourcePileIndex, 3, isPositionChanged, changeHappen);
						}
						else if ((static_cast<float>(mousePosition.x) > 680 && static_cast<float>(mousePosition.x) < 765) && (static_cast<float>(mousePosition.y) > 142 && static_cast<float>(mousePosition.y) < 740))
						{
							this->addToPile(currentCard, tempCard, selectedCards, sourcePileIndex, 4, isPositionChanged, changeHappen);
						}
						else if ((static_cast<float>(mousePosition.x) > 840 && static_cast<float>(mousePosition.x) < 925) && (static_cast<float>(mousePosition.y) > 142 && static_cast<float>(mousePosition.y) < 740))
						{
							this->addToPile(currentCard, tempCard, selectedCards, sourcePileIndex, 5, isPositionChanged, changeHappen);
						}
						else if ((static_cast<float>(mousePosition.x) > 1000 && static_cast<float>(mousePosition.x) < 1090) && (static_cast<float>(mousePosition.y) > 142 && static_cast<float>(mousePosition.y) < 740))
						{
							this->addToPile(currentCard, tempCard, selectedCards, sourcePileIndex, 6, isPositionChanged, changeHappen);
						}
						else if ((static_cast<float>(mousePosition.x) > 45 && static_cast<float>(mousePosition.x) < 610) && (static_cast<float>(mousePosition.y) > 1 && static_cast<float>(mousePosition.y) < 120) && selectedCards.size() == 1)
						{
							changeHappen = true;
							int insertionIndex = this->Home.insertionIndex(selectedCards[0]);
							if (this->Home.canInsert(selectedCards[0], insertionIndex))
							{
								this->score += 10;
								this->Home.insert(selectedCards[0], insertionIndex);
								isPositionChanged = true;

								if (sourcePileIndex >= 0)
									this->piles[sourcePileIndex].cards.erase(
										this->piles[sourcePileIndex].cards.end() - selectedCards.size(),
										this->piles[sourcePileIndex].cards.end()
									);
								else if (sourcePileIndex == -2)
									withdrawnDeck.pop_back();

								if (this->Home.checkIfComplete())
								{
									this->userwon = true;
									endTime = clock.restart().asSeconds();
									cout << "------------------YOU WIN----------------------" << endl;
								}
							}
						}



						if (!isPositionChanged)
						{
							currentCard->setPosition(originalPosition);
							for (int i = 0; i < selectedCards.size(); i++)
							{
								selectedCards[i]->setPosition(originalPositions[i]);
							}
						}
						if (sourcePileIndex >= 0)
						if (this->piles[sourcePileIndex].cards.size() > 0) 
						{
							this->piles[sourcePileIndex].cards.back().isFlipped = true;
						}
						
					}

					
				}
			}
		}

		if (isSpriteSelected && !selectedCards.empty())
		{
			sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
			sf::Vector2f basePosition(static_cast<float>(mousePosition.x) - 50, static_cast<float>(mousePosition.y) - 65);

			for (int i = 0; i < selectedCards.size(); i++) 
			{
				selectedCards[i]->setPosition(basePosition.x, basePosition.y + (i * 42));
			}
		}
		float dt = clock.restart().asSeconds(); 

		if (this->userwon)
		{
			for(int i = 0; i < 10; i++)
				fireworks.push_back(Firework(sf::Vector2f(rand() % WINDOW_WIDTH, rand() % WINDOW_HEIGHT)));
			userwon = false;  
			count++;
		}
		timeElapsed = Time.getElapsedTime();
		int totalSeconds = timeElapsed.asSeconds();
		// Convert seconds to minutes and seconds
		int minutes = totalSeconds / 60;
		int seconds = totalSeconds % 60;

		// Format the time as "MM:SS"
		std::stringstream timeStream;
		timeStream << "Time: " << setw(2) << setfill('0') << minutes << ":"
			<< setw(2) << setfill('0') << seconds;

		// Set the formatted string to the time display
		TimeText.setString(timeStream.str());
		scoreString = "Score: " + to_string(this->score);
		this->scoreText.setString(scoreString);
		window->clear(sf::Color::Cyan);
		window->draw(this->backgroundImage);
		if(!this->Deck.empty())
			window->draw(this->Deck.top().backImage);
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < this->piles[i].cards.size(); j++)
			{
				if(this->piles[i].cards[j].isFlipped)
					window->draw(this->piles[i].cards[j].frontImage);
				else
					window->draw(this->piles[i].cards[j].backImage);
			}
		}
		for (int i = max(0, static_cast<int>(withdrawnDeck.size()) - 4); i < withdrawnDeck.size(); i++)
		{
			if(i >= 0)
				window->draw(withdrawnDeck[i].frontImage);
		}
		for (int i = 0; i < 4; i++)
		{
			if(!this->Home.foundationPiles[i].empty())
				window->draw(this->Home.foundationPiles[i].top().frontImage);
		}
		if (count == 1)
		{
			for (auto& firework : fireworks) {
				firework.update(dt);
			}

			fireworks.erase(std::remove_if(fireworks.begin(), fireworks.end(),
				[](Firework& f) { return f.isFinished(); }), fireworks.end());
			for (auto& firework : fireworks) {
				firework.draw(*window);
			}
			window->draw(winText);
			if (endClock.getElapsedTime().asSeconds() > 7.0)
				window->close();
		}
		window->draw(this->scoreText);
		window->draw(this->TimeText);
		window->display();
	}
}



void Board::saveBoardState()
{
	undoStack.push(*this);
	while (!redoStack.empty()) redoStack.pop(); 
}


void Board::undoMove()
{
	if (!undoStack.empty()) {
		redoStack.push(*this);
		*this = undoStack.top(); 
		undoStack.pop();
		score -= 5;
	}
}


void Board::redoMove()
{
	if (!redoStack.empty()) {
		undoStack.push(*this);
		*this = redoStack.top();
		redoStack.pop();
	}
}