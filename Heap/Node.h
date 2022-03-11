//
// Node.h
//
// Structure and prototype methods for a Node
//

#include <stdlib.h>
#include "TreeNode.h"

#ifndef node_h
#define node_h

typedef struct node {
    TreeNode* data;
    struct node *next;
} Node;

// Initializes a Node
Node* node_init(TreeNode *data);

#endif /* node_h */
