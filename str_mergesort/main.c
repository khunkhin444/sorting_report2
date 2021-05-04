#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define line_cnt 1000000

char *lines[line_cnt];
char *tmp[line_cnt];

int main() {
    FILE *fp;
    struct  timeval start;
    struct  timeval end;       
    unsigned  long time;
    fp = fopen("dataset2.txt","r");
    int i, cnt = 0;
    char line[buf_size+1];
    while(fgets(line,buf_size+2,fp)) {
        lines[cnt] = malloc(sizeof(char)*101);
        tmp[cnt] = malloc(sizeof(char)*101);
        strcpy(lines[cnt],line);
        cnt++;
    }
    int first = 0;
    int last = cnt - 1;
    gettimeofday(&start,NULL);
    merge_sort(first, last, line_cnt);
    gettimeofday(&end,NULL);
    for(i=0;i<line_cnt;i++) {
        printf("%s",lines[i]);
        free(lines[i]);
    	free(tmp[i]);
    }
    fclose(fp);
    time = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("Sorting performance (Merge) %ld us (equal %f sec)\n", time, time / 1000000.0);
}
