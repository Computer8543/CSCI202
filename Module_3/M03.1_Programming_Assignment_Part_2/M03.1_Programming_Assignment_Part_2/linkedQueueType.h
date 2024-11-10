#pragma once

/* Program name: linkedQueueType.h
*  Author: Kyle Ingersoll
*  Date last updated: 11/10/2024
*  Purpose: Create a class template for linkedQueueType, which will be used in other programs.
*/

#include <iostream>
#include <cassert>
#include "unorderedLinkedList.h"

template <class Type>
class linkedQueueType : public unorderedLinkedList<Type> {
    /* Copied the method headings and attributes over from linkedQueue.h */
public:
    const linkedQueueType<Type>& operator=
        (const linkedQueueType<Type>&);
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
    //Postcondition: queueFront = nullptr; queueRear = nullptr

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
    //Function  to remove the first element of the queue.
    //Precondition: The queue exists and is not empty.
    //Postcondition: The queue is changed and the first 
    //               element is removed from the queue.

    linkedQueueType();
    //Default constructor

    linkedQueueType(const linkedQueueType<Type>& otherQueue);
    //Copy constructor

    ~linkedQueueType();
    //Destructor

/* Pointers to the front and back of the list are handled through this->first and this->last, thus duplicating pointers seems like a bad idea */
};

// Default constructor
template <class Type>
linkedQueueType<Type>::linkedQueueType() {

}

//Copy constructor
template <class Type>
linkedQueueType<Type>::linkedQueueType(const linkedQueueType<Type>& otherQueue) {
    // I use the copyList method from the base class in order to minimize code duplication
    linkedListType<Type>::copyList(otherQueue);
}



//Destructor
template <class Type>
linkedQueueType<Type>::~linkedQueueType()
{
    // I use a destructor from the base class to avoid code duplication
    linkedListType<Type>::~linkedListType();

} //end destructor

// method determines if queue is empty
template <class Type>
bool linkedQueueType<Type>::isEmptyQueue() const {
    // we reuse an already existing method in the base class to avoid code duplication
    return linkedListType<Type>::isEmptyList();
}


// method determines if queue is full
template <class Type>
bool linkedQueueType<Type>::isFullQueue() const {
    // also reused code from linkedQueue.h
    // since linked lists use dynamic memory, they are never full
    return false;
}

// method initializes queue
template <class Type>
void linkedQueueType<Type>::initializeQueue() {
    // we reuse an similar method in the base class to avoid code duplication
    linkedListType<Type>::initializeList();

}

// method returns the front element of the queue
template <class Type>
Type linkedQueueType<Type>::front() const {
    // I reused code from linkedQueue.h for this method
    assert(this->first != nullptr);
    return this->first->info;
} // end front

// method returns the back element of the queue

template <class Type>
Type linkedQueueType<Type>::back() const
{
    // I reused code from linkedQueue.h for this method
    assert(this->last != nullptr);
    return this->last->info;
} //end back

// this method adds an element to the queue
template <class Type>
void linkedQueueType<Type>::addQueue(const Type& queueElement) {
    // we use the insertFirst function from the class preceding this one in the inheritance hierarchy to do the heavy work and to avoid code duplication
    unorderedLinkedList<Type>::insertFirst(queueElement);
}

// this method deletes an element of the queue
template <class Type>
void linkedQueueType<Type>::deleteQueue()
{
    /* The code is copied from linkedQueue.h since the operation is the same in both versions */

    // initializing variable
    nodeType<Type>* temp;

    if (!isEmptyQueue())
    {
        temp = this->first;  //make temp point to the 
        //first node
        this->first = this->first->link; //advance queueFront 

        delete temp;    //delete the first node

        if (this->first == nullptr) //if after deletion the 
            //queue is empty
            this->last = nullptr;   //set queueRear to nullptr
    }
    else
        cout << "Cannot remove from an empty queue" << endl;
}//end deleteQueue

template <class Type>
const linkedQueueType<Type>& linkedQueueType<Type>::operator=
(const linkedQueueType<Type>& otherQueue) {
    // prevent self copying
    if (this != &otherQueue) {
        // Note: do not call copy constructor, implement assignment operator code indepenently so that the copied over data doesn't get deleted at the end
        linkedListType<Type>::copyList(otherQueue);
    }
  
    // we return this object after the copying is done
    return *this;
}
//Overload the assignment operator.