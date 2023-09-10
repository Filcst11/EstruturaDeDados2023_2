#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    //cria arquivo
    FILE *arquivo;
    //Abre arquivo
    arquivo = fopen("arquivo.txt","wb");
    if (arquivo == NULL){
        printf("Erroao abrir o arquivo\n");
        exit(1);
    }
    //Fecha arquivo
    fclose(arquivo);
    return 0;
}