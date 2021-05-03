#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "sort.h"
#define buf_size 1000000
int main() {
    struct timeval start;
    struct timeval end;
    unsigned long time;
    int arr[buf_size];
    int i=0;
    int tmp;
    srand(time(NULL));
    for(i=0;i<1000000;i++) {
        arr[i]=rand();
    }
    gettimeofday(&start,NULL);
    quick_sort(arr, 0, buf_size-1);
    gettimeofday(&end,NULL);
    time = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    for(i=0;i<buf_size;i++) printf("%d\n",arr[i]);
    fclose(fp);
    printf("Sorting performance (Heap) %ld us (equal %f sec)\n",time,time/100000.0);
}
