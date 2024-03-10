#include <iostream>
#include "Line.cpp"


int main() {
    Line<int> *line = new Line<int>(1);

    for(int i = 2; i <= 50; i++) {
       line->push(i);
    }
    line->print();

    for(int i = 1; i <= 50; i++) {
        line->pop();
    }
    line->pop();
    line->push(10);
    line->print();
    line->pop();

    return 0;

}
