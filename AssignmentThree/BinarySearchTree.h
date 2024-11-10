#include "BinarySearchTreeNode.h"

class BinarySearchTree {
    private:
        BSTNode* root;
    public:
        BinarySearchTree();
        void setRoot(const std::string& rt);
        BSTNode *insertNode(BSTNode *newNode);
        BSTNode *helpInsertNode(BSTNode *newNode, BSTNode *root);
        void doinOrderTraversal() const;
        void helpInOrderTraversal(BSTNode* node) const;
        BSTNode *getRoot() const;
        BSTNode *getNode(const std::string& value);
};