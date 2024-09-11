/**
 * Fraction Class
 *
 * Description:
 *      This class encapsulates functions and overaloads operators to
 *		achieve the ability to do arithmetic on fractions
 *
 * Public Methods:
 *		      - Fraction()
 *		   	  - Fraction(int n, int d)
 *	ostream	  - operator << (ostream& os, const Fraction& next)
 *	Fraction  - operator + (const Fraction& next)
 *  Fraction  - operator - (const Fraction& next)
 *  Fraction  - operator * (const Fraction& next)
 *  Fraction  - operator / (const Fraction& next)
 *	bool	  - operator == (const Fration& next)
 *
 * Private Methods:
 *	int		  - GCD(int a, int b)
 *	Fraction  - reduce(Fraction f, int GCD)
 *
 * Usage:
 *
 *			 - examples of how
 *			 - to use your class
 */

#include "Fraction.h"


 /**
  * Private : GCD
  *
  * Description:
  *      Recursive function to get increasingly big common divisor of both the numerator and denominator. Used to reduce fractions.
  *
  * Params:
  *     int      :  original numerator
  *     int      :  original denominator
  *
  * Returns:
  *     int      :  Greatest common divisor of the numer and denom
  */
int Fraction::GCD(int a, int b)
{
	if (b == 0)						// Base Case
		return a;

	else
		return GCD(b, a % b);		// Recursive call
}

/**
  * Private : reduce
  *
  * Description:
  *      Simply divide numerator and denominator by their GCD to achieve reduced fraction
  *
  * Params:
  *     Fraction :  original fraction
  *     int      :  greatest common divisor
  *
  * Returns:
  *     Fraction :  maximally reduced fraction. 
  */
Fraction Fraction::reduce(Fraction f, int GCD)
{
	f.numer /= GCD;		// Divide numer and denom by GCD to achieve reduced fraction
	f.denom /= GCD;

	return f;
}

/**
  * Public : Fraction
  *
  * Description:
  *      Default constructor to create a 1/1 fraction
  *
  * Params:
  *     None
  *
  * Returns:
  *     None
  */
Fraction::Fraction()
{
	numer = denom = 1;		// Default construction of 1/1 fraction
}

/**
  * Public : Fraction
  *
  * Description:
  *      Overloaded constructor to create a custom fraction
  *
  * Params:
  *     int      :  numerator
  *     int      :  denominator
  *
  * Returns:
  *     None
  */
Fraction::Fraction(int n, int d)
{
	numer = n;		// Assignment for numerator
	denom = d;		// Assignment for denominator
}


/**
  * Public : operator <<
  *
  * Description:
  *      Overload insertion operator to simply cout fractions
  *
  * Params:
  *     ostream&        :  Location of output stream
  *     const Fraction& :  Address of the fraction to the right of the operator
  *
  * Returns:
  *     ostream&	    :  Fraction numerator followed by a "/" then the denominator
  */
ostream& operator << (ostream& os, const Fraction& next)
{
	return os << next.numer << "/" << next.denom;		// Ability to cout fractions
}

/**
  * Public : operator +
  *
  * Description:
  *      Overload addition operator to simply add fractions
  *
  * Params:
  *     const Fraction& :  Address of the fraction to the right of the operator
  *
  * Returns:
  *     Fraction	    :  Correctly added and reduced fraction
  */
Fraction Fraction::operator +(const Fraction& next)
{
	Fraction lhs, rhs;

	
	lhs.numer = this->numer;	// Assignment for lhs fraction
	lhs.denom = this->denom;	
	
	rhs = next;					// Assignment for rhs fraction

	rhs.numer *= lhs.denom;		// Multiply rhs by lhs denom to achieve denom with common multiple
	rhs.denom *= lhs.denom;
	lhs.numer *= next.denom;	// Multiply lhs by original rhs denom to achieve equal denominator
	lhs.denom *= next.denom;

	lhs.numer += rhs.numer;		// Add numerators to complete operation

	lhs = reduce(lhs, GCD(lhs.numer, lhs.denom));	// Reduce fraction

	return lhs;
}

/**
  * Public : operator -
  *
  * Description:
  *      Overload subtraction operator to simply subtract fractions
  *
  * Params:
  *     const Fraction& :  Address of the fraction to the right of the operator
  *
  * Returns:
  *     Fraction	    :  Correctly subtracted and reduced fraction
  */
Fraction Fraction::operator -(const Fraction& next)
{
	if (this->denom == next.denom)				// Early Exit Conditional if denoms are already equal
	{
		Fraction temp;
		temp.numer = this->numer - next.numer;	// Operation stored in temp fraction
		temp.denom = this->denom;
		return temp;
	}

	Fraction lhs, rhs;					// create lhs and rhs fractions
	

	lhs.numer = this->numer;			// Assignment for lhs fraction
	lhs.denom = this->denom;

	rhs = next;							// Assignment for rhs fraction

	rhs.numer *= lhs.denom;				// Multiply rhs by lhs denom to achieve denom with common multiple
	rhs.denom *= lhs.denom;
	lhs.numer *= next.denom;			// Multiply lhs by original rhs denom to achieve equal denominator
	lhs.denom *= next.denom;

	lhs.numer -= rhs.numer;				// Subtract numerators to complete operation

	lhs = reduce(lhs, GCD(lhs.numer, lhs.denom));	// Reduce fraction

	return lhs;
}


/**
  * Public : operator *
  *
  * Description:
  *      Overload multiplication operator to simply multiply fractions
  *
  * Params:
  *     const Fraction& :  Address of the fraction to the right of the operator
  *
  * Returns:
  *     Fraction	    :  Correctly multiplied and reduced fraction
  */
Fraction Fraction::operator *(const Fraction& next)
{
	Fraction temp;
	temp.numer = this->numer * next.numer;		// Multiply numerators
	temp.denom = this->denom * next.denom;		// Multiply denominators
		
	temp = reduce(temp, GCD(temp.numer, temp.denom));
	
	return temp;
}

/**
  * Public : operator /
  *
  * Description:
  *      Overload division operator to simply divide fractions
  *
  * Params:
  *     const Fraction& :  Address of the fraction to the right of the operator
  *
  * Returns:
  *     Fraction	    :  Correctly divided and reduced fraction
  */
Fraction Fraction::operator / (const Fraction& next)
{
	Fraction temp;
	temp.numer = this->numer * next.denom; // Cross Multiply lhs and rhs to achieve division by fraction
	temp.denom = this->denom * next.numer;

	temp = reduce(temp, GCD(temp.numer, temp.denom));

	return temp;
}

/**
  * Public : operator ==
  *
  * Description:
  *      Overload equal-to operator to simply check for equality of fractions
  *
  * Params:
  *     const Fraction& :  Address of the fraction to the right of the operator
  *
  * Returns:
  *     bool			:  Indication of fractions being equal to eachother or not
  */
bool Fraction::operator == (const Fraction& next)
{
	return (this->numer == next.numer && this->denom == next.denom);	//Equality Statement for bool
}


// End implementation