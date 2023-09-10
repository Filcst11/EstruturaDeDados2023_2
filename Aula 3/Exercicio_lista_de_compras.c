#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *a1;
    int qtd,contador=0;
    float valor_total[100], valor_total_final = 0;
    char produto[50];
    float valor;


    a1 = fopen("lista.txt", "r");
    if (a1 == NULL){
        printf("Erro ao abrir o a1");
        exit(1);
    }
    
    while(fscanf(a1,"%s %i %f",produto, &qtd, &valor) != EOF){
        valor_total[contador] = qtd * valor;
        printf("%d)%s: %d * %.2f = %.2f\n",contador+1,produto,qtd,valor,(qtd*valor));
        contador+=1;
    }
    printf("\nO valor total da compra é:");
    for(int i=0; i < contador; i++){
        printf("+ %.2f ", valor_total[i]);
        valor_total_final += valor_total[i];
    }
    printf("= %.2f\n",valor_total_final);
    
    

    fclose(a1);
   
    return 0;
}    