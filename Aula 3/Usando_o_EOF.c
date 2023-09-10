#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *a1;
    int x;
    int soma = 0;

    a1 = fopen("entrada.txt", "r");
    if (a1 == NULL){
        printf("Erro ao abrir o a1");
        exit(1);
    }
while(fscanf(a1, "%d", &x)!= EOF){
    printf("%d\n", x);
    soma += x;
} 
printf("O valor da soma é: %d\n",soma);
    
    fclose(a1);
    return 0;
}    