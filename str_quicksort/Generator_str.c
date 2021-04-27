#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define buf_size 1000000

void rand_str(char *dest, int size) {
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while (size > 0) {
        int index = (double) rand() / RAND_MAX * 52; //not including NULL 
        *dest++ = charset[index];
        size--;
    }
    *dest = '\0';
}

int main() {
    FILE* fp;
    fp = fopen("dataset2.txt", "w+");
    srand(time(0));
    char str[100];
    for(int i=0; i<1000000;i++) {
        rand_str(str, sizeof str);
        fprintf(fp, "%s\n",str);
    }
    fclose(fp);
}
