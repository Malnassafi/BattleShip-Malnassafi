#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>

using namespace std;

const int NUM_OF_ROWS = 11;
const int NUM_OF_COLS = 11;
const int MAX_NUM_OF_SHIPS = 8;

const char IS_HIT = '!';
const char IS_WATER = '_';
const char IS_MISSED = 'O';
const char IS_SHIP = 'S';

char PLAYER_BOARD[NUM_OF_ROWS][NUM_OF_COLS];
char COMPUTERS_BOARD[NUM_OF_ROWS][NUM_OF_COLS];

bool readyToPlay(string &);
void displayBoard(char  array[NUM_OF_ROWS][NUM_OF_COLS], string);
void placeYourShips(char array[NUM_OF_ROWS][NUM_OF_COLS], string);
void computerRandomGenerateShips();
int main()
{
        string Player, Computer;
        bool play;
        play = readyToPlay(Player);
        if(play == true)
        {
                displayBoard(PLAYER_BOARD, Player);
                displayBoard(COMPUTERS_BOARD, "Computer");
                placeYourShips(PLAYER_BOARD, Player);
                computerRandomGenerateShips();
        }
        return 0;
}

bool readyToPlay(string & name)
{   
        char cheak;
        cout<<"\n********************************\n";
        cout<<"********************************\n";
        cout<<"*********BattleShipGame*********\n";
        cout<<"********************************\n";
        cout<<"********************************\n";
        cout<<"\n The game goes as followes:\n Whoever destroyes all the others ships win!\n";
        cout<<"_ stands for the water,\n S stands for your ships,\n ! stands for the ships that you or the Computer hit,\n O stands for every time you or the Computer misses \n"; 
        cout<<"ARE YOU READY TO DESTROY YOUR ENEMY? Y/N\n";
        cin>>cheak;
        if(cheak  == 'y' || cheak == 'Y')
        { 
                cout<<"PLEASE ENETER YOUR NAME BRAVE SAILER\n";
                cin>>name;
                return true;
        }
        else
        {
                return false;
        }
}

void placeYourShips(char array[NUM_OF_ROWS][NUM_OF_COLS], string name)
{
        int row, col, k = 0;
        while(k < MAX_NUM_OF_SHIPS)
        {
                cout<<"Please enter the location you would like to put your ships (exp 2 3) (dont forget the max num of ships is 8!)\n";
                cin >> row >> col ;
                if(row > 1 && row <= NUM_OF_ROWS && col > 1 && col <= NUM_OF_COLS)
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

        cout<<"\n     - "<<name<<"'s Board -\n";
        for (int r = 0; r < NUM_OF_ROWS; r++)
        {
                for (int c = 0; c < NUM_OF_COLS; c++)
                {
                        cout<<PLAYER_BOARD[r][c]<<"  ";
                }
                cout<<endl;
        }
}

void displayBoard(char  array[NUM_OF_ROWS][NUM_OF_COLS], string name)
{
        array[0][0] = '*';
        //Coloums
        array[0][1] = '0';
        array[0][2] = '1';
        array[0][3] = '2';
        array[0][4] = '3';
        array[0][5] = '4';
        array[0][6] = '5';
        array[0][7] = '6';
        array[0][8] = '7';
        array[0][9] = '8'; 
        array[0][10] = '9';
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

void computerRandomGenerateShips()
{
        int r, c, k = 0;
        while(k < MAX_NUM_OF_SHIPS)
        {
                r = rand() % NUM_OF_ROWS;
                c = rand() % NUM_OF_COLS;
                if(COMPUTERS_BOARD[r][c] != 'S')
                {
                        COMPUTERS_BOARD[r][c] = 'S';
                        k++;
                }
        }
        
        cout<<"\n     - Computer's Board -\n";
        for (int r = 0; r < NUM_OF_ROWS; r++)
        {
                for (int c = 0; c < NUM_OF_COLS; c++)
                {
                        cout<<COMPUTERS_BOARD[r][c]<<"  ";
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
