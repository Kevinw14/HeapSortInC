//
// Stack.h
// 
// Prototype methods and structure of a stack data structure
//

#include <stdlib.h>
#include "Node.h"

#ifndef stack_h
#define stack_h

typedef struct stack {
    int count;
    Node *head;
} Stack;

// Initializes a stack data structure.
Stack* stack_init(void);

// Inserts an element to the stack.
void stack_push(Stack *stack, TreeNode* data);

// Removes an element from the stack
TreeNode* stack_pop(Stack *stack);

// Looks at the first element at the top of the stack.
TreeNode* stack_peek(Stack *stack);

// Returns the size of the stack.
int stack_size(Stack *stack);

// Checks to see if the stack is empty
int stack_is_empty(Stack *stack);

#endif /* stack_h */
