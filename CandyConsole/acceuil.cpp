#include "acceuil.h"
#include<bits/stdc++.h>
#include "windows.h"
using namespace std;

acceuil::acceuil()
{
    //ctor
}

acceuil::~acceuil()
{
    //dtor
}
void acceuil::affichePageAceuil(){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, 7);
int i=0;
while(i<300){
        cout<<"            |\\ _____ /|     |\\ _____ /|  |\\ _____ /|    |\\ _____ /|     |\\ _____ /|  |\\ _____ /|     "<<endl;
        cout<<"            | (_____) |     | (_____) |  | (_____) |    | (_____) |     | (_____) |  | (_____) |       "<<endl;
        cout<<"            |/       \\|     |/       \\|  |/       \\|    |/       \\|     |/       \\|  |/       \\|   "<<endl<<endl;
        i++;


}
system("cls");
SetConsoleTextAttribute(hConsole, 3);
cout<<"              |\\ _____ /|     |\\ _____ /|  |\\ _____ /|    |\\ _____ /|     |\\ _____ /|  |\\ _____ /|     "<<endl;
SetConsoleTextAttribute(hConsole, 2);
cout<<"              | (_____) |     | (_____) |  | (_____) |    | (_____) |     | (_____) |  | (_____) |       "<<endl;
SetConsoleTextAttribute(hConsole, 3);
cout<<"              |/       \\|     |/       \\|  |/       \\|    |/       \\|     |/       \\|  |/       \\|   "<<endl<<endl;
SetConsoleTextAttribute(hConsole, 4);
cout<<"              |\\ _____ /|-------+++++      $\\\\    $\\\\    $$ $$@@@@@ $$    $$+----------|\\ _____ /|     "<<endl;
SetConsoleTextAttribute(hConsole, 5);
cout<<"              | (_____) |-----+++         $  \\\\   $ \\\\   $$ $$   @@  $$  $$+---------- | (_____) |       "<<endl;
SetConsoleTextAttribute(hConsole, 6);
cout<<"              |/       \\|---+++          $@@@@\\\\  $  \\\\  $$ $$    @    $$+-------------|/       \\|   "<<endl;
SetConsoleTextAttribute(hConsole, 7);
cout<<"                         -----+++       $      \\\\ $   \\\\ $$ $$   @@    $$+-------                "<<endl;
SetConsoleTextAttribute(hConsole, 9);
cout<<"              |\\ _____ /|-------+++++  $        \\\\$    \\\\$$ $$@@@@@    $$+-------------|\\ _____ /|     "<<endl;
SetConsoleTextAttribute(hConsole, 10);
cout<<"              | (_____) |                                                              | (_____) |       "<<endl;
SetConsoleTextAttribute(hConsole, 11);
cout<<"              |/       \\|----------+++++ @@@ @   $$   $$   @@   $$  $$+----------------|/       \\|   "<<endl;
SetConsoleTextAttribute(hConsole, 12);
cout<<"                         --------+++     @@   @  $$   $$  @     $$  $$+----------------"<<endl;
SetConsoleTextAttribute(hConsole, 1);
cout<<"              |\\ _____ /|------+++       @@@ @   $$   $$   @@   $$$$$$+----------------|\\ _____ /|     "<<endl;
SetConsoleTextAttribute(hConsole, 2);
cout<<"              | (_____) |--------+++     @@  @@  $$   $$     @  $$  $$+----------------| (_____) |       "<<endl;
SetConsoleTextAttribute(hConsole, 3);
cout<<"              |/       \\|----------+++++ @@   @@   $$$     @@   $$  $$+----------------|/       \\|   "<<endl<<endl;
SetConsoleTextAttribute(hConsole, 4);
cout<<"              |\\ _____ /|     |\\ _____ /|  |\\ _____ /|    |\\ _____ /|     |\\ _____ /|  |\\ _____ /|     "<<endl;
SetConsoleTextAttribute(hConsole, 5);
cout<<"              | (_____) |     | (_____) |  | (_____) |    | (_____) |     | (_____) |  | (_____) |       "<<endl;
SetConsoleTextAttribute(hConsole, 6);
cout<<"              |/       \\|     |/       \\|  |/       \\|    |/       \\|     |/       \\|  |/       \\|   "<<endl<<endl;
SetConsoleTextAttribute(hConsole, 7);
cout<<"                                          ENTER YOUR NAME ";SetConsoleTextAttribute(hConsole, 3); string ch ;cin>>ch;cout<<endl;
SetConsoleTextAttribute(hConsole, 6);
cout<<"                                   "<<ch<<" TAP Y TO LAUNCH THE GAME ";
string s;
cin>>s;
SetConsoleTextAttribute(hConsole, 7);
system("cls");
}
