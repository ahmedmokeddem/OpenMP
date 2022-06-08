#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
int main () {
    int nthreads, tid;
    /*Création d'une équipe de 4 threads avec leurs propres copies de variables*/
    //omp_set_num_threads(4);
    #pragma omp parallel private(nthreads,tid) num_threads(4)
    {
        /*Obtention du numéro de thread*/
        tid=omp_get_thread_num();
        printf("Hello world from thread = %d\n", tid);
        /*Seul le tread maître peut faire ça*/
        if (tid == 0) {
            nthreads=omp_get_num_threads();
            printf("Number of threads = %d\n", nthreads);
        }
    } /*Tous les threads se rejoignent ici*/
    return 0;
}