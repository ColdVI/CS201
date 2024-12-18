/*
Anil Keskin
Sec3
22201915
*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"
template <class T>
class LinkedList {


public:

    Node<T>* headptr;
    int itemCount;
    LinkedList();
    LinkedList(const T& aList);
    ~LinkedList();
    LinkedList(const LinkedList<T>& aList);
    bool insertSorted(const T& data); // Inserts data in ascending order
    bool insert(const T& data); // Inserts data without sorting
    bool remove(const T& data); // Removes the specified data
    Node<T>* find(const T& data) const; // Finds and returns the node containing data
    bool exists(const T& data) const;
    void print() const;
    void clear();
    bool isEmpty() const; // Checks if the list is empty
    int getLength() const;

    Node<T> *getNodeAt(int position) const;

    T getEntry(int position) const;

    void modifyItem(const T &oldItem, const T &newItem);

    T replace(int position, const T& newEntry);


};
#include "LinkedList.cpp"
#endif // LINKEDLIST_H
