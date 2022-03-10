//
// Heap.c
//
// Implementation of the heap data structure
//

#include <stdio.h>
#include <math.h>
#include "Heap.h"

// Initializes a heap and all of it's fields
Heap* heap_init(void) {
    Heap *heap = (Heap*)malloc(sizeof(Heap));
    Stack *stack = stack_init();
    Queue *queue = queue_init();
    heap->stack = stack;
    heap->queue = queue;
    heap->count = 0;
    heap->root = NULL;
    return heap;
}

// Takes in two nodes and swaps their values.
void swap(TreeNode *a, TreeNode* b) {
    int temp_data = b->data;

    if (a->data > b->data) {
        b->data = a->data;
        a->data = temp_data;
    }
    
}

// Recursive call that sifts the new value up to its new position in the tree to
// maintain the max heap property. When inserting a new value, the heap inserts
// at the bottom most right. It then sifts upward to maintain the heap property.
void sift_up(TreeNode *node) {
    if (node->parent != NULL && node->data > node->parent->data) {
        int temp_data = node->data;
        node->data = node->parent->data;
        node->parent->data = temp_data;
        sift_up(node->parent);
    }
}

// Inserts into the tree from left to right, top to bottom.
// Once inserted the new value sifts it's way up the tree to
// it's new position to maintain the max heap property.
void heap_insert(Heap *heap, int data) {
    TreeNode *node = treenode_init(data);
    
    if (heap->root == NULL) {
        heap->root = node;
        queue_enqueue(heap->queue, node);
        heap->count++;
        return;
    }

    TreeNode *parent = queue_first(heap->queue);
    node->parent = parent;

    if (parent->left == NULL) {
        parent->left = node;
    } else {
        parent->right = node;
        queue_dequeue(heap->queue);
    }

    queue_enqueue(heap->queue, node);
    stack_push(heap->stack, node);
    heap->count++;
    sift_up(node);

}

// Removes the bottom most right leaf in the tree.
TreeNode* heap_remove_lowest_leaf(Heap *heap) {
    TreeNode* lowest = stack_pop(heap->stack);
    heap->count--;
    return lowest;
}

// Recursive level order traversal performed on the heap.
// Private method
void level_order_traversal(Queue *queue) {
    if (queue_is_empty(queue))
        return;

    TreeNode *node = queue_dequeue(queue);
    printf("%i\n", node->data);

    if (node->left != NULL)
        queue_enqueue(queue, node->left);
    if (node->right != NULL)
        queue_enqueue(queue, node->right);
    
    level_order_traversal(queue);
}

// Initializes the queue used in level order traversal
// Inserts the root then calls the recursive level order traversal
// to print out the tree.
void heap_level_order_traversal(Heap *heap) {
    Queue* node_queue = queue_init();
    queue_enqueue(node_queue, heap->root);
    level_order_traversal(node_queue);
}

// Recursive call to calculate the height of the tree.
// Private method
int heap_recursive_height(TreeNode *node) {
    if (node == NULL)
        return 0;

    int left = heap_recursive_height(node->left);
    int right = heap_recursive_height(node->right);

    return fmax(left, right) + 1;
}

// Calls the recursive call to calculate the height and passes in
// the root of the tree
int heap_height(Heap *heap) {
    return heap_recursive_height(heap->root);
}

// Returns the number of nodes in the tree
int heap_size(Heap *heap) {
    return heap->count;
}

// Checks if the heap is empty
int heap_is_empty(Heap *heap) {
    return heap->stack->count == 0;
}

// When sorting this recursive method is called to make sure
// the tree maintains max heap property.
void max_heapify(TreeNode *node) {
    TreeNode *left = node->left;
    TreeNode *right = node->right;
    TreeNode *largest = node;
    
    if (left != NULL && left->isInHeap && left->data > node->data)
        largest = left;
    
    if (right != NULL && right->isInHeap && right->data > largest->data)
        largest = right;
    
    if (largest->data != node->data) {
        swap(largest, node);
        max_heapify(largest);
    }
}

// Sorts the heap from smallest to largest value
void heap_sort(Heap *heap) {
    if (heap_is_empty(heap))
        return;
                
    TreeNode *root = heap->root;
    TreeNode *lowest = heap_remove_lowest_leaf(heap);
    lowest->isInHeap = 0;
    swap(root, lowest);
    max_heapify(root);
    heap_sort(heap);
}
