// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

#include  <vector>
#include  <string>
#include  <algorithm>
void makeTree(BST<std::string>& tree, const char* filename) {
    std::ifstream file(filename);
    std::string word;
    while (!file.eof()) {
        int ch = file.get();
        if (file.eof()) break;

        if (ch > 0 && ch < 128 && std::isalpha(static_cast<unsigned char>(ch))) {
            word += static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
        } else {
            if (!word.empty()) {
                tree.insert(word);
                word.clear();
            }
        }
    }

    if (!word.empty()) {
        tree.insert(word);
    }

    file.close();
}

void printFreq(BST<std::string>& tree) {
    std::vector<BST<std::string>::Node*> nodes = tree.getAllNodesFreq();

    std::sort(nodes.begin(), nodes.end(),
        [](const BST<std::string>::Node* a,
            const BST<std::string>::Node* b) {
                if (a->count != b->count)
                    return a->count > b->count;
                return a->value < b->value;
        });

    std::ofstream out("freq.txt");

    for (const auto* node : nodes) {
        std::string line = node->value;
        line += " " + std::to_string(node->count);
        std::cout << line << '\n';
        if (out) out << line << '\n';
    }

    if (out) out.close();
}
