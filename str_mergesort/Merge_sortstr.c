#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#define buf_size 100
#define line_cnt 1000000


void merge(char **strings, char **left, char **right, int left_cnt, int right_cnt) {
    int i,j,k;
    i = k = j = 0;
    for(int tmp = 0; tmp< (right_cnt+left_cnt); tmp++) {
        strings[tmp] = malloc(sizeof(char)*101);
    }
    while(i<left_cnt && j<right_cnt) {
        if(strcmp(left[i],right[j])<0) {
            strcpy(strings[k],left[i]);
            k++;
            i++;
        }
        else {
            strcpy(strings[k],right[j]);
                k++;
                j++;
        }
    }
    while(i<left_cnt) {
        strcpy(strings[k],left[i]);
        k++;
        i++;
    }
    while(j<right_cnt) {
        strcpy(strings[k],right[j]);
        k++;
        j++;
    }
}
void merge_sort(char **strings, int cnt) {
    int mid, i;
    if(cnt<2) return; // lenght = 1, mean no more split.
    mid = cnt/2;
    char *left[mid];
    char *right[cnt-mid];
    
    for(i = 0; i<mid;i++) {
        left[i] = malloc(sizeof(char)*101);
        strcpy(left[i],strings[i]);
    }
    for(i = mid; i<cnt;i++) {
        right[i-mid] = malloc(sizeof(char)*101);
        strcpy(right[i-mid],strings[i]);
    }
    for(i = 0; i<cnt;i++) {
        free(strings[i]);
    }
    merge_sort(left, mid); //recursion call do the left 1st
    merge_sort(right,cnt - mid); //recursion call back to the right
    merge(strings, left, right, mid, cnt-mid); //merge to sub-array
    for(i=0;i<mid;i++) {
        free(left[i]);
    }
    for(i = mid; i<cnt;i++) {
        free(right[i-mid]);
    }
}