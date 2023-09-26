#ifndef FRACAO_H
#define FRACAO_H

typedef struct {
    int numerador;
    int denominador;
}Fracao;

Fracao criaFracao(int numerador, int denominador);
void mostraFracao(Fracao f);
int mdc(int a, int b);
Fracao simplificaFracao(Fracao f);
Fracao somaFracao(Fracao a,Fracao b);
Fracao subtraiFracao(Fracao a, Fracao b);
Fracao multiplicaFracao(Fracao a,Fracao b);
Fracao divideFracao(Fracao a, Fracao b);
float transformaDecimal(Fracao f);

#endif
