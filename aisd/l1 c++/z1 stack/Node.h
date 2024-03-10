// Node.h
// Bartosz Biegalski, 272347

template <typename T>
class Node {
private:
	T value;
	Node* previous;
public:
	explicit Node<T>(T value);
    Node* getPrevious();
	T getValue();
    void setPrevious(Node<T> *Node);
};

