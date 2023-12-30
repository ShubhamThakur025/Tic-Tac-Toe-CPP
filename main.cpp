#include <iostream>
#include <vector>
#include <cctype>
#include <bits/stdc++.h>
using namespace std;

//Vector to check on the filled tiles
vector <int> tilesFilled;

//The game board
char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

//to check availablity of a move
bool checkAvailablity(int num){
  for(const auto i : tilesFilled){
    if(i == num){
      return false;
    }
  }
  return true;
}

//to show the Board
void showBoard (){
  cout << "\t\t\t " <<board[0][0]<< " | " <<board[0][1]<< " | " <<board[0][2]<< endl;
  cout << "\t\t\t------------\n";
  cout << "\t\t\t " <<board[1][0]<< " | " <<board[1][1]<< " | " <<board[1][2]<< endl;
  cout << "\t\t\t------------\n";
  cout << "\t\t\t " <<board[2][0]<< " | " <<board[2][1]<< " | " <<board[2][2]<< endl;
}

//player choice
void playerMove(){
    int move;
    cout << "Enter your move:";
    cin >> move;
    if(checkAvailablity(move) && (move >= 1 && move <= 9)){
      tilesFilled.push_back(move);
      int col = (move - 1) % 3;
      int row = ceil((float)move/ 3) -1;
      board[row][col] = 'O';
    }
    else{
      cout << "Enter something valid\n";
      playerMove();
    }     
}

//the computerMove
void computerMove(){
  int move = rand() % 10;
  if(checkAvailablity(move) && (move <= 9 && move >= 0)){
      tilesFilled.push_back(move);
      int col = (move - 1) % 3;
      int row = ceil((float)move/ 3) -1;
      board[row][col] = 'X'; 
      showBoard();     
    }
    else{
      computerMove();
    }
}

//to show the instructions over the screen
void showInstructions (){
  cout << "-------------------------------------------------\n";
  cout << "INSTRUCTIONS:\n";
  cout << "Choose a cell numbered from 1 to 9 as shown below \n";
  cout << "You will play the first turn.\nYou are '0', The computer is 'X'\nAll the best!";
  cout << "\n\n";
  cout << "\t\t\t 1 | 2 | 3\n";
  cout << "\t\t\t------------\n";
  cout << "\t\t\t 4 | 5 | 6\n";
  cout << "\t\t\t------------\n";
  cout << "\t\t\t 7 | 8 | 9\n";
}



//to check the diagonals
bool checkDiagonals(){
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2] && 
        board[0][0] != ' ')
        return true;
         
    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0] &&
         board[0][2] != ' ')
        return true;
 
    return false;
}

//to check columns
bool checkColumns(){
    for(int i = 0; i < 3; i++){
        if (board[0][i] == board[1][i] &&
        board[1][i] == board[2][i] &&
         board[0][i] != ' '){
             return true;
         }
    }
    return false;
}

//to check rows
bool checkRows(){
    for(int i = 0; i < 3; i++){
        if (board[i][0] == board[i][1] &&
        board[i][1] == board[i][2] &&
         board[i][0] != ' '){
             return true;
         }
    }
    return false;
}

//to check if its a draw
bool checkDraw(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == ' '){
                return false;
            }
        }
    }
    return true;
}

//to check whether the game's over
bool gameOver(){
    if(checkRows() || checkColumns() || checkDiagonals()){
        showBoard();
        return true;
    }
    return false;
}

//to show the results
void showResults(int turn){
    if(turn == 1){
        cout << "Computer Won!";
    }
    else if (turn == 0){
        cout << "You Won!❤";
    }
    else{
        cout << "It's a draw";
    }
}

//to control the whole flow
int startGame(){
    int turn = 0;
    bool draw = false;
    while(!gameOver()){
        playerMove();
        if(gameOver()){
            break;
        }
        if(checkDraw()){
            turn = -2;
            break;
        }
        turn = 1;
        computerMove();
        if(gameOver()){
            break;
        }
        if(checkDraw()){
            turn = -2;
            break;
        }
        turn = 0;
    }
    showResults(turn);
}



//main function
int main (){
  cout << "Welcome to TIC-TAC-TOE" << endl;
  cout << "Developed by: Shubham Thakur" << endl;  
  showInstructions ();
  cout << "\n=================================\n";
  cout << "START\n";
  cout << "=================================\n\n";
  startGame();
  return 0;
}
