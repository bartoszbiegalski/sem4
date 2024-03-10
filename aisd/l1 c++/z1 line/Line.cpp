// Line.cpp
// Bartosz Biegalski, 272347

#include <iostream>
#include "Line.h"


template<typename T>
Line<T>::Line(T value) {
    this->first = new Node<T>(value);
    this->first->setNext(NULL);
    std::cout<<"I add element: "<<value<<std::endl;
}

template<typename T>
void Line<T>::push(T value) {
    Node<T> *temp = this->first;
    if(this->first == NULL) {
        this->first = new Node<T>(value);
        this->first->setNext(NULL);
    }
    else {
        while(temp->getNext() != NULL) {
            temp = temp->getNext();
        }
        temp->setNext(new Node<T>(value));
    }
    std::cout<<"I add element: "<<value<<std::endl;

}

template<typename T>
void Line<T>::pop() {
    if(this->first == NULL) {
        std::cout<<"There are no elements in the list!\n";
    }
    else if(this->first->getNext() == NULL) {
        std::cout<<"I take away element: "<<first->getValue()<<std::endl;
        this->first = NULL;
    }
    else {
        std::cout<<"I take away element: "<<first->getValue()<<std::endl;
        this->first = this->first->getNext();
    }
}

template<typename T>
void Line<T>::print() {
    Node<T> *temp = this->first;
    while(temp!= NULL) {
        std::cout<<temp->getValue()<<" ";
        temp = temp->getNext();
    }
    std::cout<<std::endl;
}

