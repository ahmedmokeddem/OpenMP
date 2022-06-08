#include <stdio.h>
#include <omp.h>
#define NUMBER 1000000
double prime_par(){
    omp_set_num_threads(8);
    int i ,j , val, total=0, N=NUMBER;
    double wtime = omp_get_wtime ();
    #pragma omp parallel private(i,j,val)
    {
        #pragma omp for reduction (+:total)
        for(i=2;i<=N;i++)
        {
            val=1;
            for(j=2;j<i;j++)
            {
                if(i%j == 0)
                {
                    val = 0;
                    break;
                }
            }
            total = total+val;
        }
    }
    printf("\nDone. total = %d \n",total);
    double temps=omp_get_wtime()-wtime;
    return temps;
}
double prime_seq(){
    int i ,j , val, total=0, N=NUMBER;
    double wtime = omp_get_wtime ( );
    for(i=2;i<=N;i++)
    {
        val=1;
        for(j=2;j<i;j++)
        {
            if(i%j == 0)
            {
                val = 0;
                break;
            }
        }
        total = total+val;
    }
    printf("\nDone. total = %d \n",total);
    double temps=omp_get_wtime()-wtime;
    return temps;
}
int main(){
    double seq=prime_seq();
    double par=prime_par();
    printf("\nTSeq=%14f et Tpar=%14f \n", seq, par);
    printf("\nAcceleration est egale à %f \n", seq/par);
}