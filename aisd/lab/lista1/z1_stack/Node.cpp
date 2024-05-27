// Node.cpp
// Bartosz Biegalski, 272347

#include "Node.h"

template<typename T>
Node<T>::Node(T value) {
    this->value = value;
}

template<typename T>
Node<T> *Node<T>::getPrevious() {
    return this->previous;
}

template<typename T>
void Node<T>::setPrevious(Node<T> *Node) {
    this->previous = Node;
}

template<typename T>
T Node<T>::getValue() {
    return this->value;
}

