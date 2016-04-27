#include "BinaryTree.h"

using namespace std;

BinaryTree::BinaryTree(int* in, int length) {
    BinaryTree::root = NULL;
    int i;
    for (i=0;i<length;i++) {
        BinaryTree::addNodeFromRoot(in[i]);
    }

}

BinaryTree::~BinaryTree() {

}

void BinaryTree::addNodeFromRoot(int key) {
    if (BinaryTree::root == NULL) {
        BinaryTree::root = new TreeNode(key);
        return;
    }
    TreeNode* tmp = root;
    TreeNode* parent;
    while(tmp!=NULL) {
        parent = tmp;
        if (key < tmp->key) {
            tmp = tmp->left;
        } else {
            tmp = tmp->right;
        }
    }
    if (key < parent->key) {
        parent->left = new TreeNode(key);
        parent->left->parent = parent;
    } else {
        parent->right = new TreeNode(key);
        parent->right->parent = parent;
    }

}

TreeNode* BinaryTree::getRoot() {
    return BinaryTree::root;
}

void BinaryTree::postOrderPrint(TreeNode* node) {
    if (node->left != NULL) {
        postOrderPrint(node->left);
    }
    if (node->right != NULL) {
        postOrderPrint(node->right);
    }
    cout<<node->key<<endl;
}

void BinaryTree::inOrderPrint(TreeNode* node) {
    if (node->left != NULL) {
        inOrderPrint(node->left);
    }
    cout<<node->key<<endl;
    if (node->right != NULL) {
        inOrderPrint(node->right);
    }
}

TreeNode* BinaryTree::findMin(TreeNode* node) {
    TreeNode* tmp = node;
    while(tmp->left != NULL) {
        tmp = tmp->left;
    }
    return tmp;
}

TreeNode* BinaryTree::findMax(TreeNode* node) {
    TreeNode* tmp = node;
    while(tmp->right != NULL) {
        tmp = tmp->right;
    }
    return tmp;
}

int BinaryTree::parentSide(TreeNode* node) {
    if (node->parent == NULL) {
        return 0;
    }
    if (node->parent->left == node) {
        return -1;
    }
    if (node->parent->right == node) {
        return 1;
    }
    return 0;
}

void BinaryTree::deleteNode(TreeNode* root, int key) {
    TreeNode* tmp = root;
    while(tmp->key != key && tmp != NULL) {
        if (key < tmp->key) {
            tmp = tmp->left;
        } else {
            tmp = tmp->right;
        }
    }

    int side = BinaryTree::parentSide(tmp);
    if (tmp->left == NULL && tmp->right == NULL) {
        if (side == 0) {
            delete BinaryTree::root;
        }
        if (side == -1) {
            tmp->parent->left = NULL;
        }
        if (side == 1) {
            tmp->parent->right = NULL;
        }
        return;
    }
    if (tmp->left != NULL && tmp->right == NULL) {
        tmp->left->parent = tmp->parent;
        if (side == -1) {
            tmp->parent->left = tmp->left;
        }
        if (side == 1) {
            tmp->parent->right = tmp->left;
        }
        if (side == 0) {
            BinaryTree::root = tmp->left;
        }
    }
    if (tmp->right != NULL && tmp->left == NULL) {
        tmp->right->parent = tmp->parent;
        if (side == -1) {
            tmp->parent->left = tmp->right;
        }
        if (side == 1) {
            tmp->parent->right = tmp->right;
        }
        if (side == 0) {
            BinaryTree::root = tmp->right;
        }
    }
    if (tmp->left != NULL && tmp->right != NULL) {
        TreeNode* mx = BinaryTree::findMax(tmp->left);
        if (mx->parent != tmp) {
            mx->parent->right = mx->left;
            if (mx->left != NULL) {
                mx->left->parent = mx->parent;
            }
            mx->left = tmp->left;
            mx->left->parent = mx;
            mx->right = tmp->right;
            mx->right->parent = mx;
            mx->parent = tmp->parent;
            if (side == -1) {
                mx->parent->left = mx;
            }
            if (side == 1) {
                mx->parent->right = mx;
            }
            if (side == 0) {
                BinaryTree::root = mx;
            }
        } else {
            mx->right = tmp->right;
            mx->right->parent = mx;
            mx->parent = tmp->parent;
            if (side == -1) {
                mx->parent->left = mx;
            }
            if (side == 1) {
                mx->parent->right = mx;
            }
            if (side == 0) {
                BinaryTree::root = mx;
            }
        }
    }
}

void BinaryTree::deleteAndReplaceMinRight(TreeNode* root, int key) {
    TreeNode* tmp = root;
    while(tmp->key != key && tmp != NULL) {
        if (key < tmp->key) {
            tmp = tmp->left;
        } else {
            tmp = tmp->right;
        }
    }
    int side = BinaryTree::parentSide(tmp);
    if (tmp->left == NULL && tmp->right == NULL) {
        if (side == 0) {
            delete BinaryTree::root;
        }
        if (side == -1) {
            tmp->parent->left = NULL;
        }
        if (side == 1) {
            tmp->parent->right = NULL;
        }
        return;
    }
    if (tmp->left != NULL && tmp->right == NULL) {
        tmp->left->parent = tmp->parent;
        if (side == -1) {
            tmp->parent->left = tmp->left;
        }
        if (side == 1) {
            tmp->parent->right = tmp->left;
        }
        if (side == 0) {
            BinaryTree::root = tmp->left;
        }
    }
    if (tmp->right != NULL && tmp->left == NULL) {
        tmp->right->parent = tmp->parent;
        if (side == -1) {
            tmp->parent->left = tmp->right;
        }
        if (side == 1) {
            tmp->parent->right = tmp->right;
        }
        if (side == 0) {
            BinaryTree::root = tmp->right;
        }
    }
    if (tmp->left != NULL && tmp->right != NULL) {
        TreeNode* mn = BinaryTree::findMin(tmp->right);
        if (mn->parent != tmp) {
            mn->parent->left = mn->right;
            if (mn->right != NULL) {
                mn->right->parent = mn->parent;
            }
            mn->left = tmp->left;
            mn->left->parent = mn;
            mn->right = tmp->right;
            mn->right->parent = mn;
            mn->parent = tmp->parent;
            if (side == -1) {
                mn->parent->left = mn;
            }
            if (side == 1) {
                mn->parent->right = mn;
            }
            if (side == 0) {
                BinaryTree::root = mn;
            }
        } else {
            mn->left = tmp->left;
            mn->left->parent = mn;
            mn->parent = tmp->parent;
            if (side == -1) {
                mn->parent->left = mn;
            }
            if (side == 1) {
                mn->parent->right = mn;
            }
            if (side == 0) {
                BinaryTree::root = mn;
            }
        }
    }
}
