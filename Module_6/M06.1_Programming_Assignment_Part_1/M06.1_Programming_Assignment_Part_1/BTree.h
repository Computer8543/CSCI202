#ifndef BTREE_H
#define BTREE_H

/* Program Name: BTree.h
*  Author: ChatGPT through prompt made by Kyle Ingersoll
*  Date last updated: 11/29/2024
*  Purpose: To create a working B-Tree in C++
*/

#include <iostream>
#include <vector>
#include <memory>

// Forward declaration
template <typename T>
class BTree;

// BTree Node class
template <typename T>
class BTreeNode {
public:
    bool isLeaf;                   // True if the node is a leaf
    int minDegree;                 // Minimum degree (t)
    std::vector<T> keys;           // Vector of keys
    std::vector<std::shared_ptr<BTreeNode>> children; // Vector of child pointers

    // Constructor
    BTreeNode(int degree, bool leaf)
        : minDegree(degree), isLeaf(leaf) {}

    // Split the child node at the given index
    void splitChild(int index);

    // Insert a new key into the non-full node
    void insertNonFull(T key);

    // Search for a key in the subtree rooted at this node
    BTreeNode* search(T key);

    // Display the subtree rooted at this node
    void traverse();

    friend class BTree<T>;
};

// BTree class
template <typename T>
class BTree {
private:
    std::shared_ptr<BTreeNode<T>> root; // Root node
    int minDegree;                      // Minimum degree (t)

public:
    // Constructor
    BTree(int degree) : minDegree(degree), root(nullptr) {}

    // Insert a key into the B-Tree
    void insert(T key);

    // Search for a key in the B-Tree
    BTreeNode<T>* search(T key);

    // Display the B-Tree
    void traverse() const;
};

// BTreeNode member function definitions
template <typename T>
void BTreeNode<T>::traverse() {
    int i;
    for (i = 0; i < keys.size(); i++) {
        if (!isLeaf)
            children[i]->traverse();
        std::cout << keys[i] << " ";
    }
    if (!isLeaf)
        children[i]->traverse();
}

template <typename T>
BTreeNode<T>* BTreeNode<T>::search(T key) {
    int i = 0;
    while (i < keys.size() && key > keys[i])
        i++;
    if (i < keys.size() && keys[i] == key)
        return this;
    if (isLeaf)
        return nullptr;
    return children[i]->search(key);
}

// buggy ChatGPT generated function:
/*
template <typename T>
void BTreeNode<T>::splitChild(int index) {
    auto y = children[index];
    auto z = std::make_shared<BTreeNode>(y->minDegree, y->isLeaf);
    z->keys.resize(minDegree - 1);
    for (int j = 0; j < minDegree - 1; j++)
        z->keys[j] = y->keys[j + minDegree];
    if (!y->isLeaf) {
        z->children.resize(minDegree);
        for (int j = 0; j < minDegree; j++)
            z->children[j] = y->children[j + minDegree];
    }
    y->keys.resize(minDegree - 1);
    children.insert(children.begin() + index + 1, z);
    keys.insert(keys.begin() + index, y->keys[minDegree - 1]);
    y->keys.pop_back();
}
*/ 

// corrected ChatGPT generated function:
template <typename T>
void BTreeNode<T>::splitChild(int index) {
    // Child node to be split
    auto y = children[index];
    auto z = std::make_shared<BTreeNode>(y->minDegree, y->isLeaf); // New node
    z->keys.resize(minDegree - 1);

    // Copy the upper half of y's keys to z
    for (int j = 0; j < minDegree - 1; j++)
        z->keys[j] = y->keys[j + minDegree];

    // If not a leaf, copy y's child pointers to z
    if (!y->isLeaf) {
        z->children.resize(minDegree);
        for (int j = 0; j < minDegree; j++)
            z->children[j] = y->children[j + minDegree];
    }

    // **Extract the middle key before resizing**
    T middleKey = y->keys[minDegree - 1];

    // Reduce the size of y's keys and children
    y->keys.resize(minDegree - 1);
    if (!y->isLeaf)
        y->children.resize(minDegree);

    // Add the new child to the current node (parent)
    children.insert(children.begin() + index + 1, z);

    // Add the middle key to the parent's keys
    keys.insert(keys.begin() + index, middleKey);
}

template <typename T>
void BTreeNode<T>::insertNonFull(T key) {
    int i = keys.size() - 1;
    if (isLeaf) {
        keys.push_back(0); // Temporary space for new key
        while (i >= 0 && key < keys[i]) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = key;
    }
    else {
        while (i >= 0 && key < keys[i])
            i--;
        i++;
        if (children[i]->keys.size() == 2 * minDegree - 1) {
            splitChild(i);
            if (key > keys[i])
                i++;
        }
        children[i]->insertNonFull(key);
    }
}

// BTree member function definitions
template <typename T>
void BTree<T>::insert(T key) {
    if (!root) {
        root = std::make_shared<BTreeNode<T>>(minDegree, true);
        root->keys.push_back(key);
    }
    else {
        if (root->keys.size() == 2 * minDegree - 1) {
            auto s = std::make_shared<BTreeNode<T>>(minDegree, false);
            s->children.push_back(root);
            s->splitChild(0);
            int i = (key > s->keys[0]) ? 1 : 0;
            s->children[i]->insertNonFull(key);
            root = s;
        }
        else {
            root->insertNonFull(key);
        }
    }
}

template <typename T>
BTreeNode<T>* BTree<T>::search(T key) {
    return (root == nullptr) ? nullptr : root->search(key);
}

template <typename T>
void BTree<T>::traverse() const {
    if (root)
        root->traverse();
    std::cout << std::endl;
}

#endif // BTREE_H
