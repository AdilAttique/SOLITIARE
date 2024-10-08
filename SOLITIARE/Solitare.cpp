#include "Solitare.h"

//if (evnt.mouseButton.button == sf::Mouse::Right)
//{
//	float xpos = sf::Mouse::getPosition(window).x;
//	float ypos = sf::Mouse::getPosition(window).y;
//	cout << "X: " << xpos << "  Y: " << ypos << endl;
//
Solitare::Solitare() : window(sf::VideoMode(1366, 760), "Solitaire by Adil", sf::Style::Close | sf::Style::Resize)
{
	startBackgroundTexture.loadFromFile("StartBackground.png");
	startBackgroundImage.setTexture(startBackgroundTexture);
}

void Solitare::Initialize()
{
	this->board.initliazeWindow(&window);
	this->board.intiliazeDeck();
	this->board.initliazePiles();
}

void Solitare::modeSelection()
{
	sf::SoundBuffer buttonClickBuffer;
	buttonClickBuffer.loadFromFile("ButtonClickSound.mp3");
	sf::Sound buttonClickSound;
	buttonClickSound.setBuffer(buttonClickBuffer);
	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed)
			{
				window.close();
			}
			if (evnt.type == sf::Event::MouseButtonPressed)
			{
				sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
				if (evnt.mouseButton.button == sf::Mouse::Left)
				{
					if ((static_cast<float>(mousePosition.x) > 976 && static_cast<float>(mousePosition.x) < 1176) && (static_cast<float>(mousePosition.y) > 442 && static_cast<float>(mousePosition.y) < 506))
					{
						this->gameMode = "Easy";
						buttonClickSound.play();
						sf::sleep(sf::milliseconds(300));
						return;
					}
					else if ((static_cast<float>(mousePosition.x) > 976 && static_cast<float>(mousePosition.x) < 1176) && (static_cast<float>(mousePosition.y) > 555 && static_cast<float>(mousePosition.y) < 617))
					{
						this->gameMode = "Hard";
						buttonClickSound.play();
						sf::sleep(sf::milliseconds(300));
						return;
					}
				}
				if (evnt.mouseButton.button == sf::Mouse::Right)
				{
					float xpos = sf::Mouse::getPosition(window).x;
					float ypos = sf::Mouse::getPosition(window).y;
					cout << "X: " << xpos << "  Y: " << ypos << endl;
				}
			}
		}

		window.clear();
		window.draw(this->startBackgroundImage);
		window.display();
	}
}

void Solitare::startGame()
{
	this->Initialize();
	this->modeSelection();
	this->board.Play(gameMode);
}