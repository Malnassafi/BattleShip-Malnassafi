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
* void return type function : []()
* bool return type function : []()
* int return type function : []()
* Pass-by-value : []()
* Pass-by-refrence: [main.cpp on line 73](/main.cpp#L73) i made it pass by refrence becasue i want it after the player has inputed his name into the void function to be saved in name string in the int main function.
# File I/O:
* File Output: [main.cpp on lines 25-38](/main.cpp#L25) where it outputs who won last game, the player or the computer.
* File Input: [main.cpp on line 107-109 & 118-120](/main.cpp#L107) where it saves who won the computer or the player.
# Class:
* Board class: [battleship.h on line 20](/battleship.h#L20)

