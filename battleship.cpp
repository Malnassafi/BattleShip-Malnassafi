#include"battleship.h"
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>

using namespace std;

// Constructer 
board::board() 
{ 
        computer = "Computer";
        
        setBoard(PLAYER_BOARD);
        setBoard(COMPUTERS_BOARD);
        setBoard(COMPUTER_DISPLAY_BOARD);
}

// A helper function that helps the constructer to set the boards to a default state
void board::setBoard(char array[NUM_OF_ROWS][NUM_OF_COLS])
{

        array[0][0] = '*';
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
        
        //Rows
        array[1][0] = '1';
        array[2][0] = '2';
        array[3][0] = '3';
        array[4][0] = '4';
        array[5][0] = '5';
        array[6][0] = '6';
        array[7][0] = '7';
        array[8][0] = '8';
        array[9][0] = '9';
      
        for (int r = 1; r < NUM_OF_ROWS; r++)
        {
                for (int c = 1; c < NUM_OF_COLS; c++)
                {
                        array[r][c] = IS_WATER;
                }
        }
}

// A function that displays the boards
void board::displayGameBoard( char array[NUM_OF_ROWS][NUM_OF_COLS] , string name )
{
        cout<<"\n     - "<<name<<"'s Board -\n";
        for (int r = 0; r < NUM_OF_ROWS; r++)
        {   
                for (int c = 0; c < NUM_OF_COLS; c++)
                {
                        cout<<array[r][c]<<"  ";
                }
                cout<<endl;
        }
}

// A function that checks weather to display the player board or the computer board
void board::displayBoard(string check)
{
        if(check == playerName)
        {
                displayGameBoard(PLAYER_BOARD, playerName);
        }
        else if(check == computer)
        {
                displayGameBoard( COMPUTER_DISPLAY_BOARD , computer );
        }
}

// A function that counts the number of ships on a board
int board::numOfShips(char array[NUM_OF_ROWS][NUM_OF_COLS])
{
        int k = 0;

        for(int r = 0; r < NUM_OF_ROWS; r++)
        {
                for(int c = 0; c < NUM_OF_COLS; c++)
                {
                        if(array[r][c] == IS_SHIP)
                                k++;
                }
        }
        return k;
}

// A function that checks weather to count the players number of ships or the computer number of ships
int board::numberOfShips(string check)
{
        int number;
        if(check == playerName)
        {
                number =  numOfShips(PLAYER_BOARD);
                return number;
        }
        else if(check == computer)
        {
                number = numOfShips(COMPUTERS_BOARD);
                return number;
        }
}

// A function that sets the player name to whatever the player inputed in main.cpp
void board::setName(string name)
{
        playerName = name;
}

// A function that checks weather its the player or computers turn to attack
void board::attack(string check)
{
        if(check == playerName)
        {
                playerAttack(COMPUTERS_BOARD);
        }
        else if(check == computer)
        {
                computerRandomGeneratedAttack(PLAYER_BOARD);
        }
}

// A function that checks weather its the players or computers turn to place ships
void board::placeShips(string check)
{
        if(check == playerName)
        {
                placeYourShips(PLAYER_BOARD);
        }
        else if(check == computer)
        {
                computerRandomGenerateShips(COMPUTERS_BOARD);
        }
}

// A function that askes and places the ships where the player wants
void board::placeYourShips(char array[NUM_OF_ROWS][NUM_OF_COLS])
{
        int row, col, k = 0;
        while(k < MAX_NUM_OF_SHIPS)
        {
                cout<<"Please enter the location you would like to put your ships (exp 2 3) (dont forget the max num of ships is 8!)\n";
                cin >> row >> col ;
                if((row > 0 && row <= NUM_OF_ROWS) && (col > 0 && col <= NUM_OF_COLS))
                {
                        if(array[row][col] == IS_WATER)
                        {
                                array[row][col] = IS_SHIP;
                                k++;
                        }
                        else
                        {
                                cerr<<"There is already a ship in that location!(please try again)\n\n";
                        }
                }
                else
                {
                        cerr<<"The location you choose is out of bound please choose another one withen the board!\n\n";
                }
        }

}

// A function that randomly generates ships for the computer and places them
void board::computerRandomGenerateShips(char array[NUM_OF_ROWS][NUM_OF_COLS])
{
        int r, c, k = 0;
        while(k < MAX_NUM_OF_SHIPS)
        {
                r = rand() % NUM_OF_ROWS;
                c = rand() % NUM_OF_COLS;
                if(array[r][c] == IS_WATER)
                {
                        array[r][c] = IS_SHIP;
                        k++;
                }
        }

}

// A function that askes where the player would like to attack and attack the computers board
void board::playerAttack(char array[NUM_OF_ROWS][NUM_OF_COLS])
{

        int rw, cl, k;
        cout<<"\n\nIt's your turn brave sailer!\n\n";
        do{
                cout<<"Where would you like to attack? (exp 2 2)\n";
                cin >> rw >> cl;
                if( (rw > 0 && rw <= NUM_OF_ROWS) && (cl > 0 && cl <= NUM_OF_COLS) )
                {
                        k = 0;
                        if(array[rw][cl] == IS_WATER)
                        {
                                array[rw][cl] = IS_MISSED;
                                COMPUTER_DISPLAY_BOARD[rw][cl] = IS_MISSED;
                                cout<<"\n==================================\n";
                                cout<<"====You Missed The Enemy ship!====\n";
                                cout<<"==================================\n";

                        }
                        else if(array[rw][cl] == IS_SHIP)
                        {
                                array[rw][cl] = IS_HIT;
                                COMPUTER_DISPLAY_BOARD[rw][cl] = IS_HIT;
                                cout<<"\n==================================\n";
                                cout<<"======You Hit The Enemy Ship!=====\n";
                                cout<<"==================================\n";
                        }
                        else if(array[rw][cl] == IS_HIT)
                        {
                                k = 1;
                                cerr<<"You already hit that ship! Please try again\n";
                        }
                        else if(array[rw][cl] == IS_MISSED)
                        {
                                k = 1;
                                cerr<<"You already missed on that location! Please try again\n";
                        }
                }
                else
                {
                        cerr<<"The location you choose is out of bounds! Please choose another location within the gameboard\n";
                        k = 1;
                }
        }while( (array[rw][cl] != IS_HIT && array[rw][cl] != IS_MISSED) || k == 1);
}

// A functionn that randomly generates an attack on the players board
void board::computerRandomGeneratedAttack(char array[NUM_OF_ROWS][NUM_OF_COLS])
{
        cout<<"\n\nIts the Computers turn\n\n";
        int r, c, k;
        do{
                r = rand() % NUM_OF_ROWS;
                c = rand() % NUM_OF_COLS;
                if( (r > 0 && r <= NUM_OF_ROWS) && (c > 0 && c <= NUM_OF_COLS) )
                {
                        k = 0;
                        if(array[r][c] == IS_WATER)
                        {
                                array[r][c] = IS_MISSED;
                                cout<<"\n==================================\n";
                                cout<<"========The Computer Missed!======\n";
                                cout<<"==================================\n";
                        }
                        else if(array[r][c] == IS_SHIP)
                        {
                                array[r][c] = IS_HIT;
                                cout<<"\n==================================\n";
                                cout<<"====The Computer Hit Your Ship!===\n";
                                cout<<"==================================\n";
                        }
                        else if(array[r][c] == IS_HIT)
                        {
                                k = 1;
                        }            
                        else if(array[r][c] == IS_MISSED)
                        {
                                k = 1;
                        }
                }
                else
                {
                        k = 1;
                }
        }while( (array[r][c] != IS_HIT && array[r][c] != IS_MISSED) || k == 1);
}
