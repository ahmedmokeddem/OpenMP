#include <stdio.h>
#include <omp.h>
int main() {
    int thread_id;
    omp_set_num_threads(5);
    #pragma omp parallel private(thread_id)
    {
        thread_id = omp_get_thread_num();
        printf( "Hello, World from thread %d!\n", thread_id );
    }
    return 0;
}