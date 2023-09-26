#include <stdio.h>
#include <stdlib.h>
#include "fracao.h"

//Aprender a compilar esse arquivo e o fracao.h junto


int main(){
    
    Fracao f1 = criaFracao(1,2);
    mostraFracao(f1);
    Fracao f2 = criaFracao(40,50);
    mostraFracao(f2);
    f2 = simplificaFracao(f2);
    mostraFracao(f2);

    return 0;
}