#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#define buf_size 100
#define line_cnt 1000000

char *lines[line_cnt];

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
int main() {
    FILE *fp;
    struct  timeval start;      
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
    quick_sort(lines, 0, line_cnt-1);
    gettimeofday(&end,NULL);
    for(int i=0;i<cnt;i++) {
        printf("%s",lines[i]);
        free(lines[i]);
    }
    fclose(fp);
    time = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;   
    printf("Sorting performance (Quick) %ld us (equal %f sec)\n", time, time / 1000000.0);
}
