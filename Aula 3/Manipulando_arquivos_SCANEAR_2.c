#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *arquivo;
    char linha[100];

    arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL){
        printf("ERROR");
        exit(1);
    }
    //Lendo e exibe cada linha do arquivo
    
    while(fgets(linha,sizeof(linha),arquivo) != NULL){
        printf("%s",linha);
    }
    fclose(arquivo);
    return 0;
}