## P02A - Ncurses Test
### Rykir Evans
### Description:

This portion of Program 2 serves as proof that we have successfully installed the ncurses library and were able to run a simple program. 

### Files

|   #   | File                                     | Description                       |
| :---: | ---------------------------------------- | --------------------------------- |
|   1   | [hello_ncurses.cpp](./hello_ncurses.cpp) | Simple test program using ncurses |
|   2   | [ncurses_proof.png](./ncurses_proof.png) | Image proof of running program    |

### Instructions

- Observe the image serving as proof of running the ncurses program
- If you plan to run the code...
- Make sure you install library by using apt: `sudo apt install libncurses5-dev libncursesw5-dev`
- Compile the program and link it to ncurses library: `g++ hello_ncurses.cpp -o hello_ncurses -lncurses`
- Run the compiled program: `./hello_ncurses`

### Image Proof
<img src=ncurses_proof.png width=1000>