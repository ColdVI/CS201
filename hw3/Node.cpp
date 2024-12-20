
/*
Anil Keskin
Sec3
22201915
*/
#ifndef NODE_CPP
#define NODE_CPP
#include "Node.h"


template<class T>

Node<T>::Node() : item(), next(nullptr) {}

template<class T>
Node<T>::Node(const Node<T>& other) : item(other.item), next(nullptr) {}
template<class T>


Node<T>::Node(const T& anitem) : item(anitem), next(nullptr) {}


template<class T>
Node<T>::Node(const T &anitem, Node<T> *nextPtr) {
    item = anitem;
    next = nextPtr;
}

template<class T>
void Node<T>::setItem(const T &anitem) {
    item = anitem;
}

template<class T>
void Node<T>::setNext(Node<T> *nextPtr) {
    next = nextPtr;
}

template<class T>
T& Node<T>::GetItem()  {
    return item;
}

template<class T>
T * Node<T>::getPointItem()  {
    return &item;
}

template<class T>
T Node<T>::getItem() const {
    return item;
}

template<class T>
Node<T> * Node<T>::getNext() const {
    return next;
}

#endif