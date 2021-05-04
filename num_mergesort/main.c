#include <stdio.h>
#include <sys/time.h>
#include "sort.h"

#define buf_size 1000000

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
    merge_sort(arr, buf_size);
    gettimeofday(&end,NULL);
    time = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    for(i=0;i<buf_size;i++) printf("%d\n",arr[i]);
    fclose(fp);
    printf("Sorting performance (Merge) %ld us (equal %f sec)\n",time,time/100000.0);
}
