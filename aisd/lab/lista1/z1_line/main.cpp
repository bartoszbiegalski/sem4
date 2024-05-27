#include <iostream>
#include <thread>
#include <chrono>
#include "Line.cpp"


int main() {
    Line<int> *line = new Line<int>(1);

    for(int i = 2; i <= 50; i++) {
       line->push(i);
      
    }
    std::this_thread::sleep_for(std::chrono::seconds(2));
    line->print();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    for(int i = 1; i <= 50; i++) {
        line->pop();
    }
    std::this_thread::sleep_for(std::chrono::seconds(2));
    line->pop();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    line->push(10);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    line->print();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    line->pop();

    return 0;

}
