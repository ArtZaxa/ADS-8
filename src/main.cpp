// Copyright 2021 NNTU-CS
#include <iostream>
#include "bst.h"
#include <string>
void makeTree(BST<std::string>& tree, const char* filename);
void printFreq(BST<std::string>& tree);

int main()
{
    const char* filename = "war_peace.txt";
    BST<std::string> tree;
    makeTree(tree, filename);
    int depth = tree.depth();
    std::cout << (depth == 35);

    printFreq(tree);

    return 0;
}
