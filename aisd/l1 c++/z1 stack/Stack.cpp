// Stack.cpp
// Bartosz Biegalski, 272347

#include <iostream>
#include "Stack.h"


template<typename T>
Stack<T>::Stack(T value) {
    this->last = new Node<T>(value);
    this->last->setPrevious(NULL);
    std::cout<<"I add element: "<<value<<std::endl;
}

template<typename T>
void Stack<T>::push(T value) {
    Node<T> *temp = this->last;
    if(this->last == NULL) {
        this->last = new Node<T>(value);
        this->last->setPrevious(NULL);
    }
    else {
        this->last = new Node<T>(value);
        this->last->setPrevious(temp);
    }
    std::cout<<"I add element: "<<value<<std::endl;

}

template<typename T>
void Stack<T>::pop() {
    if(this->last == NULL) {
        std::cout<<"There are no elements in the list!\n";
    }
    else if(this->last->getPrevious() == NULL) {
        std::cout<<"I take away element: "<<last->getValue()<<std::endl;
        this->last = NULL;
    }
    else {
        std::cout<<"I take away element: "<<last->getValue()<<std::endl;
        this->last = this->last->getPrevious();
    }
}

template<typename T>
void Stack<T>::print() {
    Node<T> *temp = this->first;
    while(temp!= NULL) {
        std::cout<<temp->getValue()<<" ";
        temp = temp->getNext();
    }
    std::cout<<std::endl;
}

