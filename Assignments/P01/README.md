## P01 Fraction Class

### Rykir Evans
### Description:
This program explores overloading operators to be able to simply do arithmetic with fractions from the command line as well as an input file with added measures to accept longer numerators and denominators.

### Files:
|  #  | File                             | File Description                                     |
| :-: | -------------------------------- | ---------------------------------------------------- |
|  1  | [main.cpp](./main.cpp)           |  Main file which reads in from data file.            |
|  2  | [Fraction.cpp](./Fraction.cpp)   |  Class file for operator overloads and other func.   |
|  3  | [Fraction.h](./Fraction.h)       |  Header file for fraction class                      |
|  4  | [data.txt](./data.txt)           |  Data file to list several fractions                 |

### Instructions:
Input fractions directly into `data.txt` using `x/y + j/k` format and reference the file using  `./main < data.txt`
Alternatively, call `./main` and enter fractions directly into the terminal, using `ctrl ` + `z` to exit runtime.
The correct answer will be displayed to the console following a restatement of the fraction operation.

- Example Command:
    - `./main < data.txt`
    - `./main ` and then enter `1/2 + 5/7`
