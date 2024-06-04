#include <iostream>
#include <cstdlib>

class Node {
public:
    Node *parent = NULL;
    Node *left = NULL;
    Node *right = NULL;
    int value;

    Node(int value) {
        this->value = value;
    }
};

class BST {
private:
    Node *root = NULL;
    int compareCount = 0;
    int loadCount = 0;
    int treeSize = 0;

    void treeInsert(int value, Node *root) {
        if (value < root->value) {
            compareCount++;
            if (root->left == NULL) {
                root->left = new Node(value);
                root->left->parent = root;
                compareCount++;
                loadCount += 2;
                treeSize++;
            } else {
                treeInsert(value, root->left);
            }
        } else if (value > root->value){
            compareCount++;
            if (root->right == NULL) {
                compareCount++;
                root->right = new Node(value);
                root->right->parent = root;
                loadCount += 2;
                treeSize++;
            } else {
                treeInsert(value, root->right);
            }
        }
    }

    void inOrderTreeWalk(Node *x) {
        if (x != NULL) {
            inOrderTreeWalk(x->left);
            std::cout << x->value << std::endl;
            inOrderTreeWalk(x->right);
        }
    }

    Node* treeSearch(Node *root, int k) {
        if (root == NULL || root->value == k) {
            compareCount += 2;
            return root;
        }
        if (k < root->value) {
            compareCount++;
            return treeSearch(root->left, k);
        } else {
            return treeSearch(root->right, k);
        }
    }

    Node* findMinimum(Node *root) {
        while (root->left != NULL) {
            root = root->left;
            compareCount++;
            loadCount++;
        }
        return root;
    }

    void transplant(Node*& root, Node* u, Node* v) {
        if (u->parent == NULL) {
            compareCount++;
            root = v;
        } else if (u == u->parent->left) {
            compareCount++;
            loadCount++;
            u->parent->left = v;
        } else {
            loadCount++;
            u->parent->right = v;
        }
        if (v != NULL) {
            loadCount++;
            v->parent = u->parent;
        }
    }

    void treeDelete(Node*& root, int value) {
        Node *z = treeSearch(root, value);
        if (z == NULL) {
            compareCount++;
            std::cout << "Nothing to delete\n";
            return;
        }

        if (z->left == NULL) {
            compareCount++;
            transplant(root, z, z->right);
        } else if (z->right == NULL) {
            compareCount++;
            transplant(root, z, z->left);
        } else {
            Node *y = findMinimum(z->right);
            if (y->parent != z) {
                compareCount++;
                transplant(root, y, y->right);
                y->right = z->right;
                y->right->parent = y;
                loadCount += 2;
            }
            transplant(root, z, y);
            y->left = z->left;
            y->left->parent = y;
            loadCount += 2;
        }
        delete z;
    }

    int treeHeight(Node *root) {
        if (root == NULL) return 0;
        int leftHeight = treeHeight(root->left);
        int rightHeight = treeHeight(root->right);
        return std::max(leftHeight, rightHeight) + 1;
    }

    void print_BST(Node *root, int depth, char prefix, char *left_trace, char *right_trace) {
        if (root == NULL) return;
        if (root->left != NULL) {
            print_BST(root->left, depth + 1, '/', left_trace, right_trace);
        }
        if (prefix == '/') left_trace[depth - 1] = '|';
        if (prefix == '\\') right_trace[depth - 1] = ' ';
        if (depth == 0) printf("-");
        if (depth > 0) printf(" ");
        for (int i = 0; i < depth - 1; i++) {
            if (left_trace[i] == '|' || right_trace[i] == '|') {
                printf("| ");
            } else {
                printf("  ");
            }
        }
        if (depth > 0) printf("%c-", prefix);
        printf("[%d]\n", root->value);
        left_trace[depth] = ' ';
        if (root->right != NULL) {
            right_trace[depth] = '|';
            print_BST(root->right, depth + 1, '\\', left_trace, right_trace);
        }
    }

public:
    void setRoot(Node *root) {
        this->root = root;
    }

    void TreeInsert(int value) {
        if (this->root == NULL) {
            this->setRoot(new Node(value));
            treeSize++;
        } else {
            treeInsert(value, this->root);
        }
    }

    void InOrderTreeWalk() {
        inOrderTreeWalk(this->root);
    }

    void TreeSearch(int k) {
        if (treeSearch(this->root, k) == NULL) {
            std::cout << "value " << k << " is not in this tree\n";
        } else {
            std::cout << "found value " << k << std::endl;
        }
    }

    void TreeDelete(int k) {
        treeSize--;
        treeDelete(this->root, k);
    }

    int TreeHeight() {
        return treeHeight(this->root);
    }

    void PrintTree() {
        char* left_trace = (char*) malloc(treeSize * sizeof(char));
        char* right_trace = (char*) malloc(treeSize * sizeof(char));
        for (int i = 0; i < treeSize; i++) {
            left_trace[i] = ' ';
            right_trace[i] = ' ';
        }
        print_BST(this->root, 0, '-', left_trace, right_trace);
        free(left_trace);
        free(right_trace);
    }

    int TreeSize() {
        return treeSize;
    }

    void printStatistics() {
        std::cout << "compares: " << compareCount << ", assigns and loads: " << loadCount << std::endl;
    }
};

class RBNode {
public:
    RBNode *parent = NULL;
    RBNode *left = NULL;
    RBNode *right = NULL;
    int value;
    int color = 1; // 1 for red, -1 for black

    RBNode(int value) {
        this->value = value;
    }
};

class RBTree {
private:
    RBNode *root = NULL;
    int treeSize = 0;

    void inOrderTreeWalk(RBNode *x) {
        if (x != NULL) {
            inOrderTreeWalk(x->left);
            std::cout << x->value << " " << x->color << std::endl;
            inOrderTreeWalk(x->right);
        }
    }

    RBNode* treeInsert(int value, RBNode *root) {
        if (value < root->value) {
            if (root->left == NULL) {
                root->left = new RBNode(value);
                root->left->parent = root;
                return root->left;
            } else {
                return treeInsert(value, root->left);
            }
        } else if (value > root->value) {
            if (root->right == NULL) {
                root->right = new RBNode(value);
                root->right->parent = root;
                return root->right;
            } else {
                return treeInsert(value, root->right);
            }
        } else {
            return NULL;
        }
    }

    int treeHeight(RBNode *root) {
        if (root == NULL) return 0;
        int leftHeight = treeHeight(root->left);
        int rightHeight = treeHeight(root->right);
        return std::max(leftHeight, rightHeight) + 1;
    }

    void print_RBTree(RBNode *root, int depth, char prefix, char *left_trace, char *right_trace) {
        if (root == NULL) return;
        if (root->left != NULL) {
            print_RBTree(root->left, depth + 1, '/', left_trace, right_trace);
        }
        if (prefix == '/') left_trace[depth - 1] = '|';
        if (prefix == '\\') right_trace[depth - 1] = ' ';
        if (depth == 0) printf("-");
        if (depth > 0) printf(" ");
        for (int i = 0; i < depth - 1; i++) {
            if (left_trace[i] == '|' || right_trace[i] == '|') {
                printf("| ");
            } else {
                printf("  ");
            }
        }
        if (depth > 0) printf("%c-", prefix);
        printf("[%d %s]\n", root->value, root->color == 1 ? "R" : "B");
        left_trace[depth] = ' ';
        if (root->right != NULL) {
            right_trace[depth] = '|';
            print_RBTree(root->right, depth + 1, '\\', left_trace, right_trace);
        }
    }

    RBNode* uncle(RBNode *node) {
        if (node->parent == NULL || node->parent->parent == NULL) return NULL;
        if (node->parent == node->parent->parent->left) {
            return node->parent->parent->right;
        } else {
            return node->parent->parent->left;
        }
    }

    bool zigzag(RBNode *node) {
        if ((node->parent->right == node && node->parent->parent->right == node->parent) ||
            (node->parent->left == node && node->parent->parent->left == node->parent)) {
            return false;
        } else {
            return true;
        }
    }

    void leftRotate(RBNode *node) {
        RBNode *temp = node->right;
        node->right = temp->left;
        if (temp->left != NULL) {
            temp->left->parent = node;
        }
        temp->parent = node->parent;
        if (node->parent == NULL) {
            root = temp;
        } else if (node == node->parent->left) {
            node->parent->left = temp;
        } else {
            node->parent->right = temp;
        }
        temp->left = node;
        node->parent = temp;
    }

    void rightRotate(RBNode *node) {
        RBNode *temp = node->left;
        node->left = temp->right;
        if (temp->right != NULL) {
            temp->right->parent = node;
        }
        temp->parent = node->parent;
        if (node->parent == NULL) {
            root = temp;
        } else if (node == node->parent->right) {
            node->parent->right = temp;
        } else {
            node->parent->left = temp;
        }
        temp->right = node;
        node->parent = temp;
    }

    void fixup(RBNode *currentNode) {
        while (currentNode != root && currentNode->parent->color == 1) {
            RBNode *uncleNode = uncle(currentNode);
            if (uncleNode != NULL && uncleNode->color == 1) {  // Case 1: Uncle is red
                currentNode->parent->color = -1;
                uncleNode->color = -1;
                currentNode->parent->parent->color = 1;
                currentNode = currentNode->parent->parent;
            } else {  // Case 2: Uncle is black
                if (zigzag(currentNode)) {  // Sub-case 2.1: Zigzag pattern
                    if (currentNode == currentNode->parent->right) {
                        leftRotate(currentNode->parent);
                        currentNode = currentNode->left;
                    } else {
                        rightRotate(currentNode->parent);
                        currentNode = currentNode->right;
                    }
                } else {  // Sub-case 2.2: Linear pattern
                    currentNode->parent->color = -1;
                    currentNode->parent->parent->color = 1;
                    if (currentNode == currentNode->parent->left) {
                        rightRotate(currentNode->parent->parent);
                    } else {
                        leftRotate(currentNode->parent->parent);
                    }
                }
            }
        }
        root->color = -1;  // Root must always be black
    }

public:
    void setRoot(RBNode *root) {
        this->root = root;
    }

    void InOrderTreeWalk() {
        inOrderTreeWalk(this->root);
    }

    void TreeInsert(int value) {
        if (root == NULL) {
            root = new RBNode(value);
            root->color = -1;  // Root is always black at the beginning
        } else {
            RBNode *newNode = treeInsert(value, root);
            if (newNode != NULL) {
                fixup(newNode);
            }
        }
        treeSize++;
    }

    int TreeHeight() {
        return treeHeight(this->root);
    }

    void PrintTree() {
        char* left_trace = (char*) malloc(treeSize * sizeof(char));
        char* right_trace = (char*) malloc(treeSize * sizeof(char));
        for (int i = 0; i < treeSize; i++) {
            left_trace[i] = ' ';
            right_trace[i] = ' ';
        }
        print_RBTree(this->root, 0, '-', left_trace, right_trace);
        free(left_trace);
        free(right_trace);
    }
};
