typedef struct{
    float x;
    float y;
} Ponto;

Ponto criaPonto(float x, float y);
void mostraPonto(Ponto p);
float calculaDistancia(Ponto a, Ponto b);
float calculaAreaTriangulo(Ponto a, Ponto b, Ponto c);
float calculaAreaPoligono(Ponto vetor[]);