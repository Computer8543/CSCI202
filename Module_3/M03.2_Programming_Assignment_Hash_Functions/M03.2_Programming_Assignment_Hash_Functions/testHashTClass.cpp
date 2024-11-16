/* Program Name: testHashTClass.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 11/16/2024
*  Purpose: To test a hash table class utilizing chaining to deal with hash collisions.
*/

#include <iostream>
#include <string>
#include "hashT.h"

/* Note: The hash methods and main class were based on ChatGPT generated pseudocode, which I used as the basis for me programming it in C++. */


int main()
{
    // create hash tables
    hashT<int> hashTable1(10, &moduloHashMethod<int>);
    hashT<int> hashTable2(10, &midSquareHashMethod<int>);
    hashT<int> hashTable3(10, &foldingHashMethod<int>);

    // insert data into hash table 1
    hashTable1.insert(1);
    hashTable1.insert(2);
    hashTable1.insert(3);
    hashTable1.insert(4);
    hashTable1.insert(5);

    // insert data into hash table 2
    hashTable2.insert(1);
    hashTable2.insert(2);
    hashTable2.insert(3);
    hashTable2.insert(4);
    hashTable2.insert(5);

    // insert data into hash table 3
    hashTable3.insert(1);
    hashTable3.insert(2);
    hashTable3.insert(3);
    hashTable3.insert(4);
    hashTable3.insert(5);

    // test the search function
    hashTable1.search(1); // should be found in the list
    hashTable1.search(10); // should not be found in the list

    // remove some data from the hash tables
    hashTable1.remove(1);
    hashTable2.remove(2);
    hashTable3.remove(3);

    // print out all the remaining data
    std::cout << "Printing Hash Table 1: " << std::endl;
    hashTable1.print();
    std::cout << "Printing Hash Table 2: " << std::endl;
    hashTable2.print();
    std::cout << "Printing Hash Table 3: " << std::endl;
    hashTable3.print();

    // end program normally
    return 0;
}

