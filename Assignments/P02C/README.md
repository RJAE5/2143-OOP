## P03 - ncurses Knucklebones
### Rykir Evans
### Description:

This portion of Program 2 serves as the attempt at creating the Knucklebones game using ncurses.
Unfortunately, it would never work as intended and we would ultimately end up switching to SFML to make Knucklebones.
The code that works will allow you to roll a dice and input whatever number into the grid any number of times. 

### Files

|   #   | File                                     | Description                       |
| :---: | ---------------------------------------- | --------------------------------- |
|   1   | [button_class.hpp](./button_class.hpp)   | Header for making a button        |
|   2   | [color_class.hpp](./color_class.hpp)     | Header for setting up color       |
|   3   | [dice_class.hpp](./dice_class.hpp)       | Header for making dice            |
|   4   | [game.cpp](./game.cpp)                   | Main game running program         |
|   5   | [grid_class.hpp](./grid_class.hpp)       | Header file for making a grid     | 
|   6   | [input_class.hpp](./input_class.hpp)     | Header for handling input         |
|   7   | [logger_class.hpp](./logger_class.hpp)   | Logger for errors and debugging   |

### Instructions

- If you plan to run the code...
- Make sure you install library by using apt: `sudo apt install libncurses5-dev libncursesw5-dev`
- Compile the program and link it to ncurses library: `g++ game.cpp -o main -lncurses`
- Run the compiled program: `./main`