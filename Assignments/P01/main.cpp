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
*        how to use the program if necessary
*
*  Files:           fraction.h
*                   fraction.cpp
*                   main.cpp
*******************************************************************************/

#include <iostream>
#include "Fraction.h"

using namespace std;

/*
Fraction
*/


int main(int argc, char **argv)
{
    
    // for(int i = 0; i < argc; i++)
    // {
    //     cout << "Argument " << i << " is: " << argv[i] << endl;
    // }

    cout << "Hellow World!" << endl;
    string f1, op, f2;
    int d1,d2,n1,n2;

    while(cin >> f1 >> op >> f2)
    {
        cout << f1 << op << f2 << endl;
        n1 = f1[0] - '0';
        d2 = f1[2] - '0';
        n1 = f2[0] - '0';
        d2 = f2[2] - '0';

    }

    return 0;
    // shell Notes
    // ls = listing
    // ll = long listing

    //ENABLE WSL IN VS CODE
    // WSL PLUGINS FOR VS CODE






    // // Console Testing purposes
    // int numer1, denom1, numer2, denom2, key;
    // Fraction ans;
    // cout << "Please enter the numerator of your first Fraction: ";
    // cin >> numer1;

    // cout << "\nPlease enter the denominator of your first Fraction: ";
    // cin >> denom1;

    // cout << "\nPlease enter the numerator of your second Fraction: ";
    // cin >> numer2;

    // cout << "\nPlease enter the denominator of your second Fraction: ";
    // cin >> denom2;

    // Fraction F1(numer1, denom1);
    // Fraction F2(numer2, denom2);

    // cout << endl << endl << "Please select the arithmetic you would like to perform:" << endl;
    // cout << "1. Addition\n"
    //     << "2. Subtraction (F1 - F2)\n"
    //     << "3. Multiplication\n\n";

    // cin >> key;
    // switch (key)
    // {
    // case 1: ans = F1 + F2; break;
    // case 2: ans = F1 - F2; break;
    // case 3: ans = F1 * F2; break;

    // default: cout << "Invalid selection, initiating self-destruct.";
    // }

    // cout << "\n\nThe answer for your arithmetic (reduced as much as possible) is: " << ans << "\nThanks for coming!\n\n";
}
