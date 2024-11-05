#include "BinarySearchTreeNode.h"

class BinarySearchTree {
    private:
        BSTNode* root;
    public:
        BinarySearchTree();
        void setRoot(const std::string& rt);
        std::string insertNode(BSTNode *newNode);
        std::string helpInsertNode(BSTNode *newNode, BSTNode *root);
        BSTNode *getRoot();
};