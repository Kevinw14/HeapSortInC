//
// Stack.c
//
// Implementation of a stack data structure
//

#include <stdio.h>
#include "Stack.h"

// Initializes a stack data stucture along with its fields.
Stack* stack_init() {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->head = NULL;
    stack->count = 0;
    return stack;
}

// Insert an element at the top of the stack.
void stack_push(Stack *stack, TreeNode *data) {
    Node* node = node_init(data);
    node->next = stack->head;
    stack->head = node;
    stack->count++;
}

// Removes an element from the top of the stack.
TreeNode* stack_pop(Stack *stack) {
    if (stack_is_empty(stack)) {
        printf("Can't perform illegal operation on empty stack: stack_pop()\n");
        exit(1);
    }

    TreeNode *results = stack->head->data;
    stack->head = stack->head->next;
    stack->count--;
    return results;
}

// Looks at the element at the top of the stack.
TreeNode* stack_peek(Stack *stack) {
    if (stack_is_empty(stack)) {
        printf("Can't perform illegal operation on empty stack: stack_peek()\n");
        exit(1);
    }

    TreeNode *results = stack->head->data;
    return results;
}

// Checks to see if the stack is empty.
int stack_is_empty(Stack *stack) {
    return stack->count == 0;
}

// Returns the size of the stack.
int stack_size(Stack *stack) {
    return stack->count;
}



