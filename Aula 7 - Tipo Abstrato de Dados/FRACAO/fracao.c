#include <stdio.h>
#include <stdlib.h>
#include "fracao.h"


//Forma de utilização: 
//Fracao x = criaFracao(3,9);
//Cria a fracao 3/9 e atribui à x

Fracao criaFracao(int numerador, int denominador){
    Fracao f;
    f.numerador = numerador;
    f.denominador = denominador;
    return f;    
}

//Forma de utilização
//f = criaFracao(2,5);
//mostraFracao(fracao);
//no prompt: Fração f: 2/5

void mostraFracao(Fracao f){
    printf("\nFração: %d/%d\n\n",f.numerador,f.denominador);
}

//Forma de utilização:
//int x = mdc(40,20);
//x = 20

int mdc(int a, int b){
    while (b != 0){
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}


//forma de implementação:
//Fracao x = simplificaFracao(criaFracao(10,20));
//x = 1/2

Fracao simplificaFracao(Fracao f){
    int x = mdc(f.numerador,f.denominador);
    f.numerador = (f.numerador/x);
    f.denominador = (f.denominador/x);
    return f;    
}

//Forma de implementação:
//AB = somaFracao(criaFracao(1,2),criaFracao(2,4));
//AB = 1/1

Fracao somaFracao(Fracao a,Fracao b){
    Fracao soma;
    soma.denominador = a.denominador * b.denominador;
    soma.numerador = (a.numerador*b.denominador)+(b.numerador*a.denominador);
    soma = simplificaFracao(soma);
    return soma;

}

//Forma de implementação:
//Fracao AB = subtracaoFracao(criaFracao(4,5),criaFracao(2,3));
//AB = 2/15

Fracao subtraiFracao(Fracao a, Fracao b){
    Fracao subtracao;
    subtracao.denominador = a.denominador * b.denominador;
    subtracao.numerador = (a.numerador*b.denominador)-(b.numerador*a.denominador);
    subtracao = simplificaFracao(subtracao);
    return subtracao;
}

//Forma de implementação
//Fracao AB = multiplicaFracao(criaFracao(1,2),criaFracao(1,2));
//AB = 2/4

Fracao multiplicaFracao(Fracao a,Fracao b){
    Fracao multiplicacao;
    multiplicacao.numerador = a.numerador * b.numerador;
    multiplicacao.denominador = a.denominador * b.denominador;
    return multiplicacao;
}

//Forma de implementação
//Fracao AB = divideFracao(criaFracao(1,2),criaFracao(1,2));
//AB = 2/2

Fracao divideFracao(Fracao a, Fracao b){
    Fracao divisao;
    divisao.numerador = a.numerador * b.denominador;
    divisao.denominador = a.denominador * b.numerador;
    return divisao;
}

//Forma de implementação
//f = transformaDecimal(criaFuncao(1,2));
//f = 0,5

float transformaDecimal(Fracao f){
    float resultado;
    resultado = f.numerador/f.denominador;
    return resultado;

}