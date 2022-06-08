#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
int main () {
    int x[100];
    int i;
    #pragma omp parallel num_threads(7)
    {
        #pragma omp for schedule(dynamic,16)
        for (i = 0 ; i < 100 ; i++) printf("%d",i);
    }
    exit(0);
}