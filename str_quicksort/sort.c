#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

void swap_string(char **str1, char **str2) {
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

int partition(char **strings, int start, int end) {
    char *tmp = malloc(sizeof(char)*101);
    strcpy(tmp,strings[end]);
    int partition_idx = start;
    int i;
    for(i=start; i<end; i++) {
        if(strcmp(strings[i],tmp)<=0) {
            swap_string(&strings[i],&strings[partition_idx]);
            partition_idx++;
        }
    }
    swap_string(&strings[end],&strings[partition_idx]);
    free(tmp);
    return partition_idx;
}
void quick_sort(char **strings, int start, int end) {
    if(start < end) {
        int idx = partition(strings, start, end);
        quick_sort(strings, start, idx-1);
        quick_sort(strings, idx+1, end);
    }
}
