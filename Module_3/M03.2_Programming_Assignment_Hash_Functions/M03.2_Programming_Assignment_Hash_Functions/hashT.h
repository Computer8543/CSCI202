#pragma once

/* Program Name: hashT.h
*  Author: Kyle Ingersoll
*  Date last updated: 11/16/2024
*  Purpose: To create a hash table class utilizing chaining to deal with hash collisions.
*/

#include <iostream>
#include <functional>
#include "unorderedLinkedList.h"

/* Note: This is all based on ChatGPT's pseudocode, althrough some changes were made to better fit the C++ language. */
template <class Type> // HashMethod is meant to support function pointers to the hashing methods
class hashT {
private:
	// define attribute for the hash table size and the array in which to store the elements in the hash table
	using HashMethod = std::function<int(Type, int)>;
	int size;
	unorderedLinkedList<Type>* table;
	HashMethod hashingMethod; // polymorphic pointer wrapper for the hashing methods so we can pass them to the function

	// define methods for constructor, destructor, and other needed functions
public:
	// constructor
	hashT(int size, HashMethod hashingMethod);

	// destructor
	~hashT();

	// mutator methods
	bool search(Type key);
	bool isItemAtEqual(int index, Type key);
	void insert(Type key); // use chaining with linked list in each index to 
	Type retrieve(Type key) throw(std::out_of_range);
	void remove(Type key);
	void print();

};

/* The constructor for the class */
template <class Type>
hashT<Type>::hashT(int size, HashMethod hashingMethod) {
	// input validation to handle the creation of an empty table.
	if (size == 0) {
		// set size to 100
		this->size = 100;

		// output to user an error message
		std::cerr << "You cannot create a hash table with a size of 0. Setting hash table size to 100." << std::endl;

	}
	else {
		// set size equal to user input
		this->size = size;
	}

	// initialize an empty dynamic array of linked lists to act as a table
	table = new unorderedLinkedList<Type>[size];

	// set hashingMethod parameter into attribute
	this->hashingMethod = hashingMethod;

}

/* The destructor for the class. Deletes the dynamic array, and sets the pointer to null. */
template <class Type>
hashT<Type>::~hashT() {
	// delete heap memory used by table
	delete[] table;

	// remove the possibility of dangling pointers by setting the table pointer to NULL
	table = nullptr;

	// tell user the hash table was destroyed
	std::cout << "Hash Table was destroyed" << std::endl;
}

/* The search method for the hashT class. It hashes the key utilizing the passed in HashMethod to create an index, which is used to find the corresponding linked list in the table.
*  That linked list is then searched utilizing a method in the linked list itself, and a value of true or false is returned based on the presence of the key in the linked list.
*/
template <class Type>
bool hashT<Type>::search(Type key) {
	// we first generate the index to the table using a passed in hashing function
	int index = hashingMethod(key, size);
	
	// then if the key is found at the index return true, else return false
	if (table[index].search(key)) {
		return true;
	}
	else {
		return false;
	}
}

/* This method searches the linked list at a index specified by the user for the key. A value of true or false is returned based on the presence of the key in the linked list. */
template <class Type>
bool hashT<Type>::isItemAtEqual(int index, Type key) {
	// then if the key is found at the index return true, else return false
	if (table[index].search(key)) {
		return true;
	}
	else {
		return false;
	}
}

/* The insertion method for the hashT class. It hashes the key into an index, searches the linked list at the index for the key to ensure that it isn't already in there, and if it isn't
*  it will insert the key at the beginning of the linked list
*/
template <class Type>
void hashT<Type>::insert(Type key) {
	// we first generate the index to the table using a passed in hashing function
	int index = hashingMethod(key, size);

	// check to see if key already exists at that index
	if (table[index].search(key)) {
		std::cerr << "The key is already contained within the linked list at the index." << std::endl;
	}
	else {
		// we insert the key at the beginning of the linked list at the index of the table
		table[index].insertFirst(key);
	}
}

/* The retrieval method for the hashT class. This hashes the key into an index, searches the linked list at the index to find the key, and returns the key if found.
*  If the key is not found, an exception is thrown. I decided that returning a NULL is a bad idea.
*/
template <class Type>
Type hashT<Type>::retrieve(Type key) throw(std::out_of_range) {
	// we first generate the index to the table using a passed in hashing function
	int index = hashingMethod(key, size);

	// if the key is found, return key, else throw an out of range exception
	if (table[index].search(key)) {
		return key;
	}
	else {
		throw std::out_of_range("The key is not within the linked list at the associated index in the table.");
	}
}

/* The remove function in the hashT class. It removes the node associated with the key in the linked list at the associated index in the hash table. */
template <class Type>
void hashT<Type>::remove(Type key) {
	// we first generate the index to the table using a passed in hashing function
	int index = hashingMethod(key, size);

	// then we delete the node in the linked list associated with the key
	table[index].deleteNode(key);
}

/* The print function for the hashT class. This loops across the entire hash table and every linked list in each index at the hash table to print all the information contained within out. */
template <class Type>
void hashT<Type>::print() {
	// loop across the hash table across each index and print each linked list at the index until the end of the hash table 
	for (int i = 0; i < size; i++) {
		std::cout << "Index " << i << ": ";
		table[i].print();
		std::cout << std::endl;
	}
}

/* The modulo hash method */
template <class Type>
int moduloHashMethod(Type key, int hashTableSize) {
	return static_cast<int>((key % hashTableSize));
}

/* The mid-square hash method */
template <class Type>
int midSquareHashMethod(Type key, int hashTableSize) {
	// convert key into string
	std::string keyString = std::to_string(key);

	// store key length in variable
	int keyDigitLength = keyString.length();

	// square the key
	Type squaredKey = (key * key);

	// make a string equivalent of the squared key to extract the length of it
	std::string squaredKeyString = std::to_string(squaredKey);

	// then find squared key length through the length function
	int squaredKeyDigitLength = squaredKeyString.length();

	// get the mid-square as a substring of squaredKeyString
	std::string midSquareSubString = squaredKeyString.substr((squaredKeyDigitLength / 2), keyDigitLength);

	// convert midSquareSubString into an integer
	int midSquareInteger = std::stoi(midSquareSubString);

	// return the hash of the mid-square
	return (midSquareInteger % hashTableSize);

}

/* The folding hash method */
template <class Type>
int foldingHashMethod(Type key, int hashTableSize) {
	// convert key into string
	std::string keyString = std::to_string(key);

	// initialize sum of digits in key variable
	int sumDigitsInKey = 0;

	// we loop across the keyString, summing up the digits in the key
	for (int i = 0; i < keyString.length(); i++) {
		sumDigitsInKey += static_cast<int>(keyString.at(i));
	}

	// we then return the hash of the sum of digits in the key
	return (sumDigitsInKey % hashTableSize);
}
