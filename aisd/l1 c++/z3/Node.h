//
// Created by bartek on 08.03.24.
//

class Node {
private:
    int value;
    Node *next;
    Node *previous;

public:
    explicit Node(int value);

    Node* getNext();
    void setNext(Node *node);

    Node* getPrevious();
    void setPrevious(Node *node);

    int getValue();
};

