#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *arquivo;
    int numero = 1109;
    char palavra[] = "Esta é a mensagem que será gravada no arquivo";

    arquivo = fopen("saida.txt", "w");
    if (arquivo == NULL){
        printf("ERROR");
        exit(1);
    }
    fprintf(arquivo, "Número: %d\nPalavra: %s\n", numero,palavra);
    fclose(arquivo);
    return 0;
}