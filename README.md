# BattleShip-Malnassafi
BattleShip is a board game where you play against a computer. First you place your ships on your board and then the computer randomly generates its ships on its board. After that the games starts, then tha game goes in a loop where you guess the place of the computers ships and the computer does the same. Whoever destroyes all the enemies ships wins. 
# Input & OutPut:
* Ask user: [main.cpp on lines 83 & 84](/main.cpp#L83) if he is ready to play the game.
* Ask user: [main.cpp on lines 87 & 88](/main.cpp#L87) for his name and saves it.
* Ask user: [battleship.cpp lines 198 & 199](/battleship.cpp#L198) where he would like to attack.
* Ask user: [battleship.cpp lines 152 & 153](/battleship.cpp#L152) where he would like to place his ships.
# Control flow:
* If : [main.cpp on line 31](/main.cpp#L31) runs through the if statement if the player wants to play.
* If & else : [main.cpp on lines 74 & 80](/main.cpp#L74) runs the if statement if the player wants to play if not it will run the else statement.
* If, else if & else: [main.cpp on lines 89, 100 & 111](/main.cpp#L89) it will run the if statement if the player has 0 ships left or the else if statement if the computer has 0 ships left or the else statement if niether of them were true.
# Iteration:
* for loop : [main.cpp on line 50](/main.cpp#L51) its a for loop that will loop till the game ends.
* while loop : [battleship.cpp on line 150](/battleship.cpp#L150) its a while loop that will loop till you have the max number of ships on your board.
* do while loop : [battleship.cpp on line 197](/battleship.cpp#L197) its a do while loop that will loop till the player entered a valid place to attack.
# Data structures: 
* Two dimensional array : [battleship.h on lines 28, 29 & 30](/battleship.h#L28) created 3 two dimensional array's which are boards and on  [battleship.cpp on lines 14-53](/battleship.cpp#L14)  they are set to default.
# Functions:
* void return type function : [battleship.cpp on line 70](/battleship.cpp#L70) A function that checks weather to display the player board or the computer board.
* bool return type function : [main.cpp on line 73](/main.cpp#L73) A function ask if the player is ready to play and if so it would ask his name and would return true to start the game.
* int return type function : [battleshup.cpp on line 83](/battleship.cpp#L83) A function that counts the number of ships on a board.
* Pass-by-value : [battleship.cpp on line 115](/battleship.cpp#L115) it will pass by value a string taken from int main and set it equal to the string in the private section in the class.
* Pass-by-refrence: [main.cpp on line 73](/main.cpp#L73) i made it pass by refrence becasue i want it after the player has inputed his name into the void function to be saved in name string in the int main function.
# File I/O:
* File Output: [main.cpp on lines 25-38](/main.cpp#L25) where it outputs who won last game, the player or the computer.
* File Input: [main.cpp on line 107-109 & 118-120](/main.cpp#L107) where it saves who won the computer or the player.
# Class:
* Board class: [battleship.h on line 20](/battleship.h#L20)
* Private section : [battleship.h on line 24](/battleship.h#L24) it has two strings declared in it which is the playername and computer and 3 Two dimensional array and a couple of private function that cant be accesed through int main but other public functions can use them.
* Public section : [battleship.h on line 40](/battleship.h#L40) has a constracter and functions that have access to the private secion of the board class that can be used in int main and use the private section of the board class.

