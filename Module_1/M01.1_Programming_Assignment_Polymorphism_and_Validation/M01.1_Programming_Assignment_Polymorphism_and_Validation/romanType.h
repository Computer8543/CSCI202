#pragma once

/* Name of program: romanType.h
* Author: Kyle Ingersoll
* Date last updated: 10/31/2024
* Purpose: To serve as a header file for the romanType class, which 
* serves to receive and store a Roman Numeral, convert it to a Decimal and store that
* and then let the user choose between printing out the number as a Roman Numeral or a Decimal.
*/
#include <iostream>
#include <string>
#include <map>

// constant map to convert between Roman Numerals and Decimals
static const std::map<char, int> ROMANNUMERALTODECIMALNUMBERMAP{
	{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}
};

class romanType {
private:
	// attributes that store the number as a Roman Numeral and as a decimal
	std::string numberAsRomanNumeral; // I could store this as a c-string, but then I would be getting into dynamic memory and pointers. I don't want to overengineer this, so I'll keep it as a string.
	int numberAsDecimal; // I assume that the decimal numbers are integers, and not float or double numbers.

public:
	// constructor for the class
	romanType(std::string numberAsRomanNumeral);

	// setter function for the class
	void setNumberAsRomanNumeral(std::string numberAsRomanNumeral);

// we make this function private to ensure that Roman Numeral input number is synced with the Decimal number at all times
private:
	// conversion and storage method for Roman Numeral to Decimal numbers
	void convertAndStoreNumberAsDecimal(std::string numberAsRomanNumeral);

public:
	// output number as a Roman decimal
	void printNumberAsARomanNumeral();

	// output number as a decimal
	void printNumberAsADecimalNumber();

	// getter functions

	std::string getNumberAsRomanNumeral() const;

	int getNumberAsDecimal() const;
};