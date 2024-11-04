#include "node.h"

class BinarySearchTree {
    private:
        Node* root;
        Node* right;
        Node* left;
    public:
        BinarySearchTree();
        void setLeft(Node *newNode);
        void setRight(Node *newNode);
        Node *getLeft();
        Node *getRight();
        std::string insertNode(Node *newNode);
        std::string helpInsertNode(Node *newNode, Node *root);
        std::string findNode(Node *node);
        std::string helpFindNode(Node *newNode, Node *root);
};