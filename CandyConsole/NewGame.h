#ifndef NEWGAME_H
#define NEWGAME_H
#include"timing.h"

class NewGame
{
    public:
        NewGame(int,int,int);
        int NoMoreMoves();
        void shuffleBoard();
        void afficheBoard(int t,int sc,int k);
        void  makeMove(int,int,int,int,int);
        void TripleRemove();
        void FourRemove();
        void Mremove();
        void Lremove();
        void Tremove();
        void removeMUsed();
        void action(int);
        void dropDown();
        bool checkAbove();
        void fillEmpty();
        char returnSpE(char,char,int);
        char OriginCandy(char );
        void usageLTremove();
        int getter_score();
        int verifHV(char);
        void remove4used();
        int elimin(char a);
        bool StillmoreToBlow();
        void permut(int,int,int,int);
        bool verif(int,int,int,int);
        bool hasBro(int,int);
        int getter_moves();


    protected:

    private:
        int winScore;
        int MaxMoves;
        int level;
        char board[8][8];
        int score=0;

};

#endif // NEWGAME_H
