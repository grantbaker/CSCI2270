#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <cstddef>
#include <iostream>

using namespace std;

struct TreeNode {
    int key;

    TreeNode* left = NULL;
    TreeNode* right = NULL;
    TreeNode* parent = NULL;

    TreeNode(){};

    TreeNode(int in_key) {
        key = in_key;
    };
};

class BinaryTree {
    public:
        BinaryTree(int* in, int length);
        virtual ~BinaryTree();
        void addNodeFromRoot(int key);
        void deleteNode(TreeNode* root, int key);
        void deleteAndReplaceMinRight(TreeNode* root, int key);
        void postOrderPrint(TreeNode* node);
        void inOrderPrint(TreeNode* node);
        TreeNode* getRoot();
    protected:
    private:
        TreeNode* findMin(TreeNode* node);
        TreeNode* findMax(TreeNode* node);
        int parentSide(TreeNode* node);

        TreeNode* root = NULL;
};

#endif // BINARYTREE_H
