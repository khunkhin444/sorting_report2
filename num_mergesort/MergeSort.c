#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define buf_size 1000000

void merge(int *arr, int *left, int *right, int left_len, int right_len) {
    int i,j,k;
    i = 0;
    j = 0;
    k = 0;
    while(i<left_len && j<right_len) {
        if(left[i]<right[j]) arr[k++] = left[i++]; 
        else arr[k++]=right[j++];
    }
    while(i<left_len) arr[k++] = left[i++];
    while(j<right_len) arr[k++] = right[j++];
}
void merge_sort(int *arr, int len) {
    int mid, i, *left, *right;
    if(len<2) return; // lenght = 1, mean no more split.
    mid = len/2;
    left = (int*)malloc(mid*(sizeof(int)));
    right = (int*)malloc((len-mid)*(sizeof(int)));
    for(i=0;i<mid;i++) left[i] = arr[i];
    for(i=mid;i<len;i++) right[i-mid] = arr[i];
    merge_sort(left, mid); //recursion call do the left 1st
    merge_sort(right,len - mid); //recursion call back to the right
    merge(arr, left, right, mid, len-mid); //merge to sub-array
    free(left);
    free(right);
}

int main() {
FILE *fp;
    struct timeval start;
    struct timeval end;
    unsigned long time;
    fp = fopen("dataset1.txt","r");
    int arr[buf_size-1];
    char line[2048];
    int i=0;
    int tmp;
    while(fgets(line,2048,fp)) {
        tmp = atoi(line);
        arr[i] = tmp;
        i++;
    }
    gettimeofday(&start,NULL);
    merge_sort(arr, buf_size-1);
    gettimeofday(&end,NULL);
    time = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    for(i=0;i<buf_size;i++) printf("%d\n",arr[i]);
    fclose(fp);
    printf("Sorting performance (Merge) %ld us (equal %f sec)\n",time,time/100000.0);
}
