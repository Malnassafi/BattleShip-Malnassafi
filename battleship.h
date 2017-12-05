#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>

using namespace std;

const int NUM_OF_ROWS = 10;
const int NUM_OF_COLS = 10;
const int MAX_NUM_OF_SHIPS = 8;

const char IS_HIT = '!';
const char IS_WATER = '_';
const char IS_MISSED = 'O';
const char IS_SHIP = 'S';

class board
{
        private:
                string playerName; 
                string computer;
                
                char PLAYER_BOARD[NUM_OF_ROWS][NUM_OF_COLS];
                char COMPUTERS_BOARD[NUM_OF_ROWS][NUM_OF_COLS];
                char COMPUTER_DISPLAY_BOARD[NUM_OF_ROWS][NUM_OF_COLS];

                void placeYourShips(char array[NUM_OF_ROWS][NUM_OF_COLS]);
                void computerRandomGenerateShips(char array[NUM_OF_ROWS][NUM_OF_COLS]);
                void playerAttack(char array[NUM_OF_ROWS][NUM_OF_COLS]);
                void computerRandomGeneratedAttack(char array[NUM_OF_ROWS][NUM_OF_COLS]);
                void displayGameBoard(char  array[NUM_OF_ROWS][NUM_OF_COLS], string);
                int numOfShips(char array[NUM_OF_ROWS][NUM_OF_COLS]);
        public:
                board();
                void displayBoard(string);
                int  numberOfShips(string);
                void setName(string);
                void attack(string);
                void placeShips(string);
};

/*class player
  {
  private:
  string playerName; 
  board gamer;

  void placeYourShips(char array[NUM_OF_ROWS][NUM_OF_COLS], string);
  void computerRandomGenerateShips(char array[NUM_OF_ROWS][NUM_OF_COLS]);
  void playerAttack(char array[NUM_OF_ROWS][NUM_OF_COLS]);
  void computerRandomGeneratedAttack(char array[NUM_OF_ROWS][NUM_OF_COLS], string);
  public:
  void setName(string ); // take the name from the main.cpp and change the playerName to it
  void attack(string);
  void placeShips(string);i
//we can call the board inside player and not call it inside int main
//we can 

}; */
#endif
