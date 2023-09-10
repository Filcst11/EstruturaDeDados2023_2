#include<stdio.h>
#include<sys/time.h>

int main(){
    struct timeval start_time, end_time;
    double time;

    gettimeofday(&start_time,NULL);
    
    //seu código para ser testado

    gettimeofday(&end_time,NULL);
    time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec)/1000000.0;
    printf("tempo de execução: %f\n\n",time);

}