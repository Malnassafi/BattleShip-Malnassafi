#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>
#include<fstream> //make a fstream that inputs after each game who won, the player or the computer
/* TO DOES:
 ** Make a function that cheaks if anyone has won; (DONE)
 ** Make it so that the computers ship cant be seen by the player;
 */

using namespace std;

const int NUM_OF_ROWS = 10;
const int NUM_OF_COLS = 10;
const int MAX_NUM_OF_SHIPS = 8;
const int MAX_NUM_OF_GUESSES = 81;

const char IS_HIT = '!';
const char IS_WATER = '_';
const char IS_MISSED = 'O';
const char IS_SHIP = 'S';

//char PLAYER_BOARD[NUM_OF_ROWS][NUM_OF_COLS];
//char COMPUTERS_BOARD[NUM_OF_ROWS][NUM_OF_COLS];

bool readyToPlay(string &);
void displayBoard(char  array[NUM_OF_ROWS][NUM_OF_COLS], string);
void placeYourShips(char array[NUM_OF_ROWS][NUM_OF_COLS], string);
void computerRandomGenerateShips(char array[NUM_OF_ROWS][NUM_OF_COLS]);
void playerAttack(char array[NUM_OF_ROWS][NUM_OF_COLS]);
void computerRandomGeneratedAttack(char array[NUM_OF_ROWS][NUM_OF_COLS], string);
int numberOfShips(char array[NUM_OF_ROWS][NUM_OF_COLS]);

int main()
{
        srand( time (NULL) );
        char PLAYER_BOARD[NUM_OF_ROWS][NUM_OF_COLS];
        char COMPUTERS_BOARD[NUM_OF_ROWS][NUM_OF_COLS];
        string Player, Computer;
        bool play;
        int player, cpu;
        play = readyToPlay(Player);
        if(play == true)
        {
                displayBoard(PLAYER_BOARD, Player);
                displayBoard(COMPUTERS_BOARD, "Computer");
                placeYourShips(PLAYER_BOARD, Player);
                computerRandomGenerateShips(COMPUTERS_BOARD);

                for(int r = 0; r < MAX_NUM_OF_GUESSES; r++)
                {
                        playerAttack(COMPUTERS_BOARD);
                        computerRandomGeneratedAttack(PLAYER_BOARD, Player);
                        player = numberOfShips(PLAYER_BOARD);
                        cout<<"\nYou have "<<player<<" Ships left!\n";
                        cpu = numberOfShips(COMPUTERS_BOARD);
                        cout<<"\nThe Computer has "<<cpu<<" Ships left!\n";
                        if( player == 0)
                        {
                                cout<<"\n*=======================*\n";
                                cout<<"*========You Lost=======*\n";
                                cout<<"*=Better Luck Next Time=*\n";
                                cout<<"*=======================*\n";
                                break;
                        }
                        else if( cpu == 0)
                        {
                                cout<<"\n*================================*\n";
                                cout<<"*=============You Won============*\n";
                                cout<<"*=You Sunk All The Enemys Ships!=*\n";
                                cout<<"*================================*\n";
                                break;
                        }
                }

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

void displayBoard(char  array[NUM_OF_ROWS][NUM_OF_COLS], string name)
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

void computerRandomGenerateShips(char array[NUM_OF_ROWS][NUM_OF_COLS])
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

        cout<<"\n     - Computer's Board -\n";
        for (int r = 0; r < NUM_OF_ROWS; r++)
        {
                for (int c = 0; c < NUM_OF_COLS; c++)
                {
                        cout<<array[r][c]<<"  ";
                }
                cout<<endl;
        }
}

void playerAttack(char array[NUM_OF_ROWS][NUM_OF_COLS])
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
                                cout<<"\n==================================\n";
                                cout<<"====You Missed The Emeny Ship!====\n";
                                cout<<"==================================\n";
                        }
                        else if(array[rw][cl] == IS_SHIP)
                        {
                                array[rw][cl] = IS_HIT;
                                cout<<"\n==================================\n";
                                cout<<"======You Hit An Emeny Ship!======\n";
                                cout<<"==================================\n";
                        }
                        else if(array[rw][cl] == IS_HIT)
                        {
                                k = 1;
                                cout<<"You already hit that ship! Please try again\n";
                        }
                        else if(array[rw][cl] == IS_MISSED)
                        {
                                k = 1;
                                cout<<"You already missed on that location! Please try again\n";
                        }
                }
                else
                {
                        cout<<"The location you choose is out of bounds! Please choose another location within the gameboard\n";
                        k = 1;
                }
        }while( (array[rw][cl] != IS_HIT && array[rw][cl] != IS_MISSED) || k == 1);

        cout<<"\n\n     - Computer's Board -\n\n";
        for (int r = 0; r < NUM_OF_ROWS; r++)
        {
                for (int c = 0; c < NUM_OF_COLS; c++)
                {
                        cout<<array[r][c]<<"  ";
                }
                cout<<endl;
        }

}

void computerRandomGeneratedAttack(char array[NUM_OF_ROWS][NUM_OF_COLS], string name)
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
                                cout<<"The computer missed!\n";
                        }
                        else if(array[r][c] == IS_SHIP)
                        {
                                array[r][c] = IS_HIT;
                                cout<<"The computer Hit!\n";
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

        cout<<"\n\n     - "<<name<<"'s Board -\n\n";
        for (r = 0; r < NUM_OF_ROWS; r++)
        {
                for (c = 0; c < NUM_OF_COLS; c++)
                {
                        cout<<array[r][c]<<"  ";
                }
                cout<<endl;
        }
}

int numberOfShips(char array[NUM_OF_ROWS][NUM_OF_COLS])
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
