#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
int main () {
    printf("Nombre de CPU = %d\n",omp_get_num_procs());
    printf ("Number of threads = %d\n",omp_get_max_threads());
    return 0;
}