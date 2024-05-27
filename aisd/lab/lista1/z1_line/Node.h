// Node.h
// Bartosz Biegalski, 272347

template <typename T>
class Node {
private:
	T value;
	Node* next;
public:
	explicit Node<T>(T value);
    Node* getNext();
	T getValue();
    void setNext(Node<T> *Node);
};

