/* Program Name: testReservedSlotQueueType.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 11/9/2024
*  Purpose: To test out the reserved slot queue as array design.
*/

#include <iostream>
#include "reservedSlotQueueType.h"

int main()
{
    // initialize variables
    reservedSlotQueueType<int> numberQueue = reservedSlotQueueType<int>();
    reservedSlotQueueType<int> reverseNumberQueue = reservedSlotQueueType<int>();

    std::cout << "Is the number queue empty? " << numberQueue.isEmptyQueue() << std::endl;

    // add a bunch of elements
    numberQueue.addQueue(1);
    numberQueue.addQueue(2);
    numberQueue.addQueue(3);
    numberQueue.addQueue(4);
    numberQueue.addQueue(5);

    // delete an element
    numberQueue.deleteQueue();

    // print out the result of the back queue
    std::cout << numberQueue.back() << std::endl;

    // add elements to reverseNumberQueue
    reverseNumberQueue.addQueue(5);
    reverseNumberQueue.addQueue(4);
    reverseNumberQueue.addQueue(3);
    reverseNumberQueue.addQueue(2);
    reverseNumberQueue.addQueue(1);

    // use copy constructor and assignment operator overloading to deep copy over reverseNumberQueue into numberQueue
    numberQueue = reverseNumberQueue;

    // print out results
    std::cout << numberQueue.back() << std::endl;

    std::cout << "Is the number queue full? " << numberQueue.isFullQueue() << std::endl;

    // end program normally
    return 0;
}

