//
// TreeNode.h
//
// Structure and prototype methods of a TreeNode
//

#include <stdlib.h>

typedef struct treenode {
    int data;
    struct treenode* left;
    struct treenode* right;
    struct treenode* parent;
    int isInHeap;
} TreeNode;

// Initalizes a TreeNode
TreeNode* treenode_init(int data);
