/* Name of program: main.cpp
* Author: Kyle Ingersoll
* Date last updated: 10/31/2024
* Purpose: To serve as the main function utilizing the romanType class to translate a number from Roman Numeral to Decimal, store the results, and then 
* give the user a choice whether they want to print it out as a Roman Numeral or a Decimal.
*/

#include <iostream>
#include <string>
#include <map>
#include "romanType.h"

int main()
{
    // initialize variables
    std::string numberAsRomanNumeral;
    char numberPrintOutChoice; // changed this from bool to better fit the options given
    bool numberPrintedOut = false;

    // prompt user to enter a Roman Numeral
    std::cout << "Please enter a Roman Numeral: ";
    std::cin >> numberAsRomanNumeral;
    std::cout << std::endl;

    // input validation is already taken care of by the class, so I won't spend the time checking the input here.
    // initialize romanType class to process numberAsRomanNumeral
    romanType converter = romanType(numberAsRomanNumeral);

    // prompt user to choose between printing out a Roman Numeral or a Decimal number
    std::cout << "Do you want to print this out as a Roman Numeral (R) or a Decimal (D)?" << std::endl;
    std::cin >> numberPrintOutChoice;
    std::cout << std::endl;

    // we loop infinatly until we get the user to either enter R or D. Then we print out the number in the respective format. That causes the numberPrintedOut to become true and the loop breaks.
    while (!(numberPrintedOut)) {
        switch (numberPrintOutChoice) {
        case 'R': {
            converter.printNumberAsARomanNumeral();
            numberPrintedOut = true;
            break;
        }
        case 'D': {
            converter.printNumberAsADecimalNumber();
            numberPrintedOut = true;
            break;
        }
        default: {
            std::cerr << "You did not enter either R or D. Please chose one of the two options";
            continue;
        }
        }

    }

    // end program normally
    return 0;
}
