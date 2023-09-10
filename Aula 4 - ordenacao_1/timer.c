#include<stdio.h>
#include<time.h>

int main(){
    clock_t start_time, end_time;
    double time;

    start_time = clock();
    
    //seu código para ser testado

    end_time = clock();
    time = ((double)(end_time-start_time)/CLOCKS_PER_SEC);
    printf("tempo de execução: %f",time);

}