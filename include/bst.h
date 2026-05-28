// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <vector>
template <typename T>
class BST {
 public:
    struct Node {
        T value;
        int count;
        Node* left;
        Node* right;

        Node(const T& val)
            : value(val), count(1), left(nullptr), right(nullptr) {}
    };

 private:
    Node* root;
    Node* insertNode(Node* node, const T& value) {
        if (!node) return new Node(value);

        if (value == node->value) {
            node->count++;
        } else if (value < node->value) {
            node->left = insertNode(node->left, value);
        } else {
            node->right = insertNode(node->right, value);
        }
        return node;
    }

    Node* searchNode(Node* node, const T& value) const {
        if (!node) return nullptr;
        if (value == node->value) return node;
        if (value < node->value)  return searchNode(node->left, value);
        return searchNode(node->right, value);
    }
    int depthNode(Node* node) const {
        if (!node) return -1;
        int l = depthNode(node->left);
        int r = depthNode(node->right);
        return 1 + (l > r ? l : r);
    }

    void destroyTree(Node* node) {
        if (!node) return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

    void collectNodes(Node* node, std::vector<Node*>& vec) const {
        if (!node) return;
        collectNodes(node->right, vec);
        vec.push_back(node);
        collectNodes(node->left, vec);
    }

 public:
    BST()  : root(nullptr) {}
    ~BST() { destroyTree(root); }

    void insert(const T& value) {
        root = insertNode(root, value);
    }
    int search(const T& value) const {
        Node* node = searchNode(root, value);
        return node ? node->count : 0;
    }
    int depth() const {
        return depthNode(root);
    }
    bool empty() const { return root == nullptr; }

    std::vector<Node*> getAllNodesFreq() const {
        std::vector<Node*> vec;
        collectNodes(root, vec);
        return vec;
    }
};


#endif  // INCLUDE_BST_H_
