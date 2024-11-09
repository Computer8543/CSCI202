#pragma once

/* Program Name: reservedSlotQueueType.h
*  Author: Kyle Ingersoll
*  Date last updated: 11/9/2024
*  Purpose: To build the class implementing the reserved slot queue as array design.
*/

#include <iostream>
#include <cassert>

#include "queueADT.h" 

template <class Type>
class reservedSlotQueueType : public queueADT<Type>
{
public:
    const reservedSlotQueueType<Type>& operator=(const reservedSlotQueueType<Type>&);
    //Overload the assignment operator.

    bool isEmptyQueue() const;
    //Function to determine whether the queue is empty.
    //Postcondition: Returns true if the queue is empty,
    //               otherwise returns false.

    bool isFullQueue() const;
    //Function to determine whether the queue is full.
    //Postcondition: Returns true if the queue is full,
    //               otherwise returns false.

    void initializeQueue();
    //Function to initialize the queue to an empty state.
    //Postcondition: The queue is empty.

    Type front() const;
    //Function to return the first element of the queue.
    //Precondition: The queue exists and is not empty.
    //Postcondition: If the queue is empty, the program 
    //               terminates; otherwise, the first 
    //               element of the queue is returned.  
    Type back() const;
    //Function to return the last element of the queue.
    //Precondition: The queue exists and is not empty.
    //Postcondition: If the queue is empty, the program 
    //               terminates; otherwise, the last 
    //               element of the queue is returned.

    void addQueue(const Type& queueElement);
    //Function to add queueElement to the queue.
    //Precondition: The queue exists and is not full.
    //Postcondition: The queue is changed and queueElement
    //               is added to the queue.

    void deleteQueue();
    //Function to remove the first element of the queue.
    //Precondition: The queue exists and is not empty.
    //Postcondition: The queue is changed and the first 
    //               element is removed from the queue.

    reservedSlotQueueType(int queueSize = 100);
    //Constructor

    reservedSlotQueueType(const reservedSlotQueueType<Type>& otherQueue);
    //Copy constructor

    ~reservedSlotQueueType();
    //Destructor

private:
    int maxQueueSize; //variable to store the maximum queue size
    int queueFront;   //variable to point to the first
    //element of the queue
    int queueRear;    //variable to point to the last
    //element of the queue
    Type* list;       //pointer to the array that holds 
    //the queue elements 
};

template <class Type>
bool reservedSlotQueueType<Type>::isEmptyQueue() const
{
    return (queueFront == queueRear);
} //end isEmptyQueue

template <class Type>
bool reservedSlotQueueType<Type>::isFullQueue() const
{
    // if queueRear is at the end of the array and queueFront is at 0, then queueRear + 1 == maxQueueSize and thus the remainder of that would be 0 
    return (((queueRear + 1) % maxQueueSize) == queueFront);
} //end isFullQueue

template <class Type>
void reservedSlotQueueType<Type>::initializeQueue()
{
    queueFront = 0;
    queueRear = 0;
} //end initializeQueue

template <class Type>
Type reservedSlotQueueType<Type>::front() const
{
    assert(!isEmptyQueue());

    // since queueFront is reserved and thus empty, we return the element after queueFront
    return list[(queueFront + 1)];
} //end front

template <class Type>
Type reservedSlotQueueType<Type>::back() const
{
    assert(!isEmptyQueue());
    return list[queueRear];
} //end back

template <class Type>
void reservedSlotQueueType<Type>::addQueue(const Type& newElement)
{
    if (!isFullQueue())
    {
        queueRear = (queueRear + 1) % maxQueueSize; //use mod
        //operator to advance queueRear  
        //because the array is circular
        list[queueRear] = newElement;
    }
    else
        std::cout << "Cannot add to a full queue." << std::endl;
} //end addQueue

template <class Type>
void reservedSlotQueueType<Type>::deleteQueue()
{
    if (!isEmptyQueue())
    {
        queueRear = (queueRear - 1) % maxQueueSize; //use the
        //mod operator to decrease queueRear 
        //because the array is circular 
    }
    else
        std::cout << "Cannot remove from an empty queue." << std::endl;
} //end deleteQueue

    //Constructor
template <class Type>
reservedSlotQueueType<Type>::reservedSlotQueueType(int queueSize)
{
    if (queueSize <= 0)
    {
        std::cout << "Size of the array to hold the queue must "
            << "be positive." << std::endl;
        std::cout << "Creating an array of size 100." << std::endl;

        maxQueueSize = 100;
    }
    else
        maxQueueSize = queueSize;   //set maxQueueSize to 
    //queueSize

    queueFront = 0;                 //initialize queueFront

    //initialize queueRear
    queueRear = 0;

    list = new Type[maxQueueSize];  //create the array to
    //hold the queue elements
} //end constructor

    //Destructor
template <class Type>
reservedSlotQueueType<Type>::~reservedSlotQueueType()
{
    delete[] list;
    list = NULL;
} //end destructor

template <class Type>
const reservedSlotQueueType<Type>& reservedSlotQueueType<Type>::operator=
(const reservedSlotQueueType<Type>& otherQueue)
{
    // old code I made
    /* call copy constructor to reduce code duplication
    reservedSlotQueueType(otherQueue);

    // return reference to this object
    return *this;
    */

    // new code made by ChatGPT to fix the redefinition of formal parameter 'otherQueue' error
    if (this != &otherQueue) { // Check for self-assignment
        // Copy elements from otherQueue to this queue
        queueFront = otherQueue.queueFront;
        queueRear = otherQueue.queueRear;
        maxQueueSize = otherQueue.maxQueueSize;

        delete[] list; // Free the old list memory
        list = new Type[maxQueueSize]; // Allocate new memory

        for (int i = queueFront + 1; i <= queueRear; i++) {
            list[i] = otherQueue.list[i];
        }
    }
    return *this; // Return reference to this object
} //end assignment operator

template <class Type>
reservedSlotQueueType<Type>::reservedSlotQueueType(const reservedSlotQueueType<Type>& otherQueue)
{
    // old code
    /* if this isn't a self-assignment, loop across the queue assigning elements until queueRear has been transfered.
    if (this != otherQueue) {
        for (int i = (otherQueue.queueFront + 1); i <= otherQueue.queueRear; i++) {
            this->list[i] = otherQueue->list[i];
        }

    }

    return *this;
    */

    // new code to fix errors created by old code made by ChatGPT
    if (this != &otherQueue) { // Check for self-assignment
        queueFront = otherQueue.queueFront;
        queueRear = otherQueue.queueRear;
        maxQueueSize = otherQueue.maxQueueSize;

        list = new Type[maxQueueSize]; // Allocate new memory

        for (int i = queueFront + 1; i <= queueRear; i++) {
            list[i] = otherQueue.list[i];
        }
    }

} //end copy constructor