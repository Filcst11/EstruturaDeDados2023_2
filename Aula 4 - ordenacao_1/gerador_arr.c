#include<stdio.h>
#include<stdlib.h>

#define ARR_TAM 10

void geraArray(int arr[], int a){
    for (int i=0; i < a; i++){
        arr[i] = rand();
    }

}
int main(){
    int arr[ARR_TAM];

    geraArray(arr, ARR_TAM);

    for(int i=0; i<ARR_TAM; i++)printf("%d\n",arr[i]);
}