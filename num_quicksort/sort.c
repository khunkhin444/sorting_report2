#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
int partition(int *arr, int start, int end) {
    int p = arr[end];
    int partition_idx = start;
    int i;
    int tmp;
    for(i=start; i<end; i++) {
        if(arr[i]<=p) {
            tmp = arr[i];
            arr[i]=arr[partition_idx];
            arr[partition_idx]=tmp;
            partition_idx++;
        }
    }
    // partition_idx--;
    tmp = arr[end];
    arr[end] = arr[partition_idx];
    arr[partition_idx]=tmp;
    return partition_idx;
}
void quick_sort(int *arr, int start, int end) {
    if(start < end) {
        int idx = partition(arr, start, end);
        quick_sort(arr, start, idx-1);
        quick_sort(arr, idx+1, end);
    }
}
