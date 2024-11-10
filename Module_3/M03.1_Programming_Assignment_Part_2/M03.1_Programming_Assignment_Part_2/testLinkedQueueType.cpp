/* Program name: testLinkedQueueType.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 11/10/2024
*  Purpose: Test out the operations of linkedQueueType
*/
#include <iostream>
#include "linkedQueueType.h"
int main()
{
    // initialize variables
    linkedQueueType<int> numberQueue = linkedQueueType<int>();
    linkedQueueType<int> reverseNumberQueue = linkedQueueType<int>();

    // we first see if the queue is empty, note that it is at this point
    std::cout << "Is the queue empty? " << numberQueue.isEmptyQueue() << std::endl;

    // we add a bunch of numbers to numberQueue
    numberQueue.addQueue(1);
    numberQueue.addQueue(2);
    numberQueue.addQueue(3);
    numberQueue.addQueue(4);
    numberQueue.addQueue(5);

    // we delete the first number from queue, meaning the node with an info of 1
    numberQueue.deleteQueue();

    // we output the first number in the queue, that being 4
    std::cout << "What is the first number in the queue? " << numberQueue.front() << std::endl;

    // then we add a bunch of numbers to reverseNumberQueue
    reverseNumberQueue.addQueue(5);
    reverseNumberQueue.addQueue(4);
    reverseNumberQueue.addQueue(3);
    reverseNumberQueue.addQueue(2);
    reverseNumberQueue.addQueue(1);

    // then we copy over reverseNumberQueue to numberQueue using the assignment operator
    numberQueue = reverseNumberQueue;

    // we output the first number in the queue, that being 1
    std::cout << "What is the first number in the queue? " << numberQueue.front() << std::endl;

    // we finally see if the queue is empty, note that it is not at this point
    std::cout << "Is the queue empty? " << numberQueue.isEmptyQueue() << std::endl;

    // end program normally
    return 0;
}
