#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *fp;
    fp = fopen("dataset1.txt", "w+");
    srand(time(NULL));
    int i;
    for(i=0;i<1000000;i++) {
    fprintf(fp, "%d\n", rand());
    }
}
