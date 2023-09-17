#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int trocas = 0,comparacoes = 0;


//função para trocar o valor de a e b
void trocaValores(char a[],char b[]){
    char temp[25];
    

    strcpy(temp,a);
    strcpy(a,b);
    strcpy(b,temp);
    
}

//Função para particionar o vetor
int particao(char vetor[][25],int inf, int sup){
    
    char pivo[25];
    trocas+=1;
    strcpy(pivo,vetor[sup]);
    int i = inf-1, strcmpvalue;
    for(int j = inf; j <= sup - 1; j++){
        comparacoes+=1;
        strcmpvalue = strcmp(vetor[j],pivo);
        comparacoes+=1;
        if(strcmpvalue < 0){
            i++;
            trocas+=3;
            trocaValores(vetor[i], vetor[j]);
        }
    }
    trocaValores(vetor[i+1],vetor[sup]);
    return (i + 1);
}

//função para ordenar o vetor
void quickSort(char vetor[][25],int inf, int sup){
    comparacoes+=1;
    if(inf < sup){
        int P = particao(vetor, inf, sup);
        quickSort(vetor, inf, P - 1); 
        quickSort(vetor, P + 1, sup);
    }
}

int main(){
    setlocale(LC_ALL,"");
    

    //Tadando dando certo, falta arrumar o array para ficar igual ao do exercício

    char vetor[][25] = {"maca", "banana", "pera", "uva", "laranja", "abacaxi", "limão", "manga", "abacate", "kiwi", "cereja", "morango", "pêssego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"};

    int n = (sizeof(vetor)/sizeof(vetor[0]));


    printf("\nDesordenado: ");
    for(int i = 0; i < n; i++) printf("%s ",vetor[i]);
    printf("\n\n\n\n\n");
    quickSort(vetor, 0,(n-1));
    printf("Ordenado: ");
    for(int i = 0; i < n; i++) printf("%s ",vetor[i]);
    printf("\n\nTrocas: %d\nComparacoes: %d\nMediana: {%s} e {%s}",trocas,comparacoes,vetor[9],vetor[10]);
    
    
    //gerando arquivo de saida
    FILE *arquivosaida;
    arquivosaida = fopen("AruivoSaida.txt","w");
    fprintf(arquivosaida,"Lista ordenada:\n");
    for(int i = 0; i < n; i++) fprintf(arquivosaida,"%s ",vetor[i]);
    fclose(arquivosaida);
    
}
