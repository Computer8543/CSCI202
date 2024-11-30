/* Program Name: main.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 11/29/2024
*  Purpose: To implement a B-Tree Insert function within a program.
*/
#include <iostream>
#include "BTree.h"

// global constant
static const int MINDEGREE = 3; // we set it to three to distinguish the B-Tree from a binary tree

int main()
{
    // initialize variables
    int userInput;
    BTree<int> tree = BTree<int>(MINDEGREE);

    // tell user about purpose of program
    std::cout << "This program implements a B-Tree Insert function and then traverses it." << std::endl;

    // prompt user to input a nonnegative integer to insert it within the tree or a negative integer to end the program
    std::cout << "Enter a nonnegative integer to insert it within the B-Tree or a negative integer to end the program: ";
    std::cin >> userInput;
    std::cout << std::endl;

    // input verification and Insertion loop
    while (userInput >= 0) {
        if (!(std::cin)) {
            // clear input stream
            std::cin.clear();
            std::cin.ignore(200, '\n');

            // output error message
            std::cerr << "You did not enter in a integer. Please input a integer." << std::endl;

            // prompt user to input a nonnegative integer to insert it within the tree or a negative integer to end the program
            std::cout << "Enter a nonnegative integer to insert it within the B-Tree or a negative integer to end the program: ";
            std::cin >> userInput;
            std::cout << std::endl;
            continue;
        }
        else {
            // insert user input into B-Tree
            tree.insert(userInput);

            // prompt user to input a nonnegative integer to insert it within the tree or a negative integer to end the program
            std::cout << "Enter a nonnegative integer to insert it within the B-Tree or a negative integer to end the program: ";
            std::cin >> userInput;
            std::cout << std::endl;
            continue;
        }
    }

    // traverse tree and output user input
    std::cout << "Traversing created B-Tree: " << std::endl;
    tree.traverse();

    // end program normally
    return 0;
}

