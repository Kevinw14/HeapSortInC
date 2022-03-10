//
// TreeNode.c
//
// Implementation of a TreeNode
//

#include "TreeNode.h"

// Initalizes a TreeNode and it's fields.
TreeNode* treenode_init(int data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->isInHeap = 1;
    return node;
}
