#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
int main () {
    int x[4];
    x[0] = x[1] = x[2] = x[3] = 0;
    #pragma omp parallel num_threads(7)
    {
        int i;
        int t = omp_get_thread_num();
        #pragma omp for
        for (i = 0 ; i < 100 ; i++) x[t]++;
        if (t==3) printf("%d\n", x[t]);
    }
}