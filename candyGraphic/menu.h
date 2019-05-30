#include "SFML/Graphics.hpp"
#define MAX_num 3

class Menu
{
public:
    //les methodes publiques
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }

private:
    //les attribus privés
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_num];

};
