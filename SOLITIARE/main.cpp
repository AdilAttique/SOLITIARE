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
//	for (int i = 0; i < 52; i++)
//	{
//		cout << i << endl;
//		sf::Texture tex;
//		tex.loadFromFile("1.png");
//		sf::Texture bex;
//		bex.loadFromFile("back.png");
//		sf::Sprite Imex;
//		Imex.setTexture(tex);
//		sf::Sprite Bmex;
//		Bmex.setTexture(bex);
//	}
//}
// 
// 
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