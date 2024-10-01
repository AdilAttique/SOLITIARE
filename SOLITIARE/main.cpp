#include "Solitare.h"
#include <SFML/Graphics.hpp>
using namespace std;
#include <iostream>
using namespace sf;


int main()
{
	Solitare Game;
	Game.startGame();
	return 0;
}

//int main() 
//{
//
//    sf::RenderWindow window(sf::VideoMode(1366, 760), "SFML Test Window", sf::Style::Close | sf::Style::Resize);
//
//    Texture test;
//    test.loadFromFile("Background.png");
//
//    Sprite TEST(test);
//    
//    // Run the program as long as the window is open
//    while (window.isOpen()) {
//
//        sf::Event event;
//        while (window.pollEvent(event)) {
//       
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//
//
//        window.draw(TEST);
//
//        window.display();
//    }
//
//    return 0;
//}