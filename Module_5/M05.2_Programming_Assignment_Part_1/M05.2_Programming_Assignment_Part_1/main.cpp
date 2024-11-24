/* Program name: main.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 11/24/2024
*  Purpose: To test the leavesCount recursive function within the binaryTreeType class.
*/

#include <iostream>
#include "binarySearchTree.h"

int main()
{
    // initalize variables
    bSearchTreeType<int> binarySearchTree;
    int userInput;

    // let user know purpose of program
    std::cout << "This program is to test out the leavesCount function within the binaryTreeType class." << std::endl;

    // prompt user to input integers into the binary search tree
    std::cout << "Please input positive integers into the binary search tree. Enter a negative number to end the loop." << std::endl;
    std::cin >> userInput;
    std::cout << std::endl;

    // input verification and repeated entry loop, ends when user enters a negative number
    while (userInput >= 0) {
        if (!(std::cin)) {
            // clear buffer
            std::cin.clear();
            std::cin.ignore(200, '\n');

            // output error message to user
            std::cerr << "You did not input an integer. Please input a positive integer to be added to the binary search tree, or a negative integer to escape the loop." << std::endl;

            // prompt user to input integers into the binary search tree and continue
            std::cout << "Please input positive integers into the binary search tree. Enter a negative number to end the loop." << std::endl;
            std::cin >> userInput;
            std::cout << std::endl;
            continue;
        }
        else {
            // insert user input into binary search tree
            binarySearchTree.insert(userInput);

            // prompt user to input integers into the binary search tree and continue
            std::cout << "Please input positive integers into the binary search tree. Enter a negative number to end the loop." << std::endl;
            std::cin >> userInput;
            std::cout << std::endl;
            continue;
        }
    }

    // Display tree traversals to verify that the tree works. Generated by ChatGPT.
    std::cout << "Inorder Traversal: ";
    binarySearchTree.inorderTraversal();
    std::cout << std::endl;

    // Count leaves of the binary search tree. Generated by ChatGPT.
    std::cout << "Number of leaves: " << binarySearchTree.treeLeavesCount() << std::endl;

    // end program normally
    return 0;
}
