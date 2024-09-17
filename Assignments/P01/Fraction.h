/*****************************************************************************
*
*  Author:           Rykir Evans
*  Email:            rjevans0408@my.msutexas.edu
*  Label:            P01
*  Title:            Fraction Class
*  Course:           CMPS 2143 OOP
*  Professor:  		 Terry Grffin
*  Semester:         Fall 2024
*
*******************************************************************************/

#include <iostream>
using namespace std;

class Fraction
{

	int numer;
	int denom;

	int GCD(int, int);
	Fraction reduce(Fraction, int);

public:
	
	// Constructors
	Fraction();
	Fraction(int, int);

	// Operator overloads
	friend ostream& operator<<(ostream&, const Fraction&);
	Fraction operator + (const Fraction&);
	Fraction operator - (const Fraction&);
	Fraction operator * (const Fraction&);
	Fraction operator / (const Fraction&);
	bool operator    == (const Fraction&);
}; // End header