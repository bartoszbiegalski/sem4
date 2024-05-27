#include <iostream>
#include <thread>
#include <chrono>
#include "Stack.cpp"

int main() {

    Stack<int> *stack = new Stack<int>();

    for(int i = 1; i <= 50; i++) {
        stack->push(i);
    }
    std::this_thread::sleep_for(std::chrono::seconds(2));
    stack->print();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    for(int i = 1; i <= 50; i++) {
        stack->pop();
    }
    std::this_thread::sleep_for(std::chrono::seconds(2));
    /// trying to pop when stack is empty will cause warning
    stack->pop();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    stack->push(12);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    stack->pop();

    return 0;
}
