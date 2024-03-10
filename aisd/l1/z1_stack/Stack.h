// Stack.h
// Bartosz Biegalski, 272347
#include "Node.cpp"

template<typename T>
class Stack {
private:
	Node<T> *top;
public:
	void pop();
	void push(T value);
	void print();
};

