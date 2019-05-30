#ifndef CANDY_H
#define CANDY_H
#include <iostream>
using namespace std;


class candy
{
    public:
        candy(char,char,bool);
        friend bool operator==(candy c,candy b);
        friend ostream& operator << (ostream& O, const candy& B);
        friend bool hasSameorientation(candy b,candy c);

    protected:

    private:
        char orientation;
        char nature;
        bool specialOrNot;
        int nombreBon;
};

#endif // CANDY_H
