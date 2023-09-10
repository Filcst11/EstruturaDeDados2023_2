#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *a1, *a2;
    int x;

    a1 = fopen("entrada.txt", "r");
    if (a1 == NULL){
        printf("Erro ao abrir o a1");
        exit(1);
    }
    a2 = fopen("saida.bin", "a");
    if (a2 == NULL){
        printf("Erro ao abrir o a2");
        exit(1);
    }

    fscanf(a1, "%d", &x);
    fprintf(a2, "\n%d", x);

    fclose(a1);
    fclose(a2);
    return 0;
}    