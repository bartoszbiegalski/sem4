// Node.cpp
// Bartosz Biegalski, 272347

#include "Node.h"

template<typename T>
Node<T>::Node(T value) {
    this->value = value;
}

template<typename T>
Node<T> *Node<T>::getNext() {
    return this->next;
}

template<typename T>
void Node<T>::setNext(Node<T> *Node) {
    this->next = Node;
}

template<typename T>
T Node<T>::getValue() {
    return this->value;
}

