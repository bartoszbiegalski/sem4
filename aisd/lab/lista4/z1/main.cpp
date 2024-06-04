#include <iostream>
#include <random>
#include "algorithms.cpp"

int main() {
    BST tree;
    int n = 200000;
    /*/
    std::random_device rd;
    std::mt19937 g(rd());
    std::uniform_int_distribution<int> distrib(1, 2*n - 1);

    int i = 1;
    while (tree.TreeSize() < 100000) {
      tree.TreeInsert(i);
      i++;
    }

    //tree.PrintTree();

    tree.printStatistics();
    std::cout<<tree.TreeHeight()<<std::endl;
    std::cout<<tree.TreeSize()<<std::endl;
    //*/
    ///*
    RBTree rbtree;
    rbtree.TreeInsert(12);
    rbtree.TreeInsert(9);
    rbtree.TreeInsert(16);
    rbtree.TreeInsert(14);
    rbtree.TreeInsert(13);
    rbtree.TreeInsert(15);

    rbtree.PrintTree();
    //rbtree.InOrderTreeWalk();
    //*/
}
