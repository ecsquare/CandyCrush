#include "candy.h"
#include <iostream>
using namespace std;

candy::candy(char a,char b,bool s)
{
        nature=a;
        orientation=b;
        specialOrNot=s;
}
ostream& operator << (ostream& out, const candy& c){
        if (c.specialOrNot==true){
            if(c.nombreBon==4){
                    if(c.orientation=='V'){
                        if(c.nature=='$') out<<"~";
                        if(c.nature=='@') out<<"<";
                        if(c.nature=='+') out<<"|";
                        if(c.nature=='%') out<<"/";
                 if(c.orientation=='H')
                        if(c.nature=='$') out<<"s";
                        if(c.nature=='@') out<<"^";
                        if(c.nature=='+') out<<"-";
                        if(c.nature=='%') out<<"\\";
                    }
            }
            else{
                    if(c.nature=='$') out<<"D";
                    if(c.nature=='@') out<<"A";
                    if(c.nature=='+') out<<"P";
                    if(c.nature=='%') out<<"R";
            }
    }
    else
        out<<c.nature;
}

 bool operator==(candy c,candy b){
     if(b.nature!=c.nature)
        return false;
     else{
        if(b.specialOrNot==true || c.specialOrNot==true){
            if (hasSameorientation(c,b)==true)
                return true;
            else return false;

        }
        return true ;
     }
 }
bool hasSameorientation(candy b,candy c){
  if(b.orientation=='N')
    return true;
  else
    return c.orientation==b.orientation;
}
