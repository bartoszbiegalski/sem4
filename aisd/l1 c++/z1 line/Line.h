// Line.h
// Bartosz Biegalski, 272347
#include "Node.cpp"

template<typename T>
class Line {
private:
	Node<T> *first;
public:
	explicit Line(T value);
	void pop();
	void push(T value);
	void print();
};

