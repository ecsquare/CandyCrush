#ifndef GAME_H
#define GAME_H
#include "SFML/Graphics.hpp"
#include <time.h>
#include <SFML/Graphics/Text.hpp>


class Game
{
public:
    //les methodes publiques
    Game();
    void run();
    void quit();
    int sc=0;

private:
    //les attribus privés
    struct piece
        { int x,y,col,row,kind,match,alpha;
            piece()
            {match=0;
             alpha=255;}
        }
         grid[10][10];
    sf::RenderWindow app;
    int ts = 54; //taille d'un carreau

    sf::Vector2i offset = sf::Vector2i(48,24);//la position des bonbons par rapport à la fenetre ouverte
    sf::Vector2i pos;

        sf::Texture t1,t2,t3;
        int x0,y0,x,y;
        int click=0;
        bool isSwap=false, isMoving=false , special=false;;
        int max=10;

   //les methodes privés
    void processEvents();
    void update();
    void render();
    void swap(piece p1,piece p2);
    int NoMoreMoves( piece grid[10][10]);


    };
#endif // GAME_H
