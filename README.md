# BattleShip-Malnassafi
BattleShip is a board game where you play against a computer. First you place your ships on your board and then the computer randomly generates its ships on its board. After that the games starts, then tha game goes in a loop where you guess the place of the computers ships and the computer does the same. Whoever destroyes all the enemies ships wins. 
# Input & OutPut:
* Ask user: [main.cpp on lines 72 & 73](/main.cpp#L72) if he is ready to play the game.
* Ask user: [main.cpp on lines 76 & 77](/main.cpp#L76) for his name and saves it.
* Ask user: [battleship.cpp lines 198 & 199](/battleship.cpp#L198) where he would like to place his ships.
* Ask user: [battleship.cpp lines 242 & 243](/battleship.cpp#L242) where he would like to attack.
# Control flow:
* If : [main.cpp on line 31](/main.cpp#L31) runs through the if statement if the player wants to play.
* If & else : [main.cpp on lines 74 & 80](/main.cpp#L74) runs the if statement if the player wants to play if not it will run the else statement.
* If, else if & else: [main.cpp on lines 89, 100 & 111](/main.cpp#L89) it will run the if statement if the player has 0 ships left or the else if statement if the computer has 0 ships left or the else statement if niether of them were true.
* If & else if : [battleship.cpp on lines 125 & 129](/battleship.cpp#L125) it would check the string, if it was the player it would run the if statement and if it was the computer it would run the else if statement.
* If & else if : [battleship.cpp on lines 152 & 157](/battleship.cpp#L152) it would check the string, if it was the player it would run the if statement and if it was the computer it would run the else if statement.
* If & else if : [battleship.cpp on lines 171 & 175](/battleship.cpp#L171) it would check the string, if it was the player it would run the if statement and if it was the computer it would run the else if statement.
* If & else if : [battleship.cpp on lines 183 & 187](/battleship.cpp#L183) it would check the string, if it was the player it would run the if statement and if it was the computer it would run the else if statement.
* If(inner if & else) & else: [battleship.cpp on lines 200-215](/battleship.cpp#L200)
* If : [battleship.cpp on line 227](/battleship.cpp#L227) would check if the location of the random generated computer numbers is set to water so that it would set it to ship.
* If(inner if & 3 else if's) & else : [battleship.cpp on lines 244-279](/battleship.cpp#L244)
* If(inner if & 3 else if's) & else : [battleship.cpp on lines 290-319](/battleship.cpp#L290)
# Iteration:
* 
# Data structures: 
*
# Functions:
* Pass-by-refrence: [main.cpp on line 82](/main.cpp#L62)
*
# File I/O:
* File Output: [main.cpp on lines 24-29](/main.cpp#L24) where it outputs who won last game, the player or the computer.
* File Input: [main.cpp on line 95-97 & 106-108](/main.cpp#L95) where it saves who won the computer or the player.
# Class:
* Board class: [bitmap.h on line 20](/battleship.h#L20)

