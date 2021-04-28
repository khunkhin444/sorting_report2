#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
