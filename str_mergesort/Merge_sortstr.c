#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#define buf_size 100
#define line_cnt 1000000

char *lines[line_cnt];
char *tmp[line_cnt];
void merge(int start_left, int end_left, int start_right, int end_right, int size_left, int size_right) { //merge function
    int i,j,k;	
    int total = size_left + size_right;
    i = k = j = 0;
    while(i<size_left && j<size_right) {
   	if(strcmp(lines[start_left+i],lines[start_right+j])<0) {
   		strcpy(tmp[k],lines[start_left+i]);
   		k++;
   		i++;
   	}
   	else	{
   			strcpy(tmp[k],lines[start_right+j]);
   			k++;
   			j++;
   		}
    }
    while(i<size_left) {
    	strcpy(tmp[k],lines[start_left+i]);
    	k++;
    	i++;
    }
    while(j<size_right) {
    	strcpy(tmp[k],lines[start_right+j]);
    	k++;
    	j++;
    }
    for(i=0;i<total;i++) {
    	memset(lines[start_left+i], '\0', 101);
    	strcpy(lines[start_left+i],tmp[i]);
    	memset(tmp[i], '\0', 101);
    	}
}
void merge_sort(int start, int end, int size) { //split funcion 
    int mid, i;
    if(size<2) return; // lenght = 1, mean no more split.
    mid = size/2+start;
    merge_sort(start,mid-1,mid-start);//recursion call do the left 1st
    merge_sort(mid,end, end-mid+1);//recursion call back to the right
    merge(start, mid-1, mid, end, mid-start, end-mid+1);//merge to sub-array
}
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
    }
    for(i=0;i<cnt;i++) {
    	free(lines[i]);
    	free(tmp[i]);
    }
    fclose(fp);
    time = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("Sorting performance (Merge) %ld us (equal %f sec)\n", time, time / 1000000.0);
}
