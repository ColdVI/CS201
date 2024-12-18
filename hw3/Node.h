/*
Anil Keskin
Sec3
22201915
*/

#ifndef NODE_H
#define NODE_H


template <class T>
class Node {



    public:
    T item;
    Node<T>* next;
    Node();
    Node(const Node<T>& other);
    explicit Node(const T& anitem);
    Node(const T& anitem, Node<T>* nextPtr);
    void setItem(const T& item);
    void setNext(Node<T>* nextPtr);
    T& GetItem() ;
    T* getPointItem() ;
    T getItem() const;
    Node<T>* getNext() const;
    auto operator==(const Node<T> &other) const -> bool;


};

template<class T>
bool Node<T>::operator==(const Node<T> &other) const {
    return (item == other.item);
}


#include "Node.cpp"
#endif




