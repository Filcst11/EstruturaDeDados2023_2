#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<stdlib.h>

#define ARR_TAM 10

void geraArray(int arr[], int a){
    for (int i=0; i < a; i++){
        arr[i] = rand();
    }

}

void selectionSort(int *arr, int n, int trocas, int comparacoes){
    for (int i = 0; i < n-1 ; i++){
        int minIndex = i;

        //Encontra o índice do elemento de minimo na parte nn classificada
        for(int j = i+1 ; j < n ; j++){

            if(arr[j]<arr[minIndex]){
               minIndex = j;
               trocas +=3;
            } 
                       
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
        comparacoes++;

    }
    
}

int main(){
    struct timeval start_time, end_time;
    double time;
    int arr[ARR_TAM];
    geraArray(arr, ARR_TAM);
    int n = sizeof(arr) / sizeof(arr[0]);
    int comparacoes = 0, trocas = 0;
    
    
    gettimeofday(&start_time,NULL);

    selectionSort(arr, n, trocas, comparacoes);

    gettimeofday(&end_time,NULL);

    printf("Vetor ordenado:\n");
    for (int i = 0; i < n; i++){
        printf("%d\t",arr[i]);
    }
    
    time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec)/1000000.0;
    printf("tempo de execução: %f\nTrocas: %d\nComparações: %d\n",time,trocas,comparacoes);
    
    return 0;
}