#include "BinarySearchTreeNode.h"

class BinarySearchTree {
    private:
        BSTNode* root;
        int totalComparisons;
    public:
        BinarySearchTree();
        const int getTotalComparisons() const;
        void setRoot(const std::string& rt);
        BSTNode *insertNode(BSTNode *newNode);
        BSTNode *helpInsertNode(BSTNode *newNode, BSTNode *root);
        void doinOrderTraversal() const;
        void helpInOrderTraversal(BSTNode* node) const;
        BSTNode *getRoot() const;
        BSTNode *getNode(const std::string& value);
};