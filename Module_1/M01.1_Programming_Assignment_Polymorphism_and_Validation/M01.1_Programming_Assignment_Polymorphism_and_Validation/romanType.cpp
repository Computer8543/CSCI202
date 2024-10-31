/* Name of program: romanType.cpp
* Author: Kyle Ingersoll
* Date last updated: 10/31/2024
* Purpose: To serve as a source file for the romanType class, which
* serves to receive and store a Roman Numeral, convert it to a Decimal and store that
* and then let the user choose between printing out the number as a Roman Numeral or a Decimal.
*/

#include <iostream>
#include <string>
#include <map>
#include "romanType.h"

romanType::romanType(std::string numberAsRomanNumeral) {
	setNumberAsRomanNumeral(numberAsRomanNumeral); // we put the bulk of the work done by the constructor into the setter, since we don't want to replicate code
}

void romanType::setNumberAsRomanNumeral(std::string numberAsRomanNumeral) {
	try {
		//  we throw an exception when the Roman Numeral is an empty string
		if (numberAsRomanNumeral.length() == 0)
		{
			throw std::invalid_argument("Putting nothing as user input does not make it a Roman Numeral. Closing program now.");
		}

		// initialize variables
		int numberOfTimesCharactersInNumberMatchRomanNumerals = 0;
		const char* numberAsRomanNumeralStringElements = numberAsRomanNumeral.c_str(); // we ended up creating a c-string anyways for storing the elements of the string
		std::map<char, int>::const_iterator it; // we make it a const iterator because the map we are looping through is a const map
		// loop through numberAsRomanNumeralElements to compare the cstring elements to the keys of the map
		for (int i = 0; i < numberAsRomanNumeral.length(); i++) {

			// we loop through the map to see if the characters match the keys of the map, if they do we set numberMatchesRomanNumerals to true and we end the loop 
			for (it = ROMANNUMERALTODECIMALNUMBERMAP.begin(); it != ROMANNUMERALTODECIMALNUMBERMAP.end(); it++) {

				if (it->first == numberAsRomanNumeralStringElements[i]) {
					numberOfTimesCharactersInNumberMatchRomanNumerals++;
					break;
				}
			}


		}

		if (numberOfTimesCharactersInNumberMatchRomanNumerals != numberAsRomanNumeral.length()) {
			throw std::invalid_argument("Not all the characters in the user input match Roman Numerals. Exiting program.");
		}
		else {
			this->numberAsRomanNumeral = numberAsRomanNumeral;

			// we put this function here instead of the constructor since we want the setter function to automatically convert and store the number as a Decimal
			convertAndStoreNumberAsDecimal(numberAsRomanNumeral);
		}


	}
	catch (std::invalid_argument& ia) {
		// we print out the error message, and then exit the program
		std::cerr << ia.what() << std::endl;
		exit(1);
	}
}

// conversion and storage method for Roman Numeral to Decimal numbers
void romanType::convertAndStoreNumberAsDecimal(std::string numberAsRomanNumeral) {
	// initialize variables
	const char* numberAsRomanNumeralStringElements = numberAsRomanNumeral.c_str(); // we ended up creating a c-string anyways for storing the elements of the string
	int total = 0; // for storing the total of the Roman Numerals in decimal form
	std::map<char, int>::const_iterator it; // we make it a const iterator because the map we are looping through is a const map

	for (int i = 0; i < numberAsRomanNumeral.length(); i++) {
		// the length of numberAsRomanNumeral String being zero case and the inputted number being actually a Roman Numeral was already handled by setNumberAsRomanNumeral, so we can focus on the 1 or more cases
		if (numberAsRomanNumeral.length() == 1) {
			total = ROMANNUMERALTODECIMALNUMBERMAP.at(numberAsRomanNumeralStringElements[0]);
			break;
		}
		else if (i < (numberAsRomanNumeral.length() - 1)) {
			// basically if i is at least 2 less than the numberAsRomanNumeral length, it compares the character it is on and the character after it to see if it is smaller or larger than the other
			// if the element in i is smaller than the element in i + 1, then subtract the element in i + 1 by the element in i and add it to the total. If it is larger or equal to, add the element in i to the
			// element in i + 1
			if (ROMANNUMERALTODECIMALNUMBERMAP.at(numberAsRomanNumeralStringElements[i]) < ROMANNUMERALTODECIMALNUMBERMAP.at(numberAsRomanNumeralStringElements[(i + 1)])) {
				total += (ROMANNUMERALTODECIMALNUMBERMAP.at(numberAsRomanNumeralStringElements[(i + 1)]) - ROMANNUMERALTODECIMALNUMBERMAP.at(numberAsRomanNumeralStringElements[i]));
			}
			else {
				// had to change this algorithm due to errors in the decimal representation of this result
				total += (ROMANNUMERALTODECIMALNUMBERMAP.at(numberAsRomanNumeralStringElements[i]));
			}
		}
		else {
			// to capture that last digit in the Roman Numeral in the decimal representation
			if (ROMANNUMERALTODECIMALNUMBERMAP.at(numberAsRomanNumeralStringElements[(i - 1)]) >= ROMANNUMERALTODECIMALNUMBERMAP.at(numberAsRomanNumeralStringElements[(i)])) {
				total += (ROMANNUMERALTODECIMALNUMBERMAP.at(numberAsRomanNumeralStringElements[i]));
			}
			// we break here since the end of the array is 1 less than length, and we already calculated the size of the full number due to i + 1, despite it being two less than the
			// numberAsRomanNumeral length
			break;
		}
	}

	// set numberAsDecimal equal to total
	this->numberAsDecimal = total;

}

// output number as a Roman decimal
void romanType::printNumberAsARomanNumeral() {
	std::cout << "The inputted number as a Roman Numeral: " << numberAsRomanNumeral << std::endl;
}

// output number as a decimal
void romanType::printNumberAsADecimalNumber() {
	std::cout << "The inputted number as a Decimal: " << numberAsDecimal << std::endl;
}

// getter functions, never get used, but might be of use to a developer.

std::string romanType::getNumberAsRomanNumeral() const {
	return numberAsRomanNumeral;
}

int romanType::getNumberAsDecimal() const {
	return numberAsDecimal;
}