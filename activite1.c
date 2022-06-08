#include <stdio.h>
#include <omp.h>
int main () {
    int i, total=0, DIM=100;
    int a[DIM];
    #pragma omp parallel private(i)
    {
        int totalp;
        #pragma omp for
        for (i=0;i<DIM;i++) a[i]=i+3;

        #pragma omp for
        for (i=0;i<DIM;i++){
            a[i]=a[i]*a[i];
            totalp=totalp+a[i];
        }
        #pragma omp critical
        {
            total+=totalp;
        }

    } 
    printf("Done. total= %d\n",total);
    return 0;
}