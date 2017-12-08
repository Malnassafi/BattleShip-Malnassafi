#include"battleship.h"
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>
#include<fstream>

using namespace std;
// NO MAGIC NUMBERS!
const int MAX_NUM_OF_GUESSES = (NUM_OF_ROWS - 1) * (NUM_OF_COLS - 1);
// PROTOTYPES
bool readyToPlay(string &);
bool cheakWinner(int, int, string);

// main function starts
int main()
{
        srand( time (NULL) );
        board Player;
        ifstream inFile;
        string player, line, Cpu = "Computer";
        bool play, cheaker, check;
        int gamer, cpu;

        inFile.open("battleship.txt");
        check = inFile.is_open();
        if(check == false)
        {
               inFile.open("battleship.txt");
               inFile.close();
        } 
        else
        {
                while(getline(inFile,line) && line != "")
                {              
                        cout<<"\n\n\n\n\n "<<line<<" \n\n\n\n\n";
                }
                inFile.close();
        }
        play = readyToPlay(player);
        if(play == true)
        {       
                Player.setName(player);
                Player.displayBoard(player);
                Player.displayBoard(Cpu);
                Player.placeShips(player);
                Player.placeShips(Cpu);
                Player.displayBoard(player);
                Player.displayBoard(Cpu);

                for(int r = 0; r < MAX_NUM_OF_GUESSES; r++)
                {       
                        Player.attack(player);
                        Player.displayBoard(Cpu);
                        Player.attack(Cpu);
                        Player.displayBoard(player);
                        gamer = Player.numberOfShips(player);
                        cout<<"\nYou have "<<gamer<<" Ships left!\n";
                        cpu = Player.numberOfShips(Cpu);
                        cout<<"\nThe Computer has "<<cpu<<" Ships left!\n";
                        cheaker = cheakWinner(gamer, cpu, player);
                        if( cheaker == true)
                        {
                                break;
                        }
                }
        }

        return 0;
} // main function ends

// This function ask if the player is ready to play and if so it would ask his name and would return true to start the game
bool readyToPlay(string & name)
{
        char cheak;
        cout<<"\n===========Welcome==============\n";
        cout<<"================To==============\n";
        cout<<"=========BattleShipGame=========\n";
        cout<<"==============Brave=============\n";
        cout<<"==============Sailer============\n";
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

// This function will check who won weather it was the computer or the player
bool cheakWinner(int playerNumberOfShips, int computerNumberOfShips, string name)
{
        ofstream outFile;
        if( playerNumberOfShips  == 0)
        {
                cout<<"\n*=======================*\n";
                cout<<"*========You Lost=======*\n";
                cout<<"*=Better Luck Next Time=*\n";
                cout<<"*=======================*\n";
                outFile.open("battleship.txt");
                outFile<<"The Computer Won Last Game!\n";
                outFile.close();
                return true;
        }
        else if( computerNumberOfShips  == 0)
        {
                cout<<"\n*================================*\n";
                cout<<"*=============You Won============*\n";
                cout<<"*=You Sunk All The Enemys Ships!=*\n";
                cout<<"*================================*\n";
                outFile.open("battleship.txt");
                outFile<<name<<" Won Last Game!\n";
                outFile.close();
                return true;
        }
        else
        {
                return false;
        }
}

