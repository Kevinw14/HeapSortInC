//
// Node.c
//
// Implentation of a Node
//

#include "Node.h"

// Initalizes a Node
Node* node_init(TreeNode *data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}
