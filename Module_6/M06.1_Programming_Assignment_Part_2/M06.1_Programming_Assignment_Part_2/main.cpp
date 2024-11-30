/* Program name: main.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 11/30/2024
*  Purpose: To implement a AVL Tree insert function within the program
*/

#include <iostream>
#include "avlTree.h"

int main()
{
    // initialize variables
    int userInput;
    AVLTree<int> tree;

    // tell user about purpose of program
    std::cout << "This program implements a AVL Tree Insert function and then traverses it." << std::endl;

    // prompt user to input a nonnegative integer to insert it within the tree or a negative integer to end the program
    std::cout << "Enter a nonnegative integer to insert it within the AVL Tree or a negative integer to end the program: ";
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
            std::cout << "Enter a nonnegative integer to insert it within the AVL Tree or a negative integer to end the program: ";
            std::cin >> userInput;
            std::cout << std::endl;
            continue;
        }
        else {
            // insert user input into B-Tree
            tree.insert(userInput);

            // prompt user to input a nonnegative integer to insert it within the tree or a negative integer to end the program
            std::cout << "Enter a nonnegative integer to insert it within the AVL Tree or a negative integer to end the program: ";
            std::cin >> userInput;
            std::cout << std::endl;
            continue;
        }
    }

    // traverse tree and output user input
    std::cout << "Traversing created AVL Tree: " << std::endl;
    tree.traverse();

    // end program normally
    return 0;
}

