//
// Created by bartek on 08.03.24.
//

#include "Node.h"


Node::Node(int value) {
    this->value = value;
}

Node *Node::getNext() {
    return this->next;
}

void Node::setNext(Node *node) {
    this->next = node;
}

Node *Node::getPrevious() {
    return this->previous;
}

void Node::setPrevious(Node *node) {
    this->previous = node;
}

int Node::getValue() {
    return this->value;
}