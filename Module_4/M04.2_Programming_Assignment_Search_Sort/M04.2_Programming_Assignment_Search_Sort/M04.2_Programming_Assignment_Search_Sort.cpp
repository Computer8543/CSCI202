/* Program Name: M04.2_Programming_Assignment_Search_Sort.cpp
*  Author: Kyle Ingersoll 
*  Date last updated: 11/22/2024
*  Purpose: To compare the efficiency between the merge and selection sort on linked lists.
*/
#include <iostream>
#include <time.h>
#include "unorderedLinkedList.h"

int main()
{
    // initizalize variables

    // Merge sort linked lists
    unorderedLinkedList<int> oneElementMergeSortLinkedList;
    unorderedLinkedList<int> tenElementMergeSortLinkedList;
    unorderedLinkedList<int> hundredElementMergeSortLinkedList;
    unorderedLinkedList<int> thousandElementMergeSortLinkedList;

    // Selection sort linked lists
    unorderedLinkedList<int> oneElementSelectionSortLinkedList;
    unorderedLinkedList<int> tenElementSelectionSortLinkedList;
    unorderedLinkedList<int> hundredElementSelectionSortLinkedList;
    unorderedLinkedList<int> thousandElementSelectionSortLinkedList;

    // tell user purpose of program 
    std::cout << "This program compares the Merge and Selection Sorts on linked lists with 1, 10, 100, and 1000 randomly generated integer elements to determine which one is more efficient." << std::endl;
    
    // start generating random numbers between 1 and 100 to fill each linked list
    
    // set a random seed for this program
    srand(time(nullptr));

    // one random integer generation
    oneElementMergeSortLinkedList.insertFirst(rand() % 100 + 1);
    oneElementSelectionSortLinkedList.insertFirst(rand() % 100 + 1);

    // ten random integer generation
    for (int i = 0; i < 10; i++) {
        tenElementMergeSortLinkedList.insertFirst(rand() % 100 + 1);
        tenElementSelectionSortLinkedList.insertFirst(rand() % 100 + 1);
    }

    // hundred random integer generation
    for (int i = 0; i < 100; i++) {
        hundredElementMergeSortLinkedList.insertFirst(rand() % 100 + 1);
        hundredElementSelectionSortLinkedList.insertFirst(rand() % 100 + 1);
    }

    // thousand random integer generation
    for (int i = 0; i < 1000; i++) {
        thousandElementMergeSortLinkedList.insertFirst(rand() % 100 + 1);
        thousandElementSelectionSortLinkedList.insertFirst(rand() % 100 + 1);
    }

    // then we run the 1 element sorts
    std::cout << "One Element Selection Sort: " << std::endl;
    oneElementSelectionSortLinkedList.selectionSort();
    std::cout << "One Element Merge Sort: " << std::endl;
    oneElementMergeSortLinkedList.mergeSort();
    
    // then we run the 10 element sorts
    std::cout << "Ten Element Selection Sort: " << std::endl;
    tenElementSelectionSortLinkedList.selectionSort();
    std::cout << "Ten Element Merge Sort: " << std::endl;
    tenElementMergeSortLinkedList.mergeSort();

    // then we run the 100 element sorts
    std::cout << "One hundred Element Selection Sort: " << std::endl;
    hundredElementSelectionSortLinkedList.selectionSort();
    std::cout << "One hundred Element Merge Sort: " << std::endl;
    hundredElementMergeSortLinkedList.mergeSort();

    // then we run the 1000 element sorts
    std::cout << "One thousand Element Selection Sort: " << std::endl;
    thousandElementSelectionSortLinkedList.selectionSort();
    std::cout << "One thousand Element Merge Sort: " << std::endl;
    thousandElementMergeSortLinkedList.mergeSort();

    
    // end program normally
    return 0;
}
