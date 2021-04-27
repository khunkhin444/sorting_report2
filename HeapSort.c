#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define buf_size 1000000

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
//this function is to justify the heap into max_heap system
void max_heap_justify(int *arr, int i, int size) {
    int largest_idx;
    int lchild_idx = 2*i + 1; //left_child address
    int rchild_idx = 2*i + 2; //right_child address
    if( lchild_idx<=size && arr[lchild_idx]>arr[i] ) {
        largest_idx = lchild_idx;
    }
    else largest_idx = i;
    if( rchild_idx<=size && arr[rchild_idx]>arr[largest_idx] ) {  //this to make sure if two child larger than parent then pick the largest one.
        largest_idx = rchild_idx;
    }
    if(largest_idx!=i) { // i = largest mean parent with no child -> no larger value
        swap(&arr[largest_idx],&arr[i]);
        max_heap_justify(arr, largest_idx, size); // this to make the heap system remain max_heap status when idx change their value (ex : 3 swap with 7 while the child below have value larger than 3)
    }
}
//this function to build a max_heap system for the heap (from largest= root , to lowest=lastest child)
void bmax_heap(int *arr, int size) {
    int i;
    for(i=size/2;i>=0;i--) {
        max_heap_justify(arr, i, size);
    }
}

void heap_sort(int *arr, int size) {
    int i;
    bmax_heap(arr, size);
    for(i = size; i>=0; i--) {
        swap(&arr[i],&arr[0]);
        size--; //remove heap link/node <- idk if it is called heap link or not
        max_heap_justify(arr, 0, size); //after the swap this is to justify the max_heap not to get it wrong (if child be larger than parent)
    }
}

int main() {
    FILE *fp;
    struct timeval start;
    struct timeval end;
    unsigned long time;
    fp = fopen("dataset1.txt","r");
    int arr[buf_size];
    char line[2048];
    int i=0;
    int tmp;
    while(fgets(line,2048,fp)) {
    	//printf("check\n");
        tmp = atoi(line);
        //printf("check\n");
        arr[i] = tmp;
        //printf("check\n");
        i++;
    }
    gettimeofday(&start,NULL);
    heap_sort(arr, buf_size-1);
    gettimeofday(&end,NULL);
    time = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    for(i=0;i<buf_size;i++) printf("%d\n",arr[i]);
    fclose(fp);
    printf("Sorting performance (Heap) %ld us (equal %f sec)\n",time,time/100000.0);
}
