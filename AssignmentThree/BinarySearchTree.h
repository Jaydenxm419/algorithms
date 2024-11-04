#include "BinarySearchTreeNode.h"

class BinarySearchTree {
    private:
        BSTNode* root;
    public:
        BinarySearchTree();
        void setRoot(const std::string& rt);
        BSTNode *getRoot();
};