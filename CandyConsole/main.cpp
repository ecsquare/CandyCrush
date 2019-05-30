#include <bits/stdc++.h>
#include "windows.h"
#include "acceuil.h"
#include "NewGame.h"
#include "message.h"

using namespace std;

int main()
{
    acceuil a;
    a.affichePageAceuil();
    int scm=500,m=15,sc=0,t=0;
    int l=1;
    int temps=0;
    NewGame g(scm,m,l);
    while(g.getter_score()<scm){
    g.afficheBoard(temps,0,0);
    if(g.getter_moves()==0 || g.getter_score()==scm)
        break;
    else{
    int x1,y1,x2,y2;
    cout<<"ENTER(x1,y1) ";
    while(true){
        cin>>x1>>y1;
        if (x1<0 && y1<0 && x1>8 && y1>8){
            cout<<"retry again error"<<endl;
            cout<<"ENTER (x1,y1)"<<endl;
        }
        else
            break;

   }
   cout<<"ENTER(x2,y2) ";
   while(true){
        cin>>x2>>y2;
        if (x2<0 && y2<0 && x2>8 && y2>8 ){
            cout<<"retry again error "<<endl;
            cout<<"ENTER (x2,y2)"<<endl;
        }
        else
            break;

 }
 cout<<endl<<endl;
 temps++;
 g.makeMove(x1,y1,x2,y2,temps);
 Sleep(900);
 system("cls");
 temps+=4;
 g.action(temps);
 }
 }

 system("cls");
  int y;
 if (g.getter_score()<scm)
    y=0;
 else y=1;
 message p(y);
 p.affiche();
    return 0;
}
