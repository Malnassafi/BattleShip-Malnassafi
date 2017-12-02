#include"battleship.h"
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>
#include<fstream>

using namespace std;

const int MAX_NUM_OF_GUESSES = 81;

bool readyToPlay(string &);

int main()
{
        srand( time (NULL) );
        board Player;
        ifstream inFile;
        ofstream outFile;
        string player, line;
        bool play;
        int gamer, cpu;
        string Cpu = "Computer";
        
        inFile.open("battleship.txt");
        while(getline(inFile,line) && line != "")
        {       
                cout<<line<<" \n";
        }
        inFile.close();
        play = readyToPlay(player);
        if(play == true)
        {       
                Player.setName(player);
                Player.displayBoard(player);
                Player.displayBoard(Cpu);
                Player.placeShips(player);
                Player.placeShips(Cpu);
                
                for(int r = 0; r < MAX_NUM_OF_GUESSES; r++)
                {       
                        Player.attack(player);
                        Player.displayBoard(player);
                        Player.attack(Cpu);
                        Player.displayBoard(Cpu);
                        gamer = Player.numberOfShips(player);
                        cout<<"\nYou have "<<gamer<<" Ships left!\n";
                        cpu = Player.numberOfShips(Cpu);
                        cout<<"\nThe Computer has "<<cpu<<" Ships left!\n";
                        if( gamer == 0)
                        {       
                                cout<<"\n*=======================*\n";
                                cout<<"*========You Lost=======*\n";
                                cout<<"*=Better Luck Next Time=*\n";
                                cout<<"*=======================*\n";
                                outFile.open("battleship.txt");
                                outFile<<"The Computer Won Last Game!\n";
                                outFile.close();
                                break;
                        }
                        else if( cpu == 0)
                        {       
                                cout<<"\n*================================*\n";
                                cout<<"*=============You Won============*\n";
                                cout<<"*=You Sunk All The Enemys Ships!=*\n";
                                cout<<"*================================*\n";
                                outFile.open("battleship.txt");
                                outFile<<player<<" Won Last Game!\n";
                                outFile.close();
                                break;
                        }
                }

        }

        return 0;
}

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

