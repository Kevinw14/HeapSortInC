//
// Queue.c
//
// Implementation of a queue data structure
//

#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"

// Initalizes a queue data structure along with its fields.
Queue* queue_init(void) {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->count = 0;
    return queue;
}

// Inserts an element at the end of the queue.
void queue_enqueue(Queue *queue, TreeNode* data) {
    Node *node = node_init(data);

    if (queue_is_empty(queue))
        queue->head = node;
    else
        queue->tail->next = node;

    queue->tail = node;
    queue->count++;

}

// Removes an element from the front of the queue.
TreeNode* queue_dequeue(Queue* queue) {
    if (queue_is_empty(queue)) {
        printf("Illegal operation on empty queue: queue_dequeue()\n");
        exit(1);
    }

    TreeNode *results = queue->head->data;
    queue->head = queue->head->next;

    if (queue_is_empty(queue))
        queue->tail = NULL;

    queue->count--;
    return results;
}

// Looks at the element at the front of the queue.
TreeNode* queue_first(Queue* queue) {
    if (queue_is_empty(queue)) {
        printf("Illegal operation on empty queue: queue_first()\n");
        exit(1);
    }

    TreeNode *results = queue->head->data;
    return results;
}

// Checks to see if the queue is empty.
int queue_is_empty(Queue* queue) {
    return queue->count == 0;
}

// Returns the size of the queue.
int queue_size(Queue* queue) {
    return queue->count;
}

