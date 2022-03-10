//
// main.c
//
// C application that uses a max heap data structure to store integers
// and sort them from smallest to largest.
//

#include <stdio.h>
#include "Heap.h"

int main(void) {
    int num; // store incoming integer
    Heap *heap = heap_init(); // initialize heap data structure
    
    while (scanf("%d", &num) != EOF) {
        heap_insert(heap, num); // insert the number read in into the heap
    }
    
    printf("Before Sort\n");
    heap_level_order_traversal(heap); // uses level order traversal to print out the tree
    
    heap_sort(heap);
    
    printf("\nAfter Sort\n");
    // after sorting performing level order traveral results in the integers being in order, smallest to largest
    heap_level_order_traversal(heap);
    
    int height = heap_height(heap);
    printf("\nHeight of tree: %i\n", height);
    
    return 0;
}
