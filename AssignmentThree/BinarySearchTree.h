#include "BinarySearchTreeNode.h"

class BinarySearchTree {
    private:
        BSTNode* root;
    public:
        BinarySearchTree();
        void setRoot(const std::string& rt);
        BSTNode *insertNode(BSTNode *newNode);
        BSTNode *helpInsertNode(BSTNode *newNode, BSTNode *root);
        BSTNode *getRoot();
        BSTNode *getNode(const std::string& value);
};