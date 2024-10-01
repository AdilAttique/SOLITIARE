#include "Board.h"

Board::Board()
{
	background.loadFromFile("Background.png");
	this->backgroundImage.setTexture(background);
}

void Board::shuffle(Card* Array[])
{
	srand(time(0));

	for (int i = 51; i > 0; i--)
	{
		int j = rand() % (i + 1);

		Card* tempCard = Array[i];
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
	Card* temp[52]{};
	string filepathFront;
	int rank;

	for (int i = 0, code = 1; i < 13; i++, code+=4)
	{	
		filepathFront = to_string(code) += ".png";
		cout << i << endl;
		if (i == 0)
			rank = 1;
		else
			rank = 13 - i + 1;
		temp[i] = new Club(filepathFront, "back.png", rank, 'C');
	}

	for (int i = 13, code = 2; i < 26; i++, code += 4)
	{
		filepathFront = to_string(code) += ".png";
		cout << i << endl;
		if (i == 0)
			rank = 1;
		else
			rank = 13 - i + 1;
		temp[i] = new Spade(filepathFront, "back.png", rank, 'S');
	}

	for (int i = 26, code = 3; i < 39; i++, code += 4)
	{
		filepathFront = to_string(code) += ".png";
		cout << i << endl;
		if (i == 0)
			rank = 1;
		else
			rank = 13 - i + 1;
		temp[i] = new Heart(filepathFront, "back.png", rank, 'H');
	}

	for (int i = 39, code = 4; i < 52; i++, code += 4)
	{
		filepathFront = to_string(code) += ".png";
		cout << i << endl;
		if (i == 0)
			rank = 1;
		else
			rank = 13 - i + 1;
		temp[i] = new Diamond(filepathFront, "back.png", rank, 'D');
	}

	this->shuffle(temp);

	// 
	/*for (int i = 0; i < 52; i++)
	{
		temp[i]->frontImage.setScale(0.03, 0.03);
		temp[i]->frontImage.setPosition(10, 20);
		cout << temp[i]->frontImage.getPosition().x << endl;
		this->Deck.push(temp[i]);
	}*/
	//temp[0] = new Club("1.png", backImage, 1, 'C');
	//temp[1] = new Club("5.png", backImage, 13, 'C');
	//temp[2] = new Club("9.png", backImage, 12, 'C');
	//temp[3] = new Club("13.png", backImage, 11, 'C');
	//temp[4] = new Club("17.png", backImage, 10, 'C');
	//temp[5] = new Club("21.png", backImage, 9, 'C');
	//temp[6] = new Club("25.png", backImage, 8, 'C');
	//temp[7] = new Club("29.png", backImage, 7, 'C');
	//temp[8] = new Club("33.png", backImage, 6, 'C');
	//temp[9] = new Club("37.png", backImage, 5, 'C');
	//temp[10] = new Club("41.png", backImage, 4, 'C');
	//temp[11] = new Club("45.png", backImage, 3, 'C');
	//temp[12] = new Club("49.png", backImage, 2, 'C');
	//temp[13] = new Spade("2.png", backImage, 1, 'S');
	//temp[14] = new Spade("6.png", backImage, 13, 'S');
	//temp[15] = new Spade("10.png", backImage, 12, 'S');
	//temp[16] = new Spade("14.png", backImage, 11, 'S');
	//temp[17] = new Spade("18.png", backImage, 10, 'S');
	//temp[18] = new Spade("22.png", backImage, 9, 'S');
	//temp[19] = new Spade("26.png", backImage, 8, 'S');
	//temp[20] = new Spade("30.png", backImage, 7, 'S');
	//temp[21] = new Spade("34.png", backImage, 6, 'S');
	//temp[22] = new Spade("38.png", backImage, 5, 'S');
	//temp[23] = new Spade("42.png", backImage, 4, 'S');
	//temp[24] = new Spade("46.png", backImage, 3, 'S');
	//temp[25] = new Spade("50.png", backImage, 2, 'S');
	//temp[26] = new Heart("3.png", backImage, 1, 'H');
	//temp[27] = new Heart("7.png", backImage, 13, 'H');
	//temp[28] = new Heart("11.png", backImage, 12, 'H');
	//temp[29] = new Heart("15.png", backImage, 11, 'H');
	//temp[30] = new Heart("19.png", backImage, 10, 'H');
	//temp[31] = new Heart("23.png", backImage, 9, 'H');
	//temp[32] = new Heart("27.png", backImage, 8, 'H');
	//temp[33] = new Heart("31.png", backImage, 7, 'H');
	//temp[34] = new Heart("35.png", backImage, 6, 'H');
	//temp[35] = new Heart("39.png", backImage, 5, 'H');
	//temp[36] = new Heart("43.png", backImage, 4, 'H');
	//temp[37] = new Heart("47.png", backImage, 3, 'H');
	//temp[38] = new Heart("51.png", backImage, 2, 'H');
	//temp[39] = new Diamond("4.png", backImage, 1, 'D');
	//temp[40] = new Diamond("8.png", backImage, 13, 'D');
	//temp[41] = new Diamond("12.png", backImage, 12, 'D');
	//temp[42] = new Diamond("16.png", backImage, 11, 'D');
	//temp[43] = new Diamond("20.png", backImage, 10, 'D');
	//temp[44] = new Diamond("24.png", backImage, 9, 'D');
	//temp[45] = new Diamond("28.png", backImage, 8, 'D');
	//temp[46] = new Diamond("32.png", backImage, 7, 'D');
	//temp[47] = new Diamond("36.png", backImage, 6, 'D');
	//temp[48] = new Diamond("40.png", backImage, 5, 'D');
	//temp[49] = new Diamond("44.png", backImage, 4, 'D');
	//temp[50] = new Diamond("48.png", backImage, 3, 'D');
	//temp[51] = new Diamond("52.png", backImage, 2, 'D');


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
		tempPosition.y = 186;

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


		vector<Card*> tempVector(i + 1);
		for (int j = 0; j <= i; j++)
		{
			if (j != 0)
				tempPosition.y += 42;
			tempVector[j] = this->Deck.top();
			tempVector[j]->setPosition(tempPosition);
			if (j == i)
				tempVector[j]->isFlipped = true;
			this->Deck.pop();
		}
		MyStack tempMyStack(tempVector, 1, i, i + 1);
		this->piles.push_back(tempMyStack);
	}
}


void Board::initializeFoundations()
{

}

void Board::Play()
{
	//sf::Texture test;
	//test.loadFromFile("1.png");
	//sf::Sprite TEST(test);
	//TEST.setScale(0.03, 0.03);
	//TEST.setPosition(48, 15);
	bool isSpriteSelected = false;;
	bool deagCard = false;
	float max_x = 500;
	Card* currentCard = nullptr;
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
					for (int i = 0; i < 7; i++)
					{
						for (int j = 0; j < this->piles[i].size; j++)
						{
							// Check if the mouse click is inside the sprite
							sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
							if (this->piles[i].cards[j]->frontImage.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
							{
								currentCard = this->piles[i].cards[j];
								isSpriteSelected = true;
							}
						}
					}
					
					
				}
				else if (evnt.mouseButton.button == sf::Mouse::Right)
				{
					deagCard = true;
				}
			}
			if (evnt.type == sf::Event::MouseButtonReleased)
			{
				if (evnt.mouseButton.button == sf::Mouse::Left)
				{
					isSpriteSelected = false;
				}
			}
		}

		if (isSpriteSelected && currentCard != nullptr)
		{
			sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
			currentCard->frontImage.setPosition(static_cast<float>(mousePosition.x) - 50, static_cast<float>(mousePosition.y) - 65);
			currentCard->backImage.setPosition(static_cast<float>(mousePosition.x) - 50, static_cast<float>(mousePosition.y) - 65);
		}
		if (deagCard)
		{
			sf::Vector2f position = currentCard->frontImage.getPosition();
			position.x += 5;
			currentCard->setPosition(position);
			if (position.x >= max_x)
				deagCard = false;
		}

		window->clear(sf::Color::Red);
		
		window->draw(this->backgroundImage);
		window->draw(this->Deck.top()->backImage);
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < this->piles[i].size; j++)
			{
				if(this->piles[i].cards[j]->isFlipped)
					window->draw(this->piles[i].cards[j]->frontImage);
				else
					window->draw(this->piles[i].cards[j]->backImage);
			}
		}
		//window->draw(TEST);
		window->display();
	}
}



//{

	//sf::RenderWindow window(sf::VideoMode(1375, 696), " Tut SFML", sf::Style::Close | sf::Style::Resize);
	//window.setPosition(Vector2i(-10, 0));
	//Texture B;
	//B.loadFromFile("Ace_spades.png");

	//Sprite Card(B);
	//Card.setPosition(100, 50);
	//Texture C;

	//Texture A;
	//A.loadFromFile("background.jpg");

	//Sprite Backg(A);
	//Backg.setPosition(0, -80);
	//Font Lato;
	//Lato.loadFromFile("Lato.ttf");

	//Text NG("NEW GAME", Lato, 50);
	//NG.setPosition(540, 60);
	//NG.setFillColor(sf::Color::White);
	//Text LG("LOAD GAME", Lato, 50);
	//LG.setPosition(535, 170);
	//LG.setFillColor(sf::Color::White);
//	bool isSpriteSelected = false;;
//	bool deagCard = false;
//	float max_x = 500;
//	//--------------
//	while (window.isOpen())
//	{
//		sf::Event evnt;
//
//		while (window.pollEvent(evnt))
//		{
//			if (evnt.type == sf::Event::Closed)
//				window.close();
//
//			if (evnt.type == sf::Event::MouseButtonPressed)
//			{
//				if (evnt.mouseButton.button == sf::Mouse::Left)
//				{
//
//					// Check if the mouse click is inside the sprite
//					sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
//					if (Card.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
//					{
//						isSpriteSelected = true;
//					}
//				}
//				else if (evnt.mouseButton.button == sf::Mouse::Right)
//				{
//					deagCard = true;
//				}
//			}
//			if (evnt.type == sf::Event::MouseButtonReleased)
//			{
//				if (evnt.mouseButton.button == sf::Mouse::Left)
//				{
//					isSpriteSelected = false;
//				}
//			}
//		}
//
//		if (isSpriteSelected)
//		{
//			sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
//			Card.setPosition(static_cast<float>(mousePosition.x) - 50, static_cast<float>(mousePosition.y) - 65);
//		}
//		if (deagCard)
//		{
//			sf::Vector2f position = Card.getPosition();
//			position.x += 5;
//			Card.setPosition(position);
//			if (position.x >= max_x)
//				deagCard = false;
//		}
//		window.clear();
//		window.draw(Backg);
//		window.draw(Card);
//		window.display();
//	}
//
//	return 0;
//}