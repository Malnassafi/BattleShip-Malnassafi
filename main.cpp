#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;
const int NUM_OF_ROWS = 11;
const int NUM_OF_COLS = 11;
const int SHIP_TYPES = 4;

const char IS_HIT = '!';
const char IS_WATER = 'x';
const char IS_MISSED = 'O';
const char IS_SHIP = 'S';

char PLAYER_BOARD[NUM_OF_ROWS][NUM_OF_COLS];
char COMPUTERS_BOARD[NUM_OF_ROWS][NUM_OF_COLS];

bool readyToPlay();
void displayBoard(char  array[NUM_OF_ROWS][NUM_OF_COLS]);

int main()
{
        readyToPlay();
        displayBoard(PLAYER_BOARD);

        return 0;
}

bool readyToPlay()
{   
        char chaek;
        cout<<"********************************\n";
        cout<<"********************************\n";
        cout<<"*********BattleShipGame*********\n";
        cout<<"********************************\n";
        cout<<"********************************\n";
        cout<<"\n" //intro to the game and rules 
}
void displayBoard(char  array[NUM_OF_ROWS][NUM_OF_COLS])
{
        array[0][0] = '.';
        //Coloums
        array[0][1] = '1';
        array[0][2] = '2';
        array[0][3] = '3';
        array[0][4] = '4';
        array[0][5] = '5';
        array[0][6] = '6';
        array[0][7] = '7';
        array[0][8] = '8';
        array[0][9] = '9'; 
        array[0][10] = '0';
        //Rows
        array[1][0] = 'A';
        array[2][0] = 'B';
        array[3][0] = 'C';
        array[4][0] = 'D';
        array[5][0] = 'E';
        array[6][0] = 'F';
        array[7][0] = 'G';
        array[8][0] = 'H';
        array[9][0] = 'I';
        array[10][0] = 'J'; 
        for (int r = 1; r < NUM_OF_ROWS; r++)
        {       
                for (int c = 1; c < NUM_OF_COLS; c++)
                {       
                        array[r][c] = IS_WATER;
                }
        }

        for (int r = 0; r < NUM_OF_ROWS; r++)
        {       
                for (int c = 0; c < NUM_OF_COLS; c++)
                {       
                        cout<<array[r][c]<<"  ";
                }    
                cout<<endl;
        }

}




//Initialize default variables
//Create game board

//Loop till all ships are placed
//Draw board
//A player places ships
// Toggle to next player

//Game Loop Start
//Player X inputs valid attack grid
// Check to see if attack is a hit
// Remove/add damage to hit ships
// Redraw game board
// Check to see if game is over
// If game over - exit loop/end program
// Toggle next player's turn
//Game Loop Return
