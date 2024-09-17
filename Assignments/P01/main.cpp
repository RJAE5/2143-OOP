/*****************************************************************************
*
*  Author:           Rykir Evans
*  Email:            rjevans0408@my.msutexas.edu
*  Label:            P01
*  Title:            Fraction Class
*  Course:           CMPS 2143 OOP
*  Professor:        Terry Griffin
*  Semester:         Fall 2024
*
*  Description:
*        This Program explores overloading operators to simply do arithmetic with Fractions 
*
*  Usage:
*        Call `./main` and either input fractions directly into terminal or input fractions
*        into `data.txt`. It should be in the format `x/y + j/k` and reference the file 
*        using `./main < data.txt`. The correct answer will be displayed to the console
*       
*
*  Files:           data.txt
*                   Fraction.h
*                   Fraction.cpp
*                   main.cpp
*******************************************************************************/

#include <iostream>
#include <string>
#include <cmath>
#include "Fraction.cpp"

using namespace std;

#define MAX_PROB_LENGTH 30                                          // Max number of chars for any problem

int main()
{
    string op;                                                      // Variable for fraction operator
    char problem[MAX_PROB_LENGTH];                                  // Array for problem
    
    for(int i = 0; i < MAX_PROB_LENGTH; i++)                        // Fill char array with stop characters
        {problem[i] = '$';}         

    while(cin.getline(problem, MAX_PROB_LENGTH))                    // Loop for each line in file
    {
        int flag = 0;                                               // Counter flag for end of problem

         for(int i = 0; i < MAX_PROB_LENGTH; i++)                   // Flag increment
            {
                if(problem[i] != '$')
                    flag++;
            }

        int n1 = 0;                                                 // Fraction variables
        int d1 = 0;
        int n2 = 0;
        int d2 = 0;
        int count = 0;
        int stop = 0;
        
        while(problem[count] != '/')                                // Increment count to end of numerator 1
            {count++;}
            
            stop = count - 1;                                       // Stop indicator for the for loop

        for(int i = stop; i >= 0; i--)              
            {n1 += (problem[(stop) - i] - 48) * (pow(10,i));}       // Convert numerator 1 from chars to integer

        count++;                                                    // Hop over slash
        stop++;

        while(problem[count] != ' ' && problem[count] != '+' && problem[count] != '-' && problem[count] != '*' && problem[count] != '/')
            {count++;}                                              // Increment count to end of denominator 1
    

        for(int i = 0; i < count - stop - 1; i++)
            {d1 += (problem[(count - 1) - i] - 48) * (pow(10,i));}  // Convert denominator 1 from chars to integer
            

        if(problem[count] == '+' || problem[count] == '-' || problem[count] == '*' || problem[count] == '/')
        {op = problem[count];}                                      // Read in operator if immediate

        else
        {
            do
            {
                count++;                                            // Skip spaces to find operator
            } while(problem[count] != '+' && problem[count] != '-' && problem[count] != '*' && problem[count] != '/');
            
            op = problem[count];                                    // Alternatively read in operator because of spaces
        }

        count++;                                                    // Increment count past operator
        
        if(problem[count] == ' ')                                   // Increment count past spaces
        {
            while(problem[count] == ' ')
            {count++;}
        }

        stop = count;                                               // Set stop to beginning of numerator 2

        while(problem[count] != '/')                                // Increment count to end of numerator 2
            {count++;}


        for(int i = 0; i < count - stop; i++)                       // Convert numerator 2 from chars to integer
            {n2 += (problem[(count - 1) - i] - 48) * (pow(10,i));}

        count++;                                                    // Increment count past slash
        stop = count;                                               // Set stop to beginning of denominator 2

        while(count != (flag - 1))                                  // Increment count to end
            {count++;}

        for(int i = 0; i < count - stop; i++)
            {d2 += (problem[(count - 1) - i] - 48) * (pow(10,i));}  // Convert denominator 2 from chars to integers


        Fraction F1(n1, d1);                                        // Fraction creation
        Fraction F2(n2, d2);
        Fraction ans;

        if(op == "+")                                               // if else chain to do correct arithmetic
        ans = F1 + F2;

        else if(op == "-")
        ans = F1 - F2;

        else if(op == "*")
        ans = F1 * F2;

        else if(op == "/")
        ans = F1/F2;

        else
        std::cout << "Invalid operator, initating self-destruct ";

        std::cout << F1 << " " << op << " " << F2 << " = " << ans << endl;      // Output answer to console

        for(int i = 0; i < MAX_PROB_LENGTH; i++)                                // Wipe problem array 
            {problem[i] = '$';}

            count = 0;                                                          // Reset count
    }// End getline while loop
    
    return 0;
    
}// End main
