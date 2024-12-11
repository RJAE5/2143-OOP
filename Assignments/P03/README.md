## P03 - SFML Knucklebones
### Rykir Evans
### Description:

Program 3 is the culmination of all that we had learned in SFML and emphasizing heavy use of the principles and concepts of OOP. This program aims to create a simplified, but accurate, version of the Knucklebones game, which involves rolling a die and placing values within a grid to get a high score. There is a strategy to gathering points, utilizing the following rules:

* Two of the same number in one column doubles the value of those two numbers added.
     * i.e. 5 and 5 makes 20.
* Three of the same number in one column triples the value of those three numbers added.
     * i.e. 3, 3, and 3 makes 27

Ultimately, Knucklebones attempted and succeeded to solidify the numerous OOP concepts, as well as taught us a gaming library to add to our arsenal.

### Files

|   #   | File                                     | Description                          |
| :---: | ---------------------------------------- | ------------------------------------ |
|   1   | [dice.hpp](./dice.hpp)                   | Class for making dice and animations |
|   2   | [game.hpp](./game.cpp)                   | Class for handling game info         |
|   3   | [grid.hpp](./grid.hpp)                   | Class for handling grid info         | 
|   4   | [main.cpp](./main.hpp)                   | Main game driver and initialization  |
|   5   | [player.hpp](./player.hpp)               | Class for handling player info       |

### Instructions

**Setup**
- Make sure you install SFML by using apt: 
     - `sudo apt-get install libsfml-dev`(for Linux)
     - `brew install sfml` (for Mac)
- Compile the program and link it to SFML libraiesy: `g++ -o main main.cpp -Ipath/to/sfml/include -Lpath/to/sfml/lib -lsfml-graphics -lsfml-window -lsfml-system`
     - Alternatively, if applicable, use your own SFML compiler
- Run the compiled program: `./main`

**Gameplay**
- You will be prompted to enter a username, once you have input your username, press enter and the game will begin
- To interact with the game, you will need to press the spacebar to execute a die roll
- Once the die has finished rolling, you will need to click a column of the grid to place the number
     - Using the rules from `Description`, try to get the highest score possible
- Repeat the above steps until the grid is full
- Your game will be complete once the grid is full and it will display `GAME OVER` as well as your final score