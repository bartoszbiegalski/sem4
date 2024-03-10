//
// Created by bartek on 08.03.24.
//

#include <iostream>
#include "CycleLine.h"

CycleLine::CycleLine() {
    this->size = 0;
    this->start = nullptr;

}

Node *CycleLine::getStart() {
    return this->start;
}

int CycleLine::getSize() {
    return this->size;
}

void CycleLine::setStart(int value) {
    this->start = new Node(value);
}

void CycleLine::incrementSize() {
    this->size = this->size + 1;
}

