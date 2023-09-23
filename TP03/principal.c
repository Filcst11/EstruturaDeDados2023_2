#include <stdio.h>
#include <locale.h>
#include "ponto.h"

#define QTD 10


int main(){
    //setlocale(LC_ALL,"Portuguese");
    
    //QTD representa a quantidade de poligonos e 50 é o limite de lados que o poligono tem.
    //Para determinar o fim de cada poligono eu vou usar criaPonto(847362,382764), então se tem 3 pontos, o poligono[x][3]=criaPonto(847362,382764)
    Ponto poligono[50];
    int qtdPontos=0;
    
    //recebe dados do arquivo
    FILE *arquivoEntrada;
    char linha[100];

    arquivoEntrada = fopen("./poligono.txt","r");

    if(arquivoEntrada == NULL){
        printf("\nErro ao abrir o arquivo\n");
        return 1;
    }
    printf("Abriu o arquivo\n");

    //recebe a qtd de pontos
    fscanf(arquivoEntrada, "%d", &qtdPontos);
    
    
    
    //cria os pontos/poligono

    for(int i = 0; i < qtdPontos; i++){
        fscanf(arquivoEntrada,"%f %f\n",&poligono[i].x, &poligono[i].y);
        poligono[i+1].x = 847362;
        poligono[i+1].y = 382764;
        
    }

    //Calcula a área dos poligonos
    
    float area;

    area = calculaAreaPoligono(poligono);

    printf("Area do poligono: %.2f\n\n",area);

    fclose(arquivoEntrada);
    
    return 0;
}