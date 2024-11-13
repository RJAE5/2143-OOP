# WIP

## Current error:
The code currently runs, though the dice look funky.
These warnings are displayed when I compile the code:


```
In file included from main.cpp:4:
button_class.hpp: In member function ‘void Button::draw_button()’:
button_class.hpp:48:18: warning: format not a string literal and no format arguments [-Wformat-security]
   48 |         mvwprintw(button_win, hmiddle, wmiddle, text.c_str());
      |         ~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from dice_class.hpp:6,
                 from main.cpp:6:
logger_class.hpp: In static member function ‘static void Logger::printLastLine(WINDOW*)’:
logger_class.hpp:117:18: warning: format not a string literal and no format arguments [-Wformat-security]
  117 |         mvwprintw(win, 0, 0, lastLine.c_str());
      |         ~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from main.cpp:7:
grid_class.hpp: In member function ‘void Grid::printValues()’:
grid_class.hpp:86:30: warning: format not a string literal and no format arguments [-Wformat-security]
   86 |                     mvwprintw(win, y, x, to_string(values[i][j]).c_str());
      |                     ~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from main.cpp:8:
input_class.hpp: In member function ‘void Input::printBorder()’:
input_class.hpp:60:18: warning: format not a string literal and no format arguments [-Wformat-security]
   60 |         mvwprintw(input_win, 1, 1, prompt.c_str());  // Label inside the box
```