//
// Queue.h
//
// Prototype methods and structure of a queue data structure
//

#include <stdlib.h>
#include "Node.h"

#ifndef queue_h
#define queue_h

typedef struct queue {
    int count;
    Node *head;
    Node *tail;
} Queue;


// Initalizes a queue.
Queue* queue_init(void);

// Inserts an element at the end of the queue.
void queue_enqueue(Queue *queue, TreeNode* data);

// Removes an element from the front of the queue.
TreeNode* queue_dequeue(Queue *queue);

// Looks at the element at the front of the queue.
TreeNode* queue_first(Queue *queue);

// Returns the size of the queue.
int queue_size(Queue *queue);

// Checks to see if the queue is empty.
int queue_is_empty(Queue *queue);

#endif /* queue_h */
