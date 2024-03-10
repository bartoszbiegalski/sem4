//
// Created by bartek on 08.03.24.

#include "Node.h"

class CycleLine {
private:
    int size;
    Node *start;

public:
    CycleLine();

    Node* getStart();
    void setStart(int value);

    void incrementSize();
    void decrementSize();

    int getSize();
};
