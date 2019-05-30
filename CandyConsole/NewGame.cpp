#include "NewGame.h"
#include "timing.h"
#include<bits/stdc++.h>
using namespace std;

NewGame::NewGame(int s,int m,int l):winScore(s),MaxMoves(m),level(l)
{
    int rows, columns, flag;
    char t[8][8];
    char v[4] = {'@', '%', '$', '+'};
    srand(time(NULL));
     for ( rows = 0 ; rows < 8 ; rows++ ){
            for ( columns = 0 ; columns < 8 ; columns++ ){
                flag = 0;
                do{

                    int RandIndex = rand() % 4; //generates a random number between 0 and 3
                    t[rows][columns]=v[RandIndex];
                    //Checks for 2 adjacent numbers.
                    if  ( t[rows][columns] == t[rows - 1][columns] || t[rows][columns] == t[rows][columns - 1] ){
                        flag = 0;
                        continue;
                    }
                    else{
                        flag = 1;
                        board[rows][columns]=t[rows][columns];
                    }
                } while ( flag == 0 );
            }
        }
}
int NewGame::NoMoreMoves(){
    int i,j;
    //Lign
    for (i=0;i<8;i++) for(j=0;j<7;j++){
        if (board[i][j]==board[i][j+1]){  //couple found
                //above
                if (i!=0){
                          if (j!=0){
                                    if (board[i-1][j-1]==board[i][j]) return 0; //there is a comb
                          }
                          if (j+2<=7){
                                    if (board[i-1][j+2]==board[i][j]) return 0; //there is a comb
                          }
                }
                //in the same lign
                if (j-2>=0){
                          if (board[i][j-2]==board[i][j]) return 0; //there is a comb
                }
                if (j+3<=7){
                          if (board[i][j+3]==board[i][j]) return 0; //there is a comb
                }
                //under
                if (i+1<=7){
                          if (j+1<=7){
                                      if (board[i+1][j+1]==board[i][j]) return 0; //there is a comb
                          }
                          if (j+2<=7){
                                      if (board[i+1][j+2]==board[i][j]) return 0; //there is a comb
                          }
                }
        }
    }
    //Column
    for (i=0;i<7;i++) for(j=0;j<8;j++){
        if (board[i][j]==board[i+1][j]){  //Couple found
                //Above
                if (j!=0){
                          if (i!=0){
                                    if (board[i-1][j-1]=board[i][j]) return 0; //there is a comb
                          }
                          if (i+2<=7){
                                    if (board[i+2][j-1]==board[i][j]) return 0; //there is a comb
                          }
                }
                //Same ligne
                if (i-2>=0){
                          if (board[i-2][j]==board[i][j]) return 0; //there is a comb
                }
                if (i+3<=7){
                          if (board[i+3][j]==board[i][j]) return 0; //there is a comb
                }
                //Under
                if (j+1<=7){
                          if (i+1<=7){
                                      if (board[i+1][j+1]==board[i][j]) return 0; //there is a comb
                          }
                          if (i+2<=7){
                                      if (board[i+2][j+1]==board[i][j]) return 0; //there is a comb
                          }
                }
        }
    }
    //there are no comb
    return 1;
}
void NewGame::shuffleBoard(){
int matrice[8][8];
        for (int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                matrice[i][j]=0;
        while (NoMoreMoves()==1){
            srand(time(NULL));
            for (int i=0;i<8;i++){
                for (int j=0;j<8;j++){


                int RandI = rand() % 8; //generates a random number between 0 and 7
                int RandJ= rand() % 8;
                while(matrice[RandI][RandJ]!=0){
                         RandI = rand() % 8; //generates a random number between 0 and 7
                          RandJ= rand() % 8;

                }
                char aux=board[i][j];
                board[i][j]=board[RandI][RandJ];
                board[RandI][RandJ]=aux;

             }
            }
       }
}
void NewGame::afficheBoard(int t,int sc,int k){
timing l(t);



  cout<<endl<<endl<<endl;
  cout<<"           _________________________________________________________________________\n";
  cout<<"          |    0   |    1   |    2   |    3   |    4   |    5   |   6    |   7    |           ^^^^^^^^^^^^^^^^^^^^^^^^\n";
  cout<<"       ___|________|________|________|________|________|________|________|________|               temps : ";l.afficherT();cout<<"\n";
  cout<<"      | 0 |        |        |        |        |        |        |        |        |               score : "<<getter_score()<<"\n";
  cout<<"      |   |  "<<board[0][0]<<"     |  "<<board[0][1]<<"     |  "<<board[0][2]<<"     |  "<<board[0][3]<<"     |  "<<board[0][4]<<"     |  "<<board[0][5]<<"     |  "<<board[0][6]<<"     |  "<<board[0][7]<<"     |               moves : "<<MaxMoves<<endl;
  cout<<"      |___|________|________|________|________|________|________|________|________|               LEVEL : "<<level<<endl;
  cout<<"      | 1 |        |        |        |        |        |        |        |        |           ^^^^^^^^^^^^^^^^^^^^^^^^\n";
  cout<<"      |   |  "<<board[1][0]<<"     |  "<<board[1][1]<<"     |  "<<board[1][2]<<"     |  "<<board[1][3]<<"     |  "<<board[1][4]<<"     |  "<<board[1][5]<<"     |  "<<board[1][6]<<"     |  "<<board[1][7]<<"     |            TO WIN YOU HAVE TO REACH\n";
  cout<<"      |___|________|________|________|________|________|________|________|________|                   "<<winScore<<"\n";
  cout<<"      | 2 |        |        |        |        |        |        |        |        |  \n";
  cout<<"      |   |  "<<board[2][0]<<"     |  "<<board[2][1]<<"     |  "<<board[2][2]<<"     |  "<<board[2][3]<<"     |  "<<board[2][4]<<"     |  "<<board[2][5]<<"     |  "<<board[2][6]<<"     |  "<<board[2][7]<<"     |\n";
  cout<<"      |___|________|________|________|________|________|________|________|________|           ^^^^^^^^^^^^^^^^^^^^^^^^^\n";
  cout<<"      | 3 |        |        |        |        |        |        |        |        |             Lucky! Special Candy!\n";
  cout<<"      |   |  "<<board[3][0]<<"     |  "<<board[3][1]<<"     |  "<<board[3][2]<<"     |  "<<board[3][3]<<"     |  "<<board[3][4]<<"     |  "<<board[3][5]<<"     |  "<<board[3][6]<<"     |  "<<board[3][7]<<"     |\n";
  cout<<"      |___|________|________|________|________|________|________|________|________|               ___ ___ ___ ___\n";
  cout<<"      | 4 |        |        |        |        |        |        |        |        |              | $ | @ | + | % |\n";
  cout<<"      |   |  "<<board[4][0]<<"     |  "<<board[4][1]<<"     |  "<<board[4][2]<<"     |  "<<board[4][3]<<"     |  "<<board[4][4]<<"     |  "<<board[4][5]<<"     |  "<<board[4][6]<<"     |  "<<board[4][7]<<"     |           ____________________\n";
  cout<<"      |___|________|________|________|________|________|________|________|________|           L/T| D | A | P | R |  \n";
  cout<<"      | 5 |        |        |        |        |        |        |        |        |           ____________________\n";
  cout<<"      |   |  "<<board[5][0]<<"     |  "<<board[5][1]<<"     |  "<<board[5][2]<<"     |  "<<board[5][3]<<"     |  "<<board[5][4]<<"     |  "<<board[5][5]<<"     |  "<<board[5][6]<<"     |  "<<board[5][7]<<"     |           4V | s | ^ | | | \\ |\n";
  cout<<"      |___|________|________|________|________|________|________|________|________|           _____________________\n";
  cout<<"      | 6 |        |        |        |        |        |        |        |        |           4H | ~ | < | - | / |\n";
  cout<<"      |   |  "<<board[6][0]<<"     |  "<<board[6][1]<<"     |  "<<board[6][2]<<"     |  "<<board[6][3]<<"     |  "<<board[6][4]<<"     |  "<<board[6][5]<<"     |  "<<board[6][6]<<"     |  "<<board[6][7]<<"     |           _____________________\n";
  cout<<"      |___|________|________|________|________|________|________|________|________|\n";
  cout<<"      | 7 |        |        |        |        |        |        |        |        |  \n";
  cout<<"      |   |  "<<board[7][0]<<"     |  "<<board[7][1]<<"     |  "<<board[7][2]<<"     |  "<<board[7][3]<<"     |  "<<board[7][4]<<"     |  "<<board[7][5]<<"     |  "<<board[7][6]<<"     |  "<<board[7][7]<<"     |\n";
  cout<<"      |___|________|________|________|________|________|________|________|________|  \n";
  cout<<endl<<endl;
}
void NewGame::makeMove(int x1,int y1,int x2,int y2,int temps){
   if(verif(x1,y1,x2,y2)==true && ((x1==x2 &&(y1==y2+1 || y2==y1+1))||(y1==y2 && (x1==x2+1 || x2==x1+1)))){
        //permutaion des pieces
        permut(x1,y1,x2,y2);
        system("cls");
        afficheBoard(temps,score,MaxMoves--);

   }
   else{
    cout<<"INVALID MOVE"<<endl;
   }
}
//return a special candy according to the number of combination and the shape
char NewGame::returnSpE(char a,char b,int x){
    if (a=='$'){
         if(x==4){
            if (b=='V') return 's';
            if(b=='H') return '~';
         }
         if(x==5) return 'D';
        }
    if (a=='%'){
        if(x==4){
            if (b=='V') return '/';
            if(b=='H') return '\\';
        }
        if(x==5) return 'R';

        }
    if (a=='@'){
        if(x==4){
            if (b=='V') return '^';
            if(b=='H') return '<';
        }
        if(x==5) return 'A';

        }
    if (a=='+'){
       if(x==4){
            if (b=='V') return '|';
            if(b=='H') return '-';
       }
       if(x==5) return 'P';
        }
}
//fonction that returns the simple candy that it was formed by [OR] return char if the candy is allready simple
char NewGame::OriginCandy(char a){
    if (a=='D' || a=='~' || a=='s') return '$';
    if (a=='A' || a=='<' || a=='^') return '@';
    if(a=='R' || a=='/' || a=='\\') return '%';
    if (a=='P' || a=='-' || a=='|') return '+';
    return a;
}
// function that return 1 if the combination can be used with horizontal combination , 2 if only used in verticle combonation , 3 if nomal candy
int NewGame::verifHV(char a){
    if(a=='~' || a=='<' || a=='/' || a=='-') return 1;
    if(a=='^' || a=='s' || a=='\\' || a=='|') return 2;
     else return 3;
}

void NewGame::fillEmpty(){
       char v[4] = {'@', '%', '$', '+'};
        srand(time(NULL));
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){

				// if the candy at (i,j) is equal to X, put a random candy in that tile
                if(board[i][j] == 'X'){

                    int r = rand() % 4;
                    // set the given tile to that number
                    board[i][j] = v[r];}
                }
        }
}

// after the removal (blowing up the candies), drop down the remaining candies
void NewGame::dropDown(){

		// continue the while loop until you get all empty tiles to top
		// checkAbove function checks if empty tiles have any candies above them
        while(checkAbove()){

			// start from the lowest row for each column
            for(int i=0; i<7; i++){
                for(int j=0; j<8; j++){

					// if the row is equal to 0, move all rows above it down by one
                    if(board[i+1][j] == 'X'){

                        board[i+1][j] = board[i][j];
                        board[i][j] = 'X';
                    }

                }
            }

        }
    }

// check if any of the empty tiles has candies above it
	// (return true if any tile that is equal to 0, has a candy above it)
bool NewGame::checkAbove(){

		// when you find a tile equal to 0, check if it has any candies above
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){

				// if there is an empty tile (tile that is equal to 0)
                if(board[i][j]=='X'){

					// check all tiles above it
                    for(int k=i; k>-1; k--){

						// if at least one of these tiles is not empty, return true
                        if(board[k][j] != 'X')
                            return true;

                    }

                }

            }
        }

        return false;
}
/////////////////////REMOVE DIFFERENT CANDY GROUPS ////////////////////////


	// if there are candy groups shaped like T, remove them
    /*

      ***
       *
       *

    */
void NewGame::Tremove(){


        /*

        ---
         -
         -

        */
        for(int i=0; i+2<8; i++){
            for(int j=0; j+2<8; j++){


				// set all candies on that group to 0 (remove them) except where to place the special candy
                if( board[i][j]==board[i][j+1] &&
                    board[i][j]==board[i][j+2] &&
                    board[i][j]==board[i+1][j+1] &&
                    board[i][j]==board[i+2][j+1]
                        ){
                    char z=returnSpE(board[i][j],' ',5);
                    board[i][j] ='X';
                    board[i][j+1] = 'X';
                    board[i][j+2] = 'X';
                    board[i+1][j+1] = 'X';
                    board[i+2][j+1] = z;

                    score += 25;

                }

            }
        }

        /*
        a grouping like

        -
        ---
        -

        */
        for(int i=0; i+2<8; i++){
            for(int j=0; j+2<8; j++){

				// set all candies on that group to 0 (remove them) except where to place the special candy
                if( board[i][j]==board[i+1][j] &&
                    board[i][j]==board[i+2][j] &&
                    board[i][j]==board[i+1][j+1] &&
                    board[i][j]==board[i+1][j+2]
                        ){
                    char z=returnSpE(board[i][j],' ',5);
                    board[i][j] = 'X';
                    board[i+1][j] = 'X';
                    board[i+2][j] = z;
                    board[i+1][j+1] = 'X';
                    board[i+1][j+2] = 'X';

                    score += 25;

                }

            }
        }


        /*

         -
         -
        ---

        */
        for(int i=0; i+2<8; i++){
            for(int j=1; j+1<8; j++){

				// set all candies on that group to 0 (remove them) except where to place the special candy
                if( board[i][j]==board[i+1][j] &&
                    board[i][j]==board[i+2][j] &&
                    board[i][j]==board[i+2][j-1] &&
                    board[i][j]==board[i+2][j+1]
                        ){
                    char z=returnSpE(board[i][j],' ',5);
                    board[i][j] ='X';
                    board[i+1][j] ='X';
                    board[i+2][j] ='X';
                    board[i+2][j-1] ='X';
                    board[i+2][j+1] = z;

                    score += 25;
                }
            }
        }

        /*
          -
        ---
          -
        */
        for(int i=0; i+2<8; i++){
            for(int j=2; j<8; j++){

				// set all candies on that group to 0 (remove them) except where to put the special candy
                if( board[i][j]==board[i+1][j] &&
                    board[i][j]==board[i+1][j-1] &&
                    board[i][j]==board[i+1][j-2] &&
                    board[i][j]==board[i+2][j]
                        ){
                    char z=returnSpE(board[i][j],' ',5);
                    board[i][j] ='X';
                    board[i+1][j] ='X';
                    board[i+1][j-1] ='X';
                    board[i+1][j-2] ='X';
                    board[i+2][j] =z;

                    score += 25;

                }

            }
        }

    }
// a grouping like L
    /*

    -
    -
    ---

    */
void NewGame::Lremove(){

        /*

        -
        -
        ---

        */
        for(int i=0; i+2<8; i++){
            for(int j=0; j+2<8; j++){

				// set all candies on that group to 0 (remove them) except where to place the special candy
                if( board[i][j]==board[i+1][j] &&
                    board[i][j]==board[i+2][j] &&
                    board[i][j]==board[i+2][j+1] &&
                    board[i][j]==board[i+2][j+2]
                        ){
                    char z=returnSpE(board[i][j],' ',5);
                    board[i][j] = 'X';
                    board[i+1][j] = 'X';
                    board[i+2][j] = z;
                    board[i+2][j+1] = 'X';
                    board[i+2][j+2] = 'X';

                    score += 25;

                }

            }
        }

        /*

        ---
        -
        -

        */
        for(int i=0; i+2<8; i++){
            for(int j=0; j+2<8; j++){

                if( board[i][j]==board[i][j+1] &&
                    board[i][j]==board[i][j+2] &&
                    board[i][j]==board[i+1][j] &&
                    board[i][j]==board[i+2][j]
                        ){

                    char z=returnSpE(board[i][j],' ',5);
                    board[i][j] = 'X';
                    board[i][j+1] = 'X';
                    board[i][j+2] = 'X';
                    board[i+1][j] = 'X';
                    board[i+2][j] = z;

                    score += 25;

                }

            }
        }


        /*

          -
          -
        ---

        */
        for(int i=0; i+2<8; i++){
            for(int j=2; j<8; j++){

                if( board[i][j]==board[i+1][j] &&
                    board[i][j]==board[i+2][j] &&
                    board[i][j]==board[i+2][j-1] &&
                    board[i][j]==board[i+2][j-2]
                        ){
                    char z=returnSpE(board[i][j],' ',5);
                    board[i][j] = 'X';
                    board[i+1][j] = 'X';
                    board[i+2][j] = z;
                    board[i+2][j-1] = 'X';
                    board[i+2][j-2] = 'X';

                    score += 25;

                }

            }
        }


        /*

        ---
          -
          -

        */
        for(int i=0; i+2<8; i++){char a
            for(int j=0; j+2<8; j++){

                if( board[i][j]==board[i][j+1] &&
                    board[i][j]==board[i][j+2] &&
                    board[i][j]==board[i+1][j+2] &&
                    board[i][j]==board[i+2][j+2]
                        ){
                    char z=returnSpE(board[i][j],' ',5);
                    board[i][j] = 'X';
                    board[i][j+1] = 'X';
                    board[i][j+2] = 'X';
                    board[i+1][j+2] = 'X';
                    board[i+2][j+2] = z;

                    score += 25;

                }

            }
        }

}
	// if there are 5 candies side by side or from top to bottom, remove them and add the points
void NewGame::Mremove(){

		// starting from (0,0), check if the next 4 candies are equal to this one
		// if equal, remove these candies
        for(int i=0; i<8; i++){
            for(int j=0; j+4<8; j++){

                if(
                    board[i][j]==board[i][j+1] &&
                    board[i][j]==board[i][j+2] &&
                    board[i][j]==board[i][j+3] &&
                    board[i][j]==board[i][j+4]
                    ){

                    board[i][j] = 'X';
                    board[i][j+1] = 'X';
                    board[i][j+2] = 'M';
                    board[i][j+3] = 'X';
                    board[i][j+4] = 'X';

                    score += 30;

                }

            }
        }


		// starting from (0,0), check if the next 4 candies under it are the same as that
		// if equal, remove these candies
        for(int i=0; i+4<8; i++){
            for(int j=0; j<8; j++){

                if(
                    board[i][j]==board[i+1][j] &&
                    board[i][j]==board[i+2][j] &&
                    board[i][j]==board[i+3][j] &&
                    board[i][j]==board[i+4][j]
                    ){

                    board[i][j] = 'X';
                    board[i+1][j] = 'X';
                    board[i+2][j] = 'X';
                    board[i+3][j] = 'X';
                    board[i+4][j] = 'M';

                    score += 30;

                }

            }
        }

    }

	// if there are 4 candies side by side or from top to bottom, remove them and add the points
void NewGame::FourRemove(){

		// starting from (0,0), check if the next 3 candies are equal to this one
		// if equal, remove these candies and place the special candy
        for(int i=0; i<8; i++){
            for(int j=0; j+3<8; j++){

                if(
                    board[i][j]==board[i][j+1] &&
                    board[i][j]==board[i][j+2] &&
                    board[i][j]==board[i][j+3]
                    ){

                    char z=returnSpE(board[i][j],'H',4);
                    board[i][j] = 'X';
                    board[i][j+1] = z;
                    board[i][j+2] = 'X';
                    board[i][j+3] = 'X';

                    score += 16;

                }

            }
        }


		// starting from (0,0), check if the next 3 candies under it are the same as that
		// if equal, remove these candies and place the special candy
        for(int i=0; i+3<8; i++){
            for(int j=0; j<8; j++){

                if(
                    board[i][j]==board[i+1][j] &&
                    board[i][j]==board[i+2][j] &&
                    board[i][j]==board[i+3][j]
                    ){
                    char z=returnSpE(board[i][j],'V',4);
                    board[i][j] = 'X';
                    board[i+1][j] = 'X';
                    board[i+2][j] = 'X';
                    board[i+3][j] = z;

                    score += 16;

                }

            }
        }

    }


	// if there are 3 candies side by side or from top to bottom, remove them and add the points
void NewGame::TripleRemove(){

		// starting from (0,0), check if the next 2 candies are equal to this one
		// if equal, remove these candies
        for(int i=0; i<8; i++){
            for(int j=0; j+2<8; j++){

                if(
                    board[i][j]==board[i][j+1] &&
                    board[i][j]==board[i][j+2]
                    ){

                    board[i][j] = 'X';
                    board[i][j+1] = 'X';
                    board[i][j+2] = 'X';

                    score += 9;

                }

            }
        }


		// starting from (0,0), check if the next 2 candies under it are the same as that
		// if equal, remove these candies
        for(int i=0; i+2<8; i++){
            for(int j=0; j<8; j++){

                if(
                    board[i][j]==board[i+1][j] &&
                    board[i][j]==board[i+2][j]
                    ){

                    board[i][j] = 'X';
                    board[i+1][j] = 'X';
                    board[i+2][j] = 'X';

                    score += 9;

                }

            }
        }

}

void NewGame::action(int temps){
               int compt=0;
            while(StillmoreToBlow()==true){
                //("BOOOM");
				// remove all candy groups starting from the ones shaped like T
                removeMUsed();
                Tremove();

                Lremove();

                usageLTremove();

                Mremove();

                FourRemove();

                remove4used();

                TripleRemove();

                // drop down the remaining candies
                dropDown();
                // fill in the blank tiles after all candies are blown up
                fillEmpty();
                compt++;
                temps+=compt;
                afficheBoard(temps,score,MaxMoves);}
}
///////////////////// Use special candy 'D' 'A' 'R' 'P' in a combination  \\\\\\\\\\\\\\\\\\\\\\

void NewGame::usageLTremove(){
    for (int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j]=='A' || board[i][j]=='D' || board[i][j]=='R' || board[i][j]=='P'){
                //remove if a combination like AXX || XXA || XAX
                // XX0 X X X
                //   1 X X X
                //   2 X X X
                //   3              & & &
                // &&4              & & &
                //   5       * * *  & & &
                //   6       * * *
                // **7       * * *

                //AXX
                if(OriginCandy(board[i][j])==board[i][j+1] && board[i][j+1]==board[i][j+2]){
                    board[i][j]='X';
                    board[i][j+1]='X';
                    board[i][j+2]='X';
                    //&&
                    if (i!=0 && i!=7){
                            board[i-1][j]='X';board[i-1][j+1]='X';board[i-1][j+2]='X';
                            board[i+1][j]='X';board[i+1][j+1]='X';board[i+1][j+2]='X';

                    }
                   //XX
                    if(i==0){
                            board[i+2][j]='X';board[i+2][j+1]='X';board[i+2][j+2]='X';
                            board[i+1][j]='X';board[i+1][j+1]='X';board[i+1][j+2]='X';
                    }
                   //**
                    if(i==7){
                            board[i-1][j]='X';board[i-1][j+1]='X';board[i-1][j+2]='X';
                            board[i-2][j]='X';board[i-2][j+1]='X';board[i-2][j+2]='X';
                    }
                    }
                //XXA
                if(OriginCandy(board[i][j])==board[i][j-1] && board[i][j-1]==board[i][j-2] ){
                    board[i][j]='X';
                    board[i][j-1]='X';
                    board[i][j-2]='X';
                    if (i!=0 && i!=7){
                            board[i-1][j]='X';board[i-1][j-1]='X';board[i-1][j-2]='X';
                            board[i+1][j]='X';board[i-2][j-1]='X';board[i+1][j-2]='X';

                    }
                    if(i==0){
                            board[i+2][j-1]='X';board[i+2][j-2]='X';board[i+2][j]='X';
                            board[i+1][j-1]='X';board[i+1][j-2]='X';board[i+1][j]='X';
                    }
                    if(i==7){
                            board[i-1][j]='X';board[i-1][j-1]='X';board[i-1][j-2]='X';
                            board[i-2][j]='X';board[i-2][j-1]='X';board[i-2][j-2]='X';
                    }
                    }

                //XAX
                if(OriginCandy(board[i][j])==board[i][j-1] && board[i][j-1]==board[i][j+1] ){
                    board[i][j]='X';
                    board[i][j+1]='X';
                    board[i][j-1]='X';
                    if (i!=0 && i!=7){
                            board[i-1][j]='X';board[i-1][j-1]='X';board[i-1][j+1]='X';
                            board[i+1][j]='X';board[i-2][j-1]='X';board[i+1][j+1]='X';

                    }
                    if(i==0){
                            board[i+2][j]='X';board[i+2][j-1]='X';board[i+2][j+1]='X';
                            board[i+1][j]='X';board[i+1][j-1]='X';board[i+1][j+1]='X';
                    }
                    if(i==7){
                            board[i-1][j]='X';board[i-1][j-1]='X';board[i-1][j+1]='X';
                            board[i-2][j]='X';board[i-2][j-1]='X';board[i-2][j+1]='X';
                    }
                    }
                /////remove column \\\\\\

                // X   A   X
                // X   X   A
                // A   X   X

                // *     &       X
                // 0 1 2 3 4 5 6 7
                //
                // * * *     X X X
                // * * *     X X X
                // * * *     X X X
                //      & & &
                //      & & &
                //      & & &

                //1\\
                // A
                // X
                // X

                if(OriginCandy(board[i][j])==board[i+1][j] && board[i+1][j]==board[i+2][j] ){
                    board[i][j]='X';
                    board[i+1][j]='X';
                    board[i+2][j]='X';
                    if (j!=0 && j!=7){
                            board[i][j-1]='X';board[i+1][j-1]='X';board[i+2][j-1]='X';
                            board[i][j+1]='X';board[i+2][j+1]='X';board[i+2][j+1]='X';

                    }
                    if(j==0){
                            board[i][j+1]='X';board[i+1][j+1]='X';board[i+2][j+1]='X';
                            board[i][j+2]='X';board[i+1][j+2]='X';board[i+2][j+2]='X';
                    }
                    if(j==7){
                            board[i][j-1]='X';board[i+1][j-1]='X';board[i+2][j-1]='X';
                            board[i][j-2]='X';board[i+1][j-2]='X';board[i+2][j-2]='X';
                    }
                }
                //2\\
                // X
                // A
                // X
                if(OriginCandy(board[i][j])==board[i-1][j] && board[i-1][j]==board[i+1][j] ){
                    board[i][j]='X';
                    board[i-1][j]='X';
                    board[i+1][j]='X';
                    if (j!=0 && j!=7){
                            board[i][j-1]='X';board[i-1][j-1]='X';board[i+1][j-1]='X';
                            board[i][j+1]='X';board[i-1][j+1]='X';board[i+1][j+1]='X';
                    }
                    if(j==0){
                            board[i][j+1]='X';board[i-1][j+1]='X';board[i+1][j+1]='X';
                            board[i][j+2]='X';board[i-1][j+1]='X';board[i+1][j+2]='X';
                    }
                    if(j==7){
                            board[i][j-1]='X';board[i-1][j-1]='X';board[i+1][j-1]='X';
                            board[i][j-2]='X';board[i-1][j-2]='X';board[i+1][j-2]='X';
                    }
                }

                //3\\
                // X
                // X
                // A

                if(OriginCandy(board[i][j])==board[i-1][j] && board[i-1][j]==board[i-2][j] ){
                    board[i][j]='X';
                    board[i-1][j]='X';
                    board[i-2][j]='X';
                    if (j!=0 && j!=7){
                            board[i][j-1]='X';board[i-1][j-1]='X';board[i-2][j-1]='X';
                            board[i][j+1]='X';board[i-1][j+1]='X';board[i-2][j+1]='X';

                    }
                    if(j==0){
                            board[i][j+1]='X';board[i-1][j+1]='X';board[i-2][j+1]='X';
                            board[i][j+2]='X';board[i-1][j+2]='X';board[i-2][j+2]='X';
                    }
                    if(j==7){
                            board[i][j-1]='X';board[i-1][j-1]='X';board[i-2][j-1]='X';
                            board[i][j-2]='X';board[i-1][j-2]='X';board[i-2][j-2]='X';
                    }
                    score+=40;
                }
}}}}
/////////////////////// use Special candy XXXX \\\\\\\\\\\\\\\\\
//1\\ if horizontal Y X X remove ligne i
//   0 1 2 3 4 5 6 7
//
// i X X X X X X X X
//
//2\\ if vertical remove all candy in column j
//          j
//    0 1 2 3 4 5 6 7
//  0       X
//  1       X
//  2       X
//  3       X
//  4       X
//  5       X
//  6       X
//  7       X


void NewGame::remove4used(){
    char a;
     for(int i=0;i<8;i++){
        for(int j=0;j<7;j++){
            //1\\

            if(board[i][j]=='<' || board[i][j]=='~' || board[i][j]=='-' || board[i][j]=='/')
            {
                   a=OriginCandy(board[i][j]);
                    if((a==OriginCandy(board[i][j+1]) && a==OriginCandy(board[i][j+2]) && verifHV(board[i][j+1])!=2 && verifHV(board[i][j+2]!=2))
                       ||(a==OriginCandy(board[i][j-1])==OriginCandy(board[i][j+1]) && verifHV(board[i][j-1])!=2 && verifHV(board[i][j+1])!=2)
                        ||(a==OriginCandy(board[i][j-1]) && a==OriginCandy(board[i][j-2]) && verifHV(board[i][j-1])!=2 && verifHV(board[i][j-2])!=2))

                    for(int k=0;k<8;k++)
                      board[i][k]='X';

            }
        }
    }
    for(int i=0;i<6;i++){
        for(int j=0;j<8;j++){
            //2\\

            if(board[i][j]=='^' || board[i][j]=='s'|| board[i][j]=='|' || board[i][j]=='\\' ){
                a=OriginCandy(board[i][j]);
                if  ((a==OriginCandy(board[i+1][j]) &&  a==OriginCandy(board[i+2][j]) && verifHV(board[i+1][j])!=1 && verifHV(board[i+2][j])!=1)
                    ||(a==OriginCandy(board[i-1][j]) && a==OriginCandy(board[i+1][j]) && verifHV(board[i-1][j])!=1 && verifHV(board[i+1][j])!=1)
                    ||(a==OriginCandy(board[i-1][j]) && a==OriginCandy(board[i-2][j]) && verifHV(board[i-1][j])!=1 && verifHV(board[i-1][j])!=1)){

                            char v[4] = {'@', '%', '$', '+'};
                            srand(time(NULL));
                            for(int k=0;k<8;k++){
                                int RandIndex = rand() % 4; //generates a random number between 0 and 3
                                 board[k][j]=v[RandIndex];
                            }

                }
            }
        }
    }
}
////////////////////// use Special candy Multicolor \\\\\\\\\\\\\

int NewGame::elimin(char a){
    int compt=15;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j]==a){
                board[i][j]='X';
                compt++;}
        }

    }
    return compt;
}
void NewGame::removeMUsed(){
    char y=' ';
    //Lign
    for (int i=0;i<8;i++){
        for(int j=0;j<6;j++){
                if (board[i][j]=='M'){
                    if (board[i][j+1]==board[i][j+2]) {y=board[i][j+1];board[i][j]='X';score+=elimin(y);}
                    if (board[i][j-1]==board[i][j+1]) {y=board[i][j+1];board[i][j]='X';score+=elimin(y);}
                    if (board[i][j-1]==board[i][j-2]) {y=board[i][j-1];board[i][j]='X';score+=elimin(y);}
                }
        }
    }
    //column
     for (int i=0;i<6;i++){
        for(int j=0;j<8;j++){
                if (board[i][j]=='M'){
                    if (board[i+1][j]==board[i+2][j]) {y=board[i+1][j];board[i][j]='X';score+=elimin(y);}
                    if (board[i-1][j]==board[i+1][j]) {y=board[i+1][j];board[i][j]='X';score+=elimin(y);}
                    if (board[i-1][j]==board[i-2][j]) {y=board[i-1][j];board[i][j]='X';score+=elimin(y);}

               }
        }
    }
}
int NewGame::getter_score(){
    return score;
}
// function to check if user's move is valid or not
bool NewGame::verif(int x1, int y1, int x2, int y2){
			// first, make the given move
            permut(x1,y1,x2,y2);
			// after the move, check if the candies on given coordinates have at least two neighboring candies that are the same kind as them
            if(hasBro(x1,y1) || hasBro(x2,y2)){
				// if the move is valid, return true
				// take back the move you just made (if this function returns true, we will make the actual move in main function)
                permut(x1,y1,x2,y2);
                return true;
            }
            else{
				// if the move is invalid, return false
				// take back the move you just made (if this function returns true, we will make the actual move in main function)
                permut(x1,y1,x2,y2);
                return false;
            }
    }
    // function to switch places of two candies
void NewGame::permut(int x1, int y1, int x2, int y2){

		// take the first and second candies that you will switch places
        char a = board[x1][y1];
        char b = board[x2][y2];

		// put these candies on their new places
        board[x1][y1] = b;
        board[x2][y2] = a;

    }
    // check if a given candy have a neighboring candy (that is the same kind) on its right, up, down or left side
bool NewGame::hasBro(int x, int y){
       char a=board[x][y];
       char b;
       char c;
		// flag will be increased by one each time the candy fails to have two neighbors of same kind on its sides
		// if the flag reaches 6, the function will return false
        int flag = 0;
		// if (x,y) has at least two candies on its left side, check if those two candies are equal to the one at (x,y)
        if(y > 1){
            b=board[x][y-1];
            c=board[x][y-2];


			// if the candies are equal, return true
            if(OriginCandy(a)==OriginCandy(b) && OriginCandy(a)==OriginCandy(c)&& verifHV(a)!=2 && verifHV(b)!=2 && verifHV(c)!=2 || ((a=='M' && b==c) ||(b=='M' && a==c)||(c=='M' && b==a))){

                return true;
            }

            else
                flag++;
        }
        else
            flag++;


		// if (x,y) has at least two candies on its right side, check if those are equal to (x,y)
        if(8 - y > 2){
                b=board[x][y+1];
                c=board[x][y+2];


			// if the candies are equal, return true
            if(OriginCandy(a)==OriginCandy(b) && OriginCandy(a)==OriginCandy(c)&& verifHV(a)!=2 && verifHV(b)!=2 && verifHV(c)!=2 || ((a=='M' && b==c) ||(b=='M' && a==c)||(c=='M' && b==a))){

                return true;
            }
            else
                flag++;
        }
        else
            flag++;


		// if (x,y) has at least two candies on its up side, check if those are equal to (x,y)
        if(x > 1){
            b=board[x-1][y];
            c=board[x-2][y];
			// if equal, return true
            if(OriginCandy(a)==OriginCandy(b) && OriginCandy(a)==OriginCandy(c)&& verifHV(a)!=1 && verifHV(b)!=1 && verifHV(c)!=1 || ((a=='M' && b==c) ||(b=='M' && a==c)||(c=='M' && b==a))){

                return true;
            }
            else
                flag++;
        }
        else
            flag++;


		// if (x,y) has at least two candies on its down side, check if those are equal to (x,y)
        if(8 - x > 2){
            b=board[x+1][y];
            c=board[x+2][y];

			// if equal, return true
            if(OriginCandy(a)==OriginCandy(b) && OriginCandy(a)==OriginCandy(c)&& verifHV(a)!=1 && verifHV(b)!=1 && verifHV(c)!=1 || ((a=='M' && b==c) ||(b=='M' && a==c)||(c=='M' && b==a))){

                return true;
            }
            else
                flag++;
        }
        else
            flag++;


		// if (x,y) has one candy on its left side and one on its right side, check if they are equal to (x,y)
        if(8- y > 1 && y > 0){
            b=board[x][y+1];
            c=board[x][y-1];

			// if those candies are equal to (x,y), return true
           if(OriginCandy(a)==OriginCandy(b) && OriginCandy(a)==OriginCandy(c)&& verifHV(a)!=2 && verifHV(b)!=2 && verifHV(c)!=2 || ((a=='M' && b==c) ||(b=='M' && a==c)||(c=='M' && b==a))){

                return true;
            }
            else
                flag++;
        }
        else
            flag++;


		// if (x,y) has one candy on its up side and one on its down side, check if they are equal to (x,y)
        if(8 - x > 1 && x > 0){
            b=board[x+1][y];
            c=board[x-1][y];

			// if equal, return true
            if(OriginCandy(a)==OriginCandy(b) && OriginCandy(a)==OriginCandy(c)&& verifHV(a)!=1 && verifHV(b)!=1 && verifHV(c)!=1 || ((a=='M' && b==c) ||(b=='M' && a==c)||(c=='M' && b==a))){

                return true;
            }
            else
                flag++;
        }
        else
            flag++;


		// if flag reached 6, return false
        if(flag == 6)
            return false;
        else
            return true;

    }
    // check if the board has at least one group of candies that can be removed
	// even if there are only 3 neighboring candies of the same kind, the function will return true
	// if there is this kind of a group, the candies will be blown up
bool NewGame::StillmoreToBlow(){

        for(int i=0; i<8; i++){

            for(int j=0; j<8; j++){

				// for each coordinate, check around that candy
				// if any candy have 2 neighboring candies of the same kind, we will blow them up. return true
				if(hasBro(i,j)){

                    return true;

                }

            }

        }
        return false;}
int NewGame::getter_moves(){
    return MaxMoves;
}
