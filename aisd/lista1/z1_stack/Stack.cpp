// Stack.cpp
// Bartosz Biegalski, 272347

#include <iostream>
#include "Stack.h"

template<typename T>
void Stack<T>::push(T value) {
    Node<T> *temp = this->top;
    if(this->top == NULL) {
        this->top = new Node<T>(value);
        this->top->setPrevious(NULL);
    }
    else {
        this->top = new Node<T>(value);
        this->top->setPrevious(temp);
    }
    std::cout<<"I add element: "<<value<<std::endl;
}

template<typename T>
void Stack<T>::pop() {
    if(this->top == NULL) {
        std::cout<<"There are no elements in the stack!\n";
    }
    else if(this->top->getPrevious() == NULL) {
        std::cout<<"I take away element: "<<top->getValue()<<std::endl;
        this->top = NULL;
    }
    else {
        std::cout<<"I take away element: "<<top->getValue()<<std::endl;
        this->top = this->top->getPrevious();
    }
}

template<typename T>
void Stack<T>::print() {
    Node<T> *temp = this->top;
    while(temp != NULL) {
        std::cout<<temp->getValue()<<" ";
        temp = temp->getPrevious();
    }
    std::cout<<std::endl;
}

