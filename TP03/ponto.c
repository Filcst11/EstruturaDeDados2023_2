#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ponto.h"


//Exemplo de uso:
//poligono[1][1] = criaPonto(1.00,2.00);
//poligono[1][1] = 1.00,2.00

Ponto criaPonto(float x, float y){
    Ponto p;
    p.x = x;
    p.y = y;
    return p;
}

//Exemplo de uso:
//Ponto a; a.x=1; a.y=2
//mostraPonto(a);
//resultado: ponto(1.00,2.00)

void mostraPonto(Ponto p){
    printf("\nPonto(%.2f,%.2f)\n",p.x,p.y);
}

//Exemplo de uso:
//Ponto a; a.x=1; a.y=1
//Ponto b; a.x=2; a.y=2
//distancia = calculaDistancia(a,b);
//resultado: distancia = 1.41

float calculaDistancia(Ponto a, Ponto b){
    float distancia;
    distancia = sqrt(((b.x-a.x)*(b.x-a.x))+((b.y-a.y)*(b.y-a.y)));

}

//Exemplo de uso:
//Ponto a = criaPonto(1,2);
//Ponto b= criaPonto(3,8);
//Ponto c = criaPonto(5,1);
//float area = calculaAreaTriangulo(a,b,c);
//Resultado: area = 13

float calculaAreaTriangulo(Ponto a, Ponto b, Ponto c){
    float area, determinante;

    determinante = (a.x*b.y)+(a.y*c.x)+(b.x*c.y)-(c.x*b.y)-(c.y*a.x)-(b.x*a.y);


    if(determinante < 0){
        area = (-1*(determinante))/2;
    }else{
        area = determinante/2;
    }

    return area;
}

//Exemplo de aplicação:
//area = calculaAreaPoligono(poligono[0]);
//area = 5.00


float calculaAreaPoligono(Ponto vetor[]){
    
    int i=0,qtdPontos=0;
    float area=0;

    while(vetor[i].x != 847362 && vetor[i].y != 382764){
        qtdPontos++;
        i++;
    }
    
    //criar a qtd de triangulos = qtdPontos - 2
    //calcula as áreas e soma

    for(int i = 0; i < (qtdPontos-2); i++){
        area += calculaAreaTriangulo(vetor[0],vetor[i+1],vetor[i+2]);
    }

    return area;

}