#include <SFML/Graphics.hpp>
#include <time.h>
#include "Game.h"
#include <string>
#include "SFML/Window.hpp"
#include <iostream>
#include <SFML/Audio.hpp>

Game::Game():app(sf::VideoMode(740,480), "candy crash" )//création d'une fenetre
{

    app.setFramerateLimit(60);//limiter le nombre de frames à 60 frames par secondes (optionnelle).
    //l'initialisation de la grille

	for (int i=1;i<=8;i++)
     for (int j=1;j<=8;j++)
      {
          grid[i][j].kind=rand()%7;//générer des bonbons aléatoirement
          grid[i][j].col=j;// la colonne
          grid[i][j].row=i;//la ligne
          grid[i][j].x = j*ts;//l'abscisse de la piéce
          grid[i][j].y = i*ts;//l'ordonné de la piéce
      }
}

void Game::swap(piece p1,piece p2)//la méthode "swap" pour échanger deux piéces
{
  int aux1=p1.row;
  p1.row=p2.row;
  p2.row=aux1;
  int aux2=p1.col;
  p1.col=p2.col;
  p2.col=aux2;
  grid[p1.row][p1.col]=p1;
  grid[p2.row][p2.col]=p2;

}


int Game::NoMoreMoves( piece grid[10][10])//la methode qui indique s'il n y'a pas d'autres combinaisons possibles
   {
    int i,j;
    //Traitement sur les linges
    for (i=1;i<=8;i++)
        for(j=1;j<=7;j++){
        if (grid[i][j].kind==grid[i][j+1].kind){  //Couple trouvé
                //Au dessus
                if (i!=1){
                          if (j!=1){
                                    if (grid[i-1][j-1].kind==grid[i][j].kind)
                                     return 0; //pas de blocage
                          }
                          if (j+2<=8){
                                    if (grid[i-1][j+2].kind==grid[i][j].kind)
                                    return 0; //pas de blocage
                          }
                }
                //Dans la même ligne
                if (j-2>0){
                          if (grid[i][j-2].kind==grid[i][j].kind)
                          return 0; //pas de blocage
                }
                if (j+3<=8){
                          if (grid[i][j+3].kind==grid[i][j].kind)
                          return 0; //pas de blocage
                }
                //Au dessous
                if (i+1<=8){
                          if (j+1<=8){
                                      if (grid[i+1][j+1].kind==grid[i][j].kind)
                                       return 0; //pas de blocage
                          }
                          if (j+2<=8){
                                      if (grid[i+1][j+2].kind==grid[i][j].kind)
                                       return 0; //pas de blocage
                          }
                }
        }
    }
    //Traitement pour les colonnes
    for (i=1;i<8;i++)
     for(j=1;j<=8;j++){
        if (grid[i][j].kind==grid[i+1][j].kind){  //Couple trouvé
                //Au dessus
                if (j!=1){
                          if (i!=1){
                                    if (grid[i-1][j-1].kind==grid[i][j].kind)
                                    return 0; //pas de blocage
                          }
                          if (i+2<=8){
                                    if (grid[i+2][j-1].kind==grid[i][j].kind)
                                    return 0; //pas de blocage
                          }
                }
                //Dans la même ligne
                if (i-2>=1){
                          if (grid[i-2][j].kind==grid[i][j].kind)
                           return 0; //pas de blocage
                }
                if (i+3<=8){
                          if (grid[i+3][j].kind==grid[i][j].kind)
                          return 0; //pas de blocage
                }
                //Au dessous
                if (j+1<=8){
                          if (i+1<=8){
                                      if (grid[i+1][j+1].kind==grid[i][j].kind)
                                      return 0; //pas de blocage
                          }
                          if (i+2<=8){
                                      if (grid[i+2][j+1].kind==grid[i][j].kind)
                                       return 0; //pas de blocage
                          }
                }
        }
    }
    //Bloquage
    return 1;
}

void Game::processEvents()
{
     sf::Event e;
        while (app.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)//si on clique sur le croix la fenétre disparait de l'écran
                app.close();
            // detection des clics de souris
			if (e.type == sf::Event::MouseButtonPressed)
				if (e.key.code == sf::Mouse::Left)
				{
				   if (!isSwap && !isMoving) click++;
				   pos = sf::Mouse::getPosition(app)-offset;//pos contient la position de  clic gauche de la souris
                }
         }

   //création de l'animation
   isMoving=false;//variable booléenne indique s'il y'a un mouvement ou pas
   for (int i=1;i<=8;i++)
    for (int j=1;j<=8;j++)
     {
       piece &p = grid[i][j];
       int dx,dy;
       for(int n=0;n<4;n++)   // n indique la vitesse de mouvement
       {dx = p.x-p.col*ts;
        dy = p.y-p.row*ts;
        if (dx) p.x-=dx/abs(dx);
	    if (dy) p.y-=dy/abs(dy);}
       if (dx||dy) isMoving=1;
     }

   //suppression de l'amimation
  if (!isMoving)
    for (int i=1;i<=8;i++)
    for (int j=1;j<=8;j++)
    if (grid[i][j].match)
        if (grid[i][j].alpha>10)
         {grid[i][j].alpha-=10;
          isMoving=true;}

// declaration de variable somme qui aide à faire la deuxiéme swap
   int somme=0;
   for (int i=1;i<=8;i++)
    for (int j=1;j<=8;j++)
      somme+=grid[i][j].match;

   //la deuxieme swap si ce n'est pas la bonne combinaison
   if (isSwap && !isMoving)
     {if (somme==0)
     if(special==false)
       swap(grid[y0][x0],grid[y][x]);
        isSwap=0;
        special=false;
       }

    //no more moves (met à jour la grille s'il n y'a pas d'autres combinaisons)
     int l=0;
     int a=NoMoreMoves(grid);
     if (a==1)
     {
         for(int i=1;i<=8;i++)
       for(int j=8;j>0;j--)
           {
            grid[i][j].kind = rand()%7;
            grid[i][j].y = -ts*l++;
            grid[i][j].match=0;
			grid[i][j].alpha = 255;
           }
     }
}

void Game::update() //la mise à jour de la grille
{
     if (!isMoving)
    { //toute case vide est remplacée par le contenu de la case au-dessus d’elle,
      for(int i=8;i>0;i--)
       for(int j=1;j<=8;j++)
         if (grid[i][j].match)
         for(int n=i;n>0;n--)
            if (!grid[n][j].match)
                {swap(grid[n][j],grid[i][j]); break;};
    //Les cases vides de la ligne la plus haute de la grille sont remplacées par des bonbons insérés aléatoirement.
      for(int j=1;j<=8;j++)
       for(int i=8,n=0;i>0;i--)
         if (grid[i][j].match)
           {
            grid[i][j].kind = rand()%7;
            grid[i][j].y = -ts*n++;
            grid[i][j].match=0;
			grid[i][j].alpha = 255;
           }
     }

}

void Game::render()
{
    //declaration de la variable max qui definit le maximum de combinaisons possible
     sf::Font f;
        f.loadFromFile("arial.ttf");
        sf::Text aff("10",f,25);
        aff.setStyle(sf::Text::Bold);
        aff.setFillColor(sf::Color::White);
        aff.setPosition(1100/2.0,500/2.0);

    //les clics de souris
        if (click==1)
    {
      x0=pos.x/ts+1;
      y0=pos.y/ts+1;
    }
   if (click==2)
    {
      x=pos.x/ts+1;
      y=pos.y/ts+1;
      if (abs(x-x0)+abs(y-y0)==1)//savoir si les deux piéces a échanger sont adjascents
        {swap(grid[y0][x0],grid[y][x]);
        isSwap=1;
        click=0;
        max--;
        }
      else
        {click=1;}
    }
        aff.setString(std::to_string(max));

        //declaration de score
        sf::Font font;
        font.loadFromFile("arial.ttf");
        sf::Text text("0", font);
        text.setCharacterSize(30);
        text.setStyle(sf::Text::Bold);
        text.setFillColor(sf::Color::White);
        text.setPosition(1300/2.0,800/2.0);

         text.setString(std::to_string(sc));
   //éliminer des bonbons d’une grille de jeu en combinant de 3 à 5 bonbons de même catégorie
   for(int i=1;i<=8;i++)
    for(int j=1;j<=8;j++)
   {
    //combinaison de 3 bonbons verticale
    if ((grid[i][j].kind==grid[i+1][j].kind)&&(grid[i][j].kind==grid[i-1][j].kind))
    {
        special=false;
        if(isMoving==false)
            sc+=10;
     for(int n=-1;n<=1;n++)
     {grid[i+n][j].match++;}}
     //combinaison de 3 bonbons horizontale
    if ((grid[i][j].kind==grid[i][j+1].kind)&&(grid[i][j].kind==grid[i][j-1].kind))
      {
        special=false;
        if(isMoving==false)
            sc+=10;
     for(int n=-1;n<=1;n++)
        grid[i][j+n].match++;}
    //combinaison de 4 bonbons verticale
        for(int i=1;i+3<=8;i++)
            for(int j=1;j<=8;j++)
                {
            if ((grid[i][j].kind==grid[i+1][j].kind)&&(grid[i][j].kind==grid[i+2][j].kind)&&(grid[i][j].kind==grid[i+3][j].kind)&&(grid[i][j].kind!=grid[i+4][j].kind)&&(grid[i][j].kind!=grid[i-1][j].kind))
                {int l=0;
                if(isMoving==false)
                    sc+=25;
                special=true;
                std::cout<<"4 bonbons lalala"<<std::endl;
                //nej.setPosition(grid[i][j].x-0.8,grid[i][j].y-0.8);
                for(int n=1;n<=8;n++)
                    {
                    grid[n][j].kind = rand()%7;
                    grid[n][j].y = -ts*l++;
                    grid[n][j].match=0;
                    grid[n][j].alpha = 255;}
                    }};
    //combinaison de 4 bonbons horizontale
        for(int i=1;i<=8;i++)
            for(int j=1;j+3<=8;j++)
                {
            if((grid[i][j].kind==grid[i][j+1].kind)&&(grid[i][j].kind==grid[i][j+2].kind)&&(grid[i][j].kind==grid[i][j+3].kind)&&(grid[i][j].kind!=grid[i][j+4].kind)&&(grid[i][j].kind!=grid[i][j-1].kind))
                {
                int l=0;
                if(isMoving==false)
                    sc+=25;
                special=true;
                std::cout<<"4 bonbons lalala"<<std::endl;
                //nej.setPosition(grid[i][j].x-0.8, grid[i][j].y-0.8);
                for(int n=1;n<=8;n++)
                {
                    grid[i][n].kind = rand()%7;
                    grid[i][n].y = -ts*l++;
                    grid[i][n].match=0;
                    grid[i][n].alpha = 255;}
                }
                }
     //Combinaison de 5 bonbons
    for(int i=1;i+4<=8;i++)
     for(int j=1;j<=8;j++)
    {
        //combinaison verticale
    if((grid[i][j].kind==grid[i+1][j].kind)&&(grid[i][j].kind==grid[i+2][j].kind)&&(grid[i][j].kind==grid[i+3][j].kind)&&(grid[i][j].kind==grid[i+4][j].kind))
       {int l=0;
        special=true;
        if(isMoving==false)
                    sc+=30;
        std::cout<<"5 bonbons hahaha"<<std::endl;
        piece pp=grid[i][j];
        for(int n=1;n<=8;n++)//éliminer les autres bonbons dans la grille ayant la meme catégorie
          for(int m=1;m<=8;m++)
          {

              if (grid[n][m].kind==pp.kind)
              {grid[n][m].kind = rand()%7;
             grid[n][m].y = -ts*l++;
             grid[n][m].match=0;
			 grid[n][m].alpha = 255;

              }
          }
       }
    }
       for(int i=1;i<=8;i++)
    for(int j=1;j+4<=8;j++)
    {
        //combinaison horizontale
       if((grid[i][j].kind==grid[i][j+1].kind)&&(grid[i][j].kind==grid[i][j+2].kind)&&(grid[i][j].kind==grid[i][j+3].kind)&&(grid[i][j].kind==grid[i][j+4].kind))
       {
        special=true;
        if(isMoving==false)
                sc+=30;
         int l=0;
        std::cout<<"5 bonbons hahaha"<<std::endl;
        piece pp=grid[i][j];
        for(int n=1;n<=8;n++) //éliminer les autres bonbons dans la grille ayant la meme catégorie
          for(int m=1;m<=8;m++)
          {

              if (grid[n][m].kind==pp.kind)
              {grid[n][m].kind = rand()%7;
             grid[n][m].y = -ts*l++;
             grid[n][m].match=0;
			 grid[n][m].alpha = 255;

              }
          }
           }
    }
			//combinaison de la lettre L de bonbons
       if((grid[i][j].kind==grid[i+1][j].kind)&&(grid[i][j].kind==grid[i+2][j].kind)&&(grid[i][j].kind==grid[i][j+1].kind)&&(grid[i][j].kind==grid[i][j+2].kind))
        {   int l=0;
            special=true;
            if(isMoving==false)
                    sc+=25;
            for(int n=i;n<=i+2;n++)//eliminer tous le carré de bonbons
                for(int m=j;m<=j+2;m++)
            {
               grid[n][m].kind = rand()%7;
             grid[n][m].y = -ts*l++;
             grid[n][m].match=0;
			 grid[n][m].alpha = 255;};
            }
        if((grid[i][j].kind==grid[i+1][j].kind)&&(grid[i][j].kind==grid[i+2][j].kind)&&(grid[i][j].kind==grid[i][j-1].kind)&&(grid[i][j].kind==grid[i][j-2].kind))
        {   int l=0;
            special=true;
            if(isMoving==false)
                    sc+=25;
            for(int n=i;n<=i+2;n++)//eliminer tous le carré de bonbons
                for(int m=j-2;m<=j;m++)
            {
               grid[n][m].kind = rand()%7;
             grid[n][m].y = -ts*l++;
             grid[n][m].match=0;
			 grid[n][m].alpha = 255;};
        }
        if((grid[i][j].kind==grid[i-1][j].kind)&&(grid[i][j].kind==grid[i-2][j].kind)&&(grid[i][j].kind==grid[i][j-1].kind)&&(grid[i][j].kind==grid[i][j-2].kind))
        {   int l=0;
            special=true;
            if(isMoving==false)
                    sc+=25;
            for(int n=i-2;n<=i;n++)//eliminer tous le carré de bonbons
                for(int m=j-2;m<=j;m++)
            {
               grid[n][m].kind = rand()%7;
             grid[n][m].y = -ts*l++;
             grid[n][m].match=0;
			 grid[n][m].alpha = 255;};
            }
        if((grid[i][j].kind==grid[i-1][j].kind)&&(grid[i][j].kind==grid[i-2][j].kind)&&(grid[i][j].kind==grid[i][j+1].kind)&&(grid[i][j].kind==grid[i][j+2].kind))
        {   int l=0;
            special=true;
            if(isMoving==false)
                    sc+=25;
            for(int n=i-2;n<=i;n++)//eliminer tous le carré de bonbons
                for(int m=j;m<=j+2;m++)
            {
               grid[n][m].kind = rand()%7;
             grid[n][m].y = -ts*l++;
             grid[n][m].match=0;
			 grid[n][m].alpha = 255;};
            }

         //la combinaison de la lettre T de bonbons
         if((grid[i][j].kind==grid[i+1][j].kind)&&(grid[i][j].kind==grid[i-1][j].kind)&&(grid[i][j].kind==grid[i][j+1].kind)&&(grid[i][j].kind==grid[i][j+2].kind))
         { int l=0;
         special=true;
         if(isMoving==false)
                    sc+=25;
            for(int n=i-1;n<=i+1;n++)//eliminer tous le carré de bonbons
                for(int m=j;m<=j+2;m++)
            {
               grid[n][m].kind = rand()%7;
             grid[n][m].y = -ts*l++;
             grid[n][m].match=0;
			 grid[n][m].alpha = 255;};
            }
        if((grid[i][j].kind==grid[i+1][j].kind)&&(grid[i][j].kind==grid[i-1][j].kind)&&(grid[i][j].kind==grid[i][j-1].kind)&&(grid[i][j].kind==grid[i][j-2].kind))
         { int l=0;
         special=true;
         if(isMoving==false)
                    sc+=25;
           for(int n=i-1;n<=i+1;n++)//eliminer tous le carré de bonbons
                for(int m=j-2;m<=j;m++)
            {
               grid[n][m].kind = rand()%7;
             grid[n][m].y = -ts*l++;
             grid[n][m].match=0;
			 grid[n][m].alpha = 255;};
            }
        if((grid[i][j].kind==grid[i+1][j].kind)&&(grid[i][j].kind==grid[i+2][j].kind)&&(grid[i][j].kind==grid[i][j-1].kind)&&(grid[i][j].kind==grid[i][j+1].kind))
         { int l=0;
         special=true;
         if(isMoving==false)
                    sc+=25;
           for(int n=i;n<=i+2;n++)//eliminer tous le carré de bonbons
                for(int m=j-1;m<=j+1;m++)
            {
               grid[n][m].kind = rand()%7;
             grid[n][m].y = -ts*l++;
             grid[n][m].match=0;
			 grid[n][m].alpha = 255;};
            }
        if((grid[i][j].kind==grid[i-1][j].kind)&&(grid[i][j].kind==grid[i-2][j].kind)&&(grid[i][j].kind==grid[i][j-1].kind)&&(grid[i][j].kind==grid[i][j+1].kind))
         { int l=0;
         special=true;
         if(isMoving==false)
                    sc+=25;
           for(int n=i-2;n<=i;n++)//eliminer tous le carré de bonbons
                for(int m=j-1;m<=j+1;m++)
            {
               grid[n][m].kind = rand()%7;
             grid[n][m].y = -ts*l++;
             grid[n][m].match=0;
			 grid[n][m].alpha = 255;};
            }
			}
   //déssiner les images
    t1.loadFromFile("zzz.png");
    t2.loadFromFile("gems.png");
    sf::Sprite zzz(t1), gems(t2);
    app.draw(zzz);
	for (int i=1;i<=8;i++)
     for (int j=1;j<=8;j++)
      {
        piece p = grid[i][j];
        gems.setTextureRect( sf::IntRect(p.kind*49,0,49,49));
        gems.setColor(sf::Color(255,255,255,p.alpha));
        gems.setPosition(p.x,p.y);
        gems.move(offset.x-ts,offset.y-ts);
        app.draw(gems);
        app.draw(aff);
        app.draw(text);
      }

     app.display();
}

void Game::run()//lancer le jeu
{
    while (app.isOpen()&&max!=0)
    {
        processEvents();
        update();
        render();
    }

}





