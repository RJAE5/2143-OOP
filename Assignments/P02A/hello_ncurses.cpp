/*****************************************************************************
*
*  Author:           Rykir Evans
*  Email:            rjevans0408@my.msutexas.edu
*  Label:            P02A
*  Title:            Ncurses Test
*  Course:           CMPS 2143 OOP
*  Professor:        Terry Griffin
*  Semester:         Fall 2024
*
*  Description:
*        This portion of the program serves as proof of installing ncurses successfully 
*
*  Files:           hello_ncurses.cpp
*                   ncurses_proof.png
*******************************************************************************/

#include <ncurses.h>

int main() {
    initscr();            // Start ncurses mode
    printw("Hello, World!"); // Print message on the screen
    refresh();            // Refresh to show the message
    getch();              // Wait for user input
    endwin();             // End ncurses mode
    return 0;
}