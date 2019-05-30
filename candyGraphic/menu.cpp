#include "Menu.h"


Menu::Menu(float width, float height)//constructeur de menu
{

	if (!font.loadFromFile("arial.ttf"))
	{}

	menu[0].setFont(font);//réglage du font
	menu[0].setColor(sf::Color::Red);//réglage de couleur
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_num + 1) * 1));//réglage de position

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Exit");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_num + 1) * 3));

	selectedItemIndex = 0;//variable qui manipule le choix de l'utilisateur
}


Menu::~Menu()//destructeur
{}

void Menu::draw(sf::RenderWindow &window)//affichage de menu
{
	for (int i = 0; i < MAX_num; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()//si on tape le fleche vers le haut de clavier
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);//le mot non selectionné sera en blanc
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Red);//le mot selectionné sera en rouge
	}
}

void Menu::MoveDown()//si on tape le fleche vers le bas du clavier
{
	if (selectedItemIndex + 1 < MAX_num)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);//le mot non sélectionné sera coloré en blanc
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Blue);//le mot selectionné sera en bleu
	}
}
