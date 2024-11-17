/* Program Name: M04.1_Programming_Assignment_Part_1.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 11/17/2024
*  Purpose: To create a program that reads words from a text file and displays all the nonduplicate words in ascending order.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <set>

int main()
{
    // initialize variables
    std::ifstream fileInput;
    std::set<std::string> ascendingOrderNonDuplicateWordsFromTextFile;
    std::set<std::string>::iterator it;
    std::string wordFromTextFile;
    std::string fileName;

    // introduce user to the program
    std::cout << "This is a program that reads words from a text file and displays all the nonduplicate words in ascending order." << std::endl;

    // prompt user to enter in file name
    std::cout << "Please enter in the file name of the text file you want the program to read: ";
    std::cin >> fileName;
    std::cout << std::endl;

    // then we open the file
    fileInput.open(fileName + ".txt");

    // then we loop across the words in the file, adding them to the list
    while (!(fileInput.eof())) {
        fileInput >> wordFromTextFile;
        ascendingOrderNonDuplicateWordsFromTextFile.insert(wordFromTextFile);
    }

    
    // then we close the file since we are done inserting the words into the set
    fileInput.close();

    // since set elements in C++ are automatically in ascending order, we don't need to organize them manually
    
    // now we output to the user that the output is beginning
    std::cout << "Here are all the nonduplicate words in ascending order: " << std::endl;

    // now we loop across the set using an iterator and display them to the user in ascending order
    for (it = ascendingOrderNonDuplicateWordsFromTextFile.begin(); it != ascendingOrderNonDuplicateWordsFromTextFile.end(); it++) {
        std::cout << '\t' << *it << std::endl;
    }

    // end program normally
    return 0;
}

