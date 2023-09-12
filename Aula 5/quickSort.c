#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


//função para trocar o valor de a e b
void trocaValores(int *a,int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Função para particionar o vetor
int particao(int vetor[],int inf, int sup){
    int pivo = vetor[sup];
    int i = inf-1;
    for(int j = inf; j <= sup - 1; j++){
        if(vetor[j] < pivo){
            i++;
            trocaValores(&vetor[i], &vetor[j]);
        }
    }
    trocaValores(&vetor[i+1],&vetor[sup]);
    return (i + 1);
}

//função para ordenar o vetor
void quickSort(int vetor[],int inf, int sup){
    if(inf < sup){
        int P = particao(vetor, inf, sup);
        quickSort(vetor, inf, P - 1);
        quickSort(vetor, P + 1, sup);
    }
}

int main(){
    int tamanho = 100000;
    int vetor[tamanho];

    for(int i = 0; i < tamanho; i++) vetor[i] = rand() % 10;

    int n = (sizeof(vetor)/sizeof(vetor[0]));


    printf("Desordenado: ");
    for(int i = 0; i < n; i++) printf("%d ",vetor[i]);
    printf("\n\n\n\n\n");
    quickSort(vetor, 0,n-1);
    printf("Ordenado: ");
    for(int i = 0; i < n; i++) printf("%d ",vetor[i]);
    
}
