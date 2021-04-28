#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#define buf_size 100
#define line_cnt 1000000
void merge(char **strings, char **left, char **right, int left_cnt, int right_cnt) { //merge function
    int i,j,k;
    i = k = j = 0;
    for(int tmp = 0; tmp< (right_cnt+left_cnt); tmp++) {
        strings[tmp] = malloc(sizeof(char)*101); //create memory of parent
    }
    //merge
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
void merge_sort(char **strings, int cnt) { //split funcion 
    int mid, i;
    // printf("check\n");
    if(cnt<2) return; // lenght = 1, mean no more split.
    mid = cnt/2;
    char *left[mid];
    char *right[cnt-mid];
    for(i = 0; i<mid;i++) {
        left[i] = malloc(sizeof(char)*101);
        strcpy(left[i],strings[i]);
        free(strings[i]); //free before get in another recursion	
    }
    for(i = mid; i<cnt;i++) {
        right[i-mid] = malloc(sizeof(char)*101);
        strcpy(right[i-mid],strings[i]);
        free(strings[i]); //free before get in another recursion
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

int main() {
    FILE *fp;
    struct  timeval start;
    char *lines[line_cnt];
    struct  timeval end;       
    unsigned  long time;
    fp = fopen("dataset2.txt","r");
    int cnt = 0;
    char line[buf_size+1];
    while(fgets(line,buf_size+2,fp)) {
        lines[cnt] = malloc(sizeof(char)*101);
        strcpy(lines[cnt],line);
        cnt++;
    }
    gettimeofday(&start,NULL);
    merge_sort(lines, line_cnt);
    gettimeofday(&end,NULL);
    for(int i=0;i<cnt;i++) {
        printf("%s",lines[i]);
    }
    fclose(fp);
    time = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;   
    printf("Sorting performance (Merge) %ld us (equal %f sec)\n", time, time / 1000000.0);
}
