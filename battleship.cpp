#include"battleship.h"
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>

using namespace std;

board::board()
{ 
        NUM_OF_ROWS = 10;
        NUM_OF_COLS = 10;
        MAX_NUM_OF_SHIPS = 8;

        IS_HIT = '!';
        IS_WATER = '_';
        IS_MISSED = 'O';
        IS_SHIP = 'S';
        
        PLAYER_BOARD[0][0] = '*';
        //Coloums
        PLAYER_BOARD[0][1] = '1';
        PLAYER_BOARD[0][2] = '2';      
        PLAYER_BOARD[0][3] = '3';              
        PLAYER_BOARD[0][4] = '4';                      
        PLAYER_BOARD[0][5] = '5';                              
        PLAYER_BOARD[0][6] = '6';                                      
        PLAYER_BOARD[0][7] = '7';                                              
        PLAYER_BOARD[0][8] = '8';                                                      
        PLAYER_BOARD[0][9] = '9';

        //Rows
        PLAYER_BOARD[1][0] = '1';
        PLAYER_BOARD[2][0] = '2';
        PLAYER_BOARD[3][0] = '3';
        PLAYER_BOARD[4][0] = '4';
        PLAYER_BOARD[5][0] = '5';
        PLAYER_BOARD[6][0] = '6';
        PLAYER_BOARD[7][0] = '7';
        PLAYER_BOARD[8][0] = '8';
        PLAYER_BOARD[9][0] = '9';


        for (int r = 1; r < NUM_OF_ROWS; r++)
        {                               
                for (int c = 1; c < NUM_OF_COLS; c++)
                {                               
                        PLAYER_BOARD[r][c] = IS_WATER;
                }                                       
        }

        COMPUTERS_BOARD[0][0] = '*';
        //Coloums
        COMPUTERS_BOARD[0][1] = '1';
        COMPUTERS_BOARD[0][2] = '2';
        COMPUTERS_BOARD[0][3] = '3';
        COMPUTERS_BOARD[0][4] = '4';
        COMPUTERS_BOARD[0][5] = '5';
        COMPUTERS_BOARD[0][6] = '6';
        COMPUTERS_BOARD[0][7] = '7';
        COMPUTERS_BOARD[0][8] = '8';
        COMPUTERS_BOARD[0][9] = '9';

        //Rows
        COMPUTERS_BOARD[1][0] = '1';
        COMPUTERS_BOARD[2][0] = '2';
        COMPUTERS_BOARD[3][0] = '3';
        COMPUTERS_BOARD[4][0] = '4';
        COMPUTERS_BOARD[5][0] = '5';
        COMPUTERS_BOARD[6][0] = '6';
        COMPUTERS_BOARD[7][0] = '7';
        COMPUTERS_BOARD[8][0] = '8';
        COMPUTERS_BOARD[9][0] = '9';


        for (int r = 1; r < NUM_OF_ROWS; r++)
        {
                for (int c = 1; c < NUM_OF_COLS; c++)
                {
                        COMPUTERS_BOARD[r][c] = IS_WATER;
                }
        }


}

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

void board::displayBoard(string cheak)
{
        if(cheak == playerName)
        {
                displayGameBoard( PLAYER_BOARD , playerName );
        }
        else if(cheak == computer)
        {
                displayGameBoard( COMPUTERS_BOARD , computer );
        }
}
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

int numberOfShips(string cheak)
{
        if(cheak == playerName)
        {
                numOfShips(PLAYER_BOARD);
        }
        else if(cheak == computer)
        {
                numOfShips(COMPUTERS_BOARD);
        }
}

void board::setName(string name)
{
        playerName = name;
        computer = "Computer";
}

void board::attack(string cheak)
{
        if(cheak == playerName)
        {
                playerAttack(COMPUTERS_BOARD);
        }
        else if(cheak == computer)
        {
                computerRandomGeneratedAttack(PLAYER_BOARD);
        }
}

void board::placeShips(string cheak)
{
        if(cheak == playerName)
        {
                placeYourShips(PLAYER_BOARD);
        }
        else if(cheak == computer)
        {
                computerRandomGenerateShips(COMPUTERS_BOARD);
        }
}

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

void board::playerAttack(char array[NUM_OF_ROWS][NUM_OF_COLS])
{

        nt rw, cl, k;
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
                                cout<<"\n==================================\n";
                                cout<<"====You Missed The Enemy ship!====\n";
                                cout<<"==================================\n";
                        }
                        else if(array[rw][cl] == IS_SHIP)
                        {
                                array[rw][cl] = IS_HIT;
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
