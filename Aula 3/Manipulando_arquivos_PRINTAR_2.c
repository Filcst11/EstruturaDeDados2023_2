#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *arquivo;
    arquivo = fopen("saida.txt", "a");
    if (arquivo == NULL){
        printf("ERROR");
        exit(1);
    }
    //Escrevendo uma string no arquivo

    const char *mensagem = "\nlinha 3";
    fputs(mensagem,arquivo);


    fclose(arquivo);
    return 0;
}