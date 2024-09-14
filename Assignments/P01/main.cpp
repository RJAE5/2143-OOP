/*****************************************************************************
*
*  Author:           Rykir Evans
*  Email:            rjevans0408@my.msutexas.edu
*  Label:            P01
*  Title:            Fraction Class
*  Course:           CMPS 2143 OOP
*  Semester:         Fall 2024
*
*  Description:
*        This Program explores overloading operators to simply do arithmetic with Fractions
*
*  Usage:
*        Call ./main and either input fractions directly into terminal or input fractions
*        data.txt using x/y + j/k format and reference the file using ./main < data.txt
*        The correct answer will be displayed to the console
*
*  Files:           data.txt
*                   Fraction.h
*                   Fraction.cpp
*                   main.cpp
*******************************************************************************/

#include <iostream>
#include "Fraction.cpp"

using namespace std;


int main(int argc, char *argv[])
{
    
    string f1,op,f2;                // Variables for fraction use
    int d1,d2,n1,n2, temp;

    while (cin >> f1 >> op >> f2) 
    { 
    int n1 = f1[0]-48;              // Assignment from input file
    int d1 = f1[2]-48;
    int n2 = f2[0]-48;
    int d2 = f2[2]-48;
    
    Fraction F1(n1, d1);            // Fraction creation
    Fraction F2(n2, d2);
    Fraction ans;

    if(op == "+")                   // if else chain to do correct arithmetic
    ans = F1 + F2;

    else if(op == "-")
    ans = F1 - F2;

    else if(op == "*")
    ans = F1 * F2;

    else if(op == "/")
    ans = F1/F2;

    else
    cout << "Invalid operator, initating self-destruct ";

    cout << ans << endl;            // Output answer to console
    }// End while loop
    
    return 0;
    
}
