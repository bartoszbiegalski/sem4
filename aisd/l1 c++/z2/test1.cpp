#include <iostream>
#include <random>

#include "CycleLine.h"

void insert(CycleLine *cycleLine, int value);

void print(CycleLine *cycleLine);

CycleLine* merge(CycleLine *cycleLine1, CycleLine *cycleLine2);

int cost(CycleLine *cycleLine, int value);

int main() {
    CycleLine *cycleLine1 = new CycleLine();

    CycleLine *cycleLine2 = new CycleLine();

    for(int i = 20; i <= 30; i++) {
        insert(cycleLine1, i);
        insert(cycleLine2, i + 20);
    }

    print(cycleLine1);
    print(cycleLine2);

    CycleLine *mergedCycleLine = merge(cycleLine1, cycleLine2);

    print(mergedCycleLine);

    delete cycleLine1;
    delete cycleLine2;

    CycleLine *randomCycleLine = new CycleLine();
    ///

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist1(1,100000); // distribution in range [1, 6]
    std::uniform_int_distribution<std::mt19937::result_type> dist2(1,10000); // distribution in range [1, 6]

    int *T = new int[10000];

    for (int i = 0; i<10000; i++) {
        T[i] = dist1(rng);
        insert(randomCycleLine,T[i]);
    }

    /// case 1: 1000 random indexes of T array
    double average1 = 0.0;
    for(int i = 0; i < 1000; i++) {
        int x = dist2(rng);
        average1 = (double) cost(randomCycleLine, T[x]) + average1;
    }
    average1 = average1 / 1000.0;

    std::cout<<"First case: "<<average1<<std::endl;

    /// case 2: 1000 total random numbers between 1 and 100 000

    double average2 = 0.0;
    for(int i = 0; i < 1000; i++) {
        int x = dist1(rng);
        average2 = (double) cost(randomCycleLine, x) + average2;
    }
    average2 = average2 / 1000.0;

    std::cout<<"Second case: "<<average2<<std::endl;

    return 0;
}

void insert(CycleLine *cycleLine, int value) {

    if (cycleLine->getStart() == NULL) {
        cycleLine->setStart(value);
        cycleLine->getStart()->setNext(cycleLine->getStart());
        cycleLine->incrementSize();

    } else {
        Node *node = cycleLine->getStart()->getNext();
        cycleLine->getStart()->setNext(new Node(value));
        cycleLine->getStart()->getNext()->setNext(node);
        cycleLine->incrementSize();
    }
}

void print(CycleLine *cycleLine) {
    Node *node = cycleLine->getStart();
    int size = cycleLine->getSize();
    while (size >= 0) {
        std::cout<<node->getValue()<<" ";
        node = node->getNext();
        size--;
    }
    std::cout<<std::endl;
}

CycleLine* merge(CycleLine *cycleLine1, CycleLine *cycleLine2) {
    if(cycleLine1->getStart() == nullptr && cycleLine2->getStart() == nullptr) {
        return new CycleLine;
    } else if (cycleLine1->getStart() == nullptr) {
        return cycleLine2;
    } else if (cycleLine2->getStart() == nullptr) {
        return cycleLine1;
    } else {

        Node *node1 = cycleLine1->getStart()->getNext(); /// second element of first line, the last element of the second wants to
        /// remember it
        cycleLine1->getStart()->setNext(cycleLine2->getStart()); /// now we connected beginning of the second line

        int size2 = cycleLine2->getSize();
        Node *temp = cycleLine2->getStart();

        size2--;
        cycleLine1->incrementSize();

        while (size2 > 0) {
            temp = temp->getNext();
            cycleLine1->incrementSize();
            size2--;
        }
        temp->setNext(node1);

        return cycleLine1;
    }
}

int cost(CycleLine *cycleLine, int value) {
    int counter = 0;
    Node *node = cycleLine->getStart();
    while (cycleLine->getSize() > counter) {
        counter++;
        if (node->getValue() == value) {
            return counter;
        } else {
            node = node->getNext();
        }
    }
    return counter;
}

