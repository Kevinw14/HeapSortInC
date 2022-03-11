//
// Heap.h
//
// Prototype methods and structure of a heap data structure
//

#include <stdlib.h>
#include "Stack.h"
#include "Queue.h"

#ifndef heap_h
#define heap_h

typedef struct heap {
    int count;
    Stack *stack;
    Queue *queue;
    TreeNode *root;
} Heap;

// Initilizes a heap data structure
Heap* heap_init(void);

// Inserts a integer into the heap
void heap_insert(Heap *heap, int data);

// Checks to see if there is any nodes in the heap
int heap_is_empty(Heap *heap);

// Returns the height of the tree
int heap_height(Heap *heap);

// Performs level order traversal on heap
void heap_level_order_traversal(Heap *heap);

// Sorts the heap from smallest to largest
void heap_sort(Heap *heap);

#endif /* heap_h */
