#include <stdio.h>
#include <string.h>
#include "sort.h"
void swap(char **a, char **b) {
    char *tmp = *a;
    *a = *b;
    *b = tmp;
}
void max_heap_justify(char **strings, int i, int size) {
    int largest_idx;
    int lchild_idx = 2*i + 1; //left_child address
    int rchild_idx = 2*i + 2; //right_child address
    if( lchild_idx<=size && strcmp(strings[lchild_idx],strings[i])>0) {
        largest_idx = lchild_idx;
    }
    else largest_idx = i;
    if( rchild_idx<=size && strcmp(strings[rchild_idx],strings[largest_idx])>0 ) {  //this to make sure if two child larger than parent then pick the largest one.
        largest_idx = rchild_idx;
    }
    if(largest_idx!=i) { // i = largest mean parent with no child -> no larger value
        swap(&strings[largest_idx],&strings[i]);
        max_heap_justify(strings, largest_idx, size); // this to make the heap system remain max_heap status when idx change their value (ex : 3 swap with 7 while the child below have value larger than 3)
    }
}
//this function to build a max_heap system for the heap (from largest= root , to lowest=lastest child)
void bmax_heap(char **strings, int size) {
    int i;
    for(i=size/2;i>=0;i--) {
        max_heap_justify(strings, i, size);
    }
}

void heap_sort(char **strings, int size) {
    int i;
    bmax_heap(strings, size);
    for(i = size; i>=0; i--) {
        swap(&strings[i],&strings[0]);
        size--; //remove heap link/node <- idk if it is called heap link or not
        max_heap_justify(strings, 0, size); //after the swap this is to justify the max_heap not to get it wrong (if child be larger than parent)
    }
}
