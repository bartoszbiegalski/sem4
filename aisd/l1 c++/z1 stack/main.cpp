#include <iostream>
#include "Stack.cpp"

int main() {

    Stack<int> *stack = new Stack<int>(1);

    for(int i = 2; i <= 50; i++) {
        stack->push(i);
    }

    for(int i = 1; i <= 50; i++) {
        stack->pop();
    }

    stack->pop();

    stack->push(12);

    stack->pop();

    return 0;
}
