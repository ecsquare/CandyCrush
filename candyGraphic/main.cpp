#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Texture.hpp"
#include <iostream>
#include "Menu.h"
#include <time.h>
#include "Game.h"
#include <SFML/Audio.hpp>
using namespace sf;

int main()
{

        //jouer du son
    sf::SoundBuffer soundBuffer;
    soundBuffer.loadFromFile("positive.wav");
    sf::Sound sound;
    sound.setBuffer(soundBuffer);
    sound.play();
        //affichage de fenetre de menu
    sf::RenderWindow window(sf::VideoMode(600, 496), "CLICK PLAY AND LET'S HAVE FUN ^^");//création d'une fenetre
	Menu menu(window.getSize().x, window.getSize().y);//création d'une instance de la classe Menu
	window.setFramerateLimit(60);//limiter le nombre de frames à 60 frames par secondes (optionnelle).
    sf::Texture t1;
    t1.loadFromFile("candy.jpg");//telechargement de l'image
    sf::Sprite candy(t1);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)//gérer les touches de clavier
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						{
						 Game game;
                         game.run();
                         break;}
					case 1:
						{window.close();
						break;}
					}

					break;
				}

				break;
			case sf::Event::Closed:
				window.close();

				break;

			}
		}
        //dessiner les images
		window.clear();
        window.draw(candy);


		menu.draw(window);

		window.display();
	}
}

